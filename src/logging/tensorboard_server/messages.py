"""
Classes for building requests to send to pytorch-cpp-rl.
"""
from abc import ABC, abstractmethod
import numpy as np
import msgpack


class Message(ABC):
    """
    Base class for messages.
    """
    @abstractmethod
    def to_msg(self) -> bytes:
        """
        Creates the JSON for the request.
        """


class LogConfirmation(Message):
    """
    Builds the JSON for returning the result of a log() action.
    """

    def __init__(self, success):
        self.success = success


    def to_msg(self) -> bytes:
        request = {
            "success": self.success
        }
        return msgpack.packb(request)
