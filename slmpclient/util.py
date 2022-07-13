"""
File util.py contains all custom exceptions for every situation.
"""


class Error(Exception):
    """Base Error class"""
    pass


class WrongIpAddress(Error):
    """Wrong format of target IP address"""
    pass


class ClientOpenErr(Error):
    """Can not execute SLMPClient.open method"""
    pass


class ClibImportErr(Error):
    """Can not import and use ctypes on SLMP.c, SLMP.h"""
    pass


class ClibPacketErr(Error):
    """Can not create SLMPInfoC packet"""
    pass


class UnwantedResponse(Error):
    """Response has either ErrCode not zero or is too short"""
    pass
