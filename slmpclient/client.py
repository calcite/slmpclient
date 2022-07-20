"""
File client.py obtains all communication necessities in class SLMPClient.
User needs to know IP address and port of target (e.g. Mitsubishi robotic arm) and choose whether to use
TCP or UDP communication protocol.
"""
import socket
import logging
from .util import Error, WrongIpAddress, ClientOpenErr


class SLMPClient(object):
    def __init__(self, ip_addr=None, port=None, tcp=1):
        """
        Initialize SLMP client.
        :param ip_addr: target IP address.
        :param port: target port.
        :param tcp: tcp=1/udp=0.
        """
        self._ip_addr = ip_addr
        self._port = port
        self._tcp = tcp
        self._socket = None
        self._response = None
        self.logger = logging.getLogger(__name__)
        try:
            socket.inet_aton(ip_addr)       # Check whether IP address is valid
        except socket.error:
            self.logger.warning("IP_ADDR: {} PORT: {},  IP_ADDR is not valid".format(self._ip_addr, self._port))
            raise WrongIpAddress

    def open(self):
        """
        Create socket.
        If TCP protocol is used, socket is connected to server.
        """
        try:
            if self._tcp==1:     # When TCP protocol is used
                self._socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                self._socket.connect((self._ip_addr, self._port))
                self.logger.info("socket opened TCP IP_ADDR: {}  PORT: {}".format(self._ip_addr, self._port))
            else:       # When UDP protocol is used
                self._socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                self.logger.info("socket opened UDP IP_ADDR: {}  PORT: {}".format(self._ip_addr, self._port))
        except socket.error:
            self.logger.warning("ERR: socket cant be opened IP_ADDR: {}  PORT: {}".format(self._ip_addr, self._port))
            raise ClientOpenErr

    def close(self):
        """
        Close SLMP communication.
        """
        try:
            self._socket.close()
            self.logger.info("socket closed IP_ADDR: {}  PORT: {}".format(self._ip_addr, self._port))
        except socket.error:
            self.logger.warning("ERR: socket cant be closed IP_ADDR: {}  PORT: {}".format(self._ip_addr, self._port))

    def send(self, packet):
        """
        Send SLMP packet to target.
        :param packet: packet created with C function SLMP_MakePacketStream.
        """
        try:
            if self._tcp==1:     # When TCP protocol is used
                self._socket.sendall(packet)
                self.logger.info("sent TCP IP_ADDR: {}  PORT: {}".format(self._ip_addr, self._port))
            else:       # When UDP protocol is used
                self._socket.sendto(packet, (self._ip_addr, self._port))
                self.logger.info("sent UDP IP_ADDR: {}  PORT: {}".format(self._ip_addr, self._port))
        except socket.error:
            self.logger.warning("ERR: sent IP_ADDR: {}  PORT: {}".format(self._ip_addr, self._port))

    def receive(self):
        """
        Receive response packet from SLMP server.
        """
        try:
            # Receive at most 512 bytes of data
            self._response = self._socket.recv(512)   # TODO 18000 was before
            if self._tcp==1:
                self.logger.info("recv TCP IP_ADDR: {}  PORT: {}".format(self._ip_addr, self._port))
            else:
                self.logger.info("recv UDP IP_ADDR: {}  PORT: {}".format(self._ip_addr, self._port))
            return self._response
        except socket.error:
            self.logger.warning("ERR: recv IP_ADDR: {}  PORT: {}".format(self._ip_addr, self._port))

    def get_response(self):
        """
        Response data getter.
        :return: response
        """
        return self._response
