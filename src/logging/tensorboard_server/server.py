"""
Contains a simple server class which will interoperate with tensorboard
"""
import logging

from torch.utils.tensorboard import SummaryWriter
from tensorboard_server.messages import LogConfirmation
from messaging.zmq_client import ZmqClient


class Server:
    """
    When `Server.serve()` is called, provides simple ZMQ based API for logging data to
    tensorboard.
    """

    def __init__(self, zmq_client: ZmqClient):
        self.zmq_client: ZmqClient = zmq_client
        # Currently not closing this after class is disposed (assumming long lived singleton)
        self.writer: SummaryWriter = SummaryWriter(log_dir="/workspaces/learn/build/logs")
        logging.info("Tensorboard server initialized")

    def serve(self):
        """
        Run the server.
        """
        logging.info("Serving")
        try:
            self.__serve()
        except KeyboardInterrupt:
            pass

    def _serve(self):
        while True:
            request = self.zmq_client.receive()
            method = request['method']
            param = request['param']

            if method == 'add_scalar':
                self.writer.add_scalar(param['tag'], param['scalar_value'], param['global_step'])
                self.writer.flush()
                self.zmq_client.send(LogConfirmation(True))

            elif method == 'add_image':
                self.writer.add_image(param['tag'], param['img_tensor'], param['global_step'])
                self.zmq_client.send(LogConfirmation(True))

    # Using name-mangling - should this stay (seems confusing and messy)?
    # (Just using same convention as in launch_gym_server)
    __serve = _serve
