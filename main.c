/*
 * File:   main.c
 * Author: Admin
 *
 * Created on 30 juin 2016, 23:57
 */



// PIC16F1779 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

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
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit cannot be cleared once it is set by software)
#pragma config ZCD = OFF        // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR)
#pragma config PLLEN = ON       // Phase Lock Loop enable (4x PLL is always enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

int main()
{
    TRISA = 0x0; //these are likely RISC/MIPS instructions (35 of them in total)
    
    while (1)
    {
        _delay(25000);
        LATA = 0x6F; //Latch A --corresponds to a set of pins
        _delay(25000);
        LATA = 0x0C; //we set the hex value in binary and such
        _delay(25000);
        LATA = 0x5B;
        _delay(25000);
        LATA = 0x5D;
        _delay(25000);
        LATA = 0x3C;
        _delay(25000);
        LATA = 0x75;
        _delay(25000);
        LATA = 0x77;
        _delay(25000);
        LATA = 0x4C;
        _delay(25000);
        LATA = 0x7F;
        _delay(25000);
        LATA = 0x7D;
    }
    
    //Code for servo motor control
    //Principles are to use the delay to selectively give voltage to the motor, thus simulating a PWM (pulse width modulation)
    
    return 0;
}
