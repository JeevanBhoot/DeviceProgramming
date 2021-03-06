# DeviceProgramming
C++ microcontroller programming for University of Cambridge 2nd Year Engineering (CUED IB) coursework.

Activity 1:
Microcontroller records a sequence of colours entered by the user, and then plays it back. Here is the approach:

1. The board starts by cycling the three LEDs, turning them on one at time, and switching every second:
        LED1 (green) for 1s –> LED2 (blue) for 1 sec –> LED3 (red) for 1s –> LED1 for 1 sec, etc.
2. While the colours are cycling, the user selects a colour by pressing the button. The colour that is ON at this time is recorded.
3. The process continues until N colours have been entered (the size of the sequence N is set in the code).
4. Once recording is completed, the recorded sequence is played back on the LEDs.

Activity 2:
Using an I2C tempearture sensor and micro-controller:

1. Record a temperature value every second in an array that will contain the last minute of data (older data is replaced by new data once the array is full).
2. If the temperature goes above a threshold value of 28 degree Celsius, the sensor triggers an interrupt that will get the LEDs on the microcontroller to flash an alarm signal, and transmit all the data available in the array to your computer by USB serial communication, so that the log may be analysed.
