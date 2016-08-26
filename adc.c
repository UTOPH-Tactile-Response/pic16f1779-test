/*
 * File:   main.c
 * Author: Admin
 *
 * Created on 30 juillet 2016, 23:57
 */

//This code oscillates the servo from 120 back to 180

// PIC16F1779 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 32000000 // Set frequency of 32 MHz

// CONFIG1
#pragma config FOSC = ECH       // Oscillator Selection Bits (ECH, External Clock, High Power Mode (4-20 MHz): device clock supplied to CLKIN pins)
#pragma config WDTE = ON        // Watchdog Timer Enable (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PPS1WAY = OFF    // Peripheral Pin Select one-way control (The PPSLOCK bit cannot be cleared once it is set by software)
#pragma config ZCD = OFF        // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR)
#pragma config PLLEN = ON       // Phase Lock Loop enable (4x PLL is always enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)


int getMode()
{

    int result;     //variable to store our ADC result

    TRISA = 0xFF;   //set all digital I/O to inputs (except the pin controlling the servo)
    TRISB = 0xFF;
    TRISC = 0xFF;
    TRISD = 0xFF; 
    
    WPUD = 0; //disable weak pull ups on the analog pins
    
    ANSELD = 0xFF; //set D pins to be analog (analog select)
        
    //ADCON0 means the 0th ADC control register
    ADCON0bits.CHS = 0b010101; //this will select which channel i.e. port to read from
    ADCON0bits.ADON = 1; //enable the ADC
    
    //ADCON1 means the 1st ADC control register
    ADCON1bits.ADFM = 1; //this right justifies
    ADCON1bits.ADCS = 0b111; //set the clock
    ADCON1bits.ADNREF = 0; //set the reference
    
    __delay_ms(2); //acquisition time
    
    ADCON0bits.GO = 1; //this starts the conversion and also tells us when it succeeded (poll it)
    
    while (ADCON0bits.GO);//as long as high, conversion is still going
    
    //now we can read the result!
    int val = ADRESL;
    int mode;
    if (val>50) //set it to very low just for testing
    {
        
        mode = 1;
    }
    else
    {
        mode = 0;
    }
    return mode;
}

int main()
{
    int mode = getMode();
    if (mode == 1)
    {
        TRISA = 0x0;
        OSCCON = 0b01111000; // 32 MHz
        int i = 0;
        
        while (i < 10)
        {
            LATA = 0xFF;
            __delay_ms(1); //sets it to the middle roughly(around 120)
            LATA = 0x00;
            __delay_ms(20);
            i++;
        }
        

        i = 0;
        

        while (i < 10)
        {
            LATA = 0xFF;
            __delay_ms(1.5); //sets it to 180 
            LATA = 0x00;
            __delay_ms(20);
            i++;
        }
    }
    return 0;
}