# pic16f1779-test
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
