* File: main.c
* Author: Trent
*
* Created on May 19, 2015, 6:47 PM
*/

#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)

void interrupt isrRoutine(void);
void interrupt isrRoutine(void){
if(TMR0IE && TMR0IF){
RB4 = 1;
RB4 = 0;
TMR0IF = 0;
}
//GIE = 1; //RE EMABLE GLOBAL INTERRUPT
TMR0 = 0xFF; 
//counter++;
}
#include <xc.h>
void main(void) {
T0CS = 0; 
PSA = 1; // This assigns the pre Scaler to the WDT
PS2 = 0; //prescaler of 1:1
PS1 = 0; //prescaler of 1:1
PS0 = 0; //prescaler of 1:1
//END SEQUENCE
TMR0 = 240;
TMR0IE = 1; //enable timer0 interrupts
TMR0IF = 0; //reset the timer 0 interrupt flag
GIE = 1; // if not enabled. enable global interrupts
TRISB4 = 0;
while(1){
}
}