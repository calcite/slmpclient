# SLMPCLIENT
Package slmpclient provides the SLMPClient class for communication via TCP/UDP, and also provides the SLMPPacket class, which uses the original SLMP protocol library written in the C language for creating packets.

### 1. Example
Using the SELF_TEST command to verify the correctness of communication between the client and the server:
```python
import time
from slmpclient import util
from slmpclient import SLMPClient
from slmpclient import SLMPPacket
from slmpclient import FrameType, ProcessorNumber, TimerValue, SLMPCommand, SLMPSubCommand


def main():
    pucData = b'\x05\x00\x0a\x0b\x0c\x0d\x0c'  # Send 'ABCDE'(0x0A, 0x0B, 0x0C, 0x0D, 0x0E) data length of 5 (0x0005)
    slmp_controller = SLMPPacket(ulFrameType=FrameType.SLMP_FTYPE_BIN_REQ_ST.value,
                                 usNodeNumber=0xFF,
                                 usNetNumber=0,
                                 usProcNumber=ProcessorNumber.SLMP_CPU_1.value,
                                 usTimer=TimerValue.SLMP_TIMER_WAIT_FOREVER.value,
                                 usCommand=SLMPCommand.SLMP_COMMAND_SELF_TEST.value,
                                 usSubCommand=SLMPSubCommand.SUB_word0.value,
                                 pucData=pucData)
    
    packet = slmp_controller.create_stream()
    
    # SLMP socket connection
    client = SLMPClient(ip_addr="192.168.10.201", port=4050, tcp_flag=True)
    client.open()
    print("1. Connection opened.")

    client.send(packet)
    print("2. Packet send.")
    response = client.receive()
    print("3. Response received.")
    print(response)

    time.sleep(1)
    client.close()
    print("Connection closed.")
    exit(0)
    

if __name__ == '__main__':
    main()
```

### 2. Example
The following example shows reading the values of registers M32 to M38:
```python
import time
import struct
from slmpclient import util
from slmpclient import SLMPClient
from slmpclient import SLMPPacket
from slmpclient import FrameType, ProcessorNumber, TimerValue, SLMPCommand, SLMPSubCommand

IP_ADDR = '127.0.0.1'
PORT = 4050


def read_d_reg():
    # Creates and returns packet ready to send.
    # Packet contains device read command from D(word) register of specific device number.
    # :return: packet
    
    pucData = b'\xAC\x12\x00\xA8\x1C\x00'  # Reading will start from register D4780, and takes 28 words
    slmp_controller = SLMPPacket(ulFrameType=FrameType.SLMP_FTYPE_BIN_REQ_ST.value, usNetNumber=0, usNodeNumber=0xFF,
                                 usProcNumber=ProcessorNumber.SLMP_CPU_DEFAULT.value,
                                 usTimer=TimerValue.SLMP_TIMER_WAIT_FOREVER.value,
                                 usCommand=SLMPCommand.SLMP_COMMAND_DEVICE_READ.value,
                                 usSubCommand=SLMPSubCommand.SUB_word0.value, pucData=pucData)
    packet = slmp_controller.create_stream()
    
    return packet


def parse_response(response, print_flag=False):
    # Parse specific response, received on request from this file.
    # Returns list of data [m32, m33, m34, m35, m37, m38]
    # :param response: response
    # :param print_flag: True/False
    # :return: [data]
    
    end_code = response[8:10]
    if end_code != b'\x00\x00' or len(response) < 67:
        print("parse ERR") #TODO log
        raise util.UnwantedResponse

    response_data_part = response[11:67]
    data = struct.unpack('<ddddddd', response_data_part)

    if print_flag is True:
        print("M32          : ", data[0])
        print("M33          : ", data[1])
        print("M34          : ", data[2])
        print("M35          : ", data[3])
        print("M37          : ", data[5])
        print("M38          : ", data[6])
        print("")

    return [data[0], data[1], data[2], data[3], data[5], data[6]]


def main():
    # Main program.
    # Creates SLMP TCP connection and periodically send requests to server.
    # Response supposed to hove 6 values from registers m38=D4780, m37=D4784, m35=D4792, m34=D4796, m33=D4800, m32=D4804.
    
    request = read_d_reg()
    client = SLMPClient(ip_addr=IP_ADDR, port=PORT, protocol=True)
    client.open()

    while True:
        client.send(request)
        response = client.receive()
        data = parse_response(response, print_flag=True)
        time.sleep(0.1)


if __name__ == "__main__":
    main()
```