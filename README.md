# pic16f1779-test

## Aug 25 update
Finally got the potentiometer and servo working together! Currently the potentiometer works as a binary switch: when we move the knob on the potentiometer all the way to one side, it skips the code Andrew posted. Else, it runs the code that Andrew did. 

For next week, we should consider hooking up a serial communication with the computer from the PIC.
We also need to consider how the servo will respond to different levels of the potentiometer. It probably can't be binary like now!

Far future: working in unity and C# to integrate the serial data received from the pic into unity
https://unity3d.com/learn/tutorials/topics/scripting/coding-unity-absolute-beginner

## Aug 18
One issue is that we need to configure the servo to respond to different levels of the 
next level help: http://www.microchip.com/forums/m839336.aspx
ADCON0 is 490
http://www.circuitsgallery.com/2013/09/analog-digital-converter-using-pic2.html
adc pic microcontroller
http://extremeelectronics.co.in/microchip-pic-tutorials/using-adc-of-pic-microcontroller/
http://www.microcontrollerboard.com/analog-to-digital-converter.html
http://picguides.com/beginner/adc.php

## August 11 update
Currently trying to figure out how to read the data from the pins on the pic. There is no equivalent to Arduino's simple read(). The pic programming cable is NOT a serial cable thing, we cannot use it to get data from the pic like that. Instead, we need something to set up UART or another cable for serial communications.

http://www.microchip.com/forums/m754681.aspx

We might need something like this: http://www.mikroe.com/add-on-boards/communication/usb-uart2/

Also, it seems we can't printf() here for similar reasons (at least not in the sense that we would like--since we can't read values in that fashion). printf generally does not print to the regular stdout (terminal) under this programming paradigm
RS232

Ground and vbus
Brown is ground
Red is 5V,
and yellow is signal

Plan for next week: Add wires to make the serial connection over the PicKit cable

Reading:
http://groups.csail.mit.edu/lbr/stack/pic/pic-microcontrollers.pdf
https://electrosome.com/uart-pic-microcontroller-mplab-xc8/


A new hardware approach 
## *Reasons for change*
* The Arduino does not have enough PWM pins, which we will need to control the servo motors in the multi-jointed hand
* We're not really using the processing power of the Arduino
* The pic microcontroller is much cheaper ($3 vs $50)


# Setup Instructions
* Download MPLab X IDE
* Download xc8 (C compiler) 

Pretty much just check out this guide:
http://ww1.microchip.com/downloads/en/DeviceDoc/50002173A.pdf

## Hardware
The new pic chip is *not* USB-powered. Thus, you will need an external power source (like a 9V) to power it.

(But make sure not to fry it--Andrew used a reg to adjust the voltage)

In terms of how we actually get the program onto the board, we  use a Pickit 3 (which *is* USB-interfacing) which attaches to the pins of the smaller microcontroller.   


Possibly useful link: http://www.circuitstoday.com/pic-tutorial-16f877

Pin layout: http://ww1.microchip.com/downloads/en/DeviceDoc/40001819A.pdf

# Hardware Layout
Middle wire should go to big terminal and small wire should go to little terminal.
(the wire that is connected to the ground should go to the big terminal)

Black middle red right
