/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

//LEDs
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);

//Button interrupt
InterruptIn button(USER_BUTTON);

//Timeout for debounce
Timeout button_debounce_timeout; 
float debounce_time_interval = 0.3;

//Ticker for cycling LEDs
Ticker cycle_ticker;
float cycle_time_interval = 1.0;

//Global values
int t=0;
int t2=0;
int n=0;
int arr[5];

//Create onButtonStopDebouncing so that it can be used in onButtonPress
void onButtonStopDebouncing(void);

//Interrupt on button press
void onButtonPress(void)
{
        arr[n] = t;
        n += 1;
        button.rise(NULL);
        button_debounce_timeout.attach(onButtonStopDebouncing, debounce_time_interval);

}

//Completing function onButtonStopDebouncing after onButtonPress has been written
void onButtonStopDebouncing(void)
{
        button.rise(onButtonPress);
}

//Select LED
void select_led(int l)
{
        if (l==1) {
                led1 = true;
                led2 = false;
                led3 = false;
        }
        else if (l==2) {
                led1 = false;
                led2 = true;
                led3 = false;
        }
        else if (l==3) {
                led1 = false;
                led2 = false;
                led3 = true;
        }
}

//Cycle LEDs
void onCycleTicker(void)
{
        select_led(t); //Select LED
        t=(t%3)+1; //Increment value of t - staying in range 1 to 3
}


//Cycle LEDs in recorded pattern
void onCycleTickerPattern(void)
{
        select_led(arr[t]); //Select LED
        t2=(t2+1)%5; //Increment value of t - staying in range 1 to 3
}

//Main functionality - LEDs cycling
int main()
{  
    button.rise(onButtonPress); //Checking interrupt
    while (true) {
        while (n < 5) { //When the number of interrupts equals 5 (or above), the code switches over to cycling through the user's sequence, otherwise it follows the normal cycle and awaits interrupts.
            select_led(t); 
            wait(1);
            t=(t%3)+1;
        }
        select_led(arr[t2]);
        wait(1);
        t2=(t2+1)%5;
    }
}