#!/usr/bin/env python
"""
learn - Tensorboard server.
"""

from tensorboard_server.server import Server
from tensorboard_server.zmq_client import ZmqClient


def main():
    """
    Host the server.
    """
    # If anything is logged during imports, it messes up our logging so we
    # reset the logging module here
    root_logger = logging.getLogger()
    if root_logger.handlers:
        for handler in root_logger.handlers:
            root_logger.removeHandler(handler)
    logging.basicConfig(level=logging.DEBUG,
                        format=('%(asctime)s %(funcName)s '
                                '[%(levelname)s]: %(message)s'),
                        datefmt='%Y%m%d %H:%M:%S')
    logging.info("Initializing tensorboard server")

    zmq_client = ZmqClient(10201)
    logging.info("Connecting to client")
    zmq_client.send("Connection established")
    logging.info("Connected")
    server = Server(zmq_client)

    try:
        server.serve()
    except:  # pylint: disable=bare-except
        import pdb
        pdb.post_mortem()


if __name__ == '__main__':
    main()
