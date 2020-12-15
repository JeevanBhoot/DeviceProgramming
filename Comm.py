import serial
board = serial.Serial("COM3", 9600)
# This creates an object able to establish a serial communication channel
# with the board. The first parameter depends on your operating system
# and probably needs to be updated.
# The second is the baud rate. It needs to match the board's settings.

while True:
    line = board.readline()
    print(line)