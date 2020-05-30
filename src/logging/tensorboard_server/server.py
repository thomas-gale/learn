"""
Contains a simple server class which will interoperate with tensorboard
"""
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
        self.env: gym.Env = None
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
                # Add the scalar to tensorboard
                self.zmq_client.send(LogConfirmation(True))

            elif method == 'add_image':
                # Add the image to tensorboard
                self.zmq_client.send(LogConfirmation(True))
