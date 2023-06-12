/*
 * File:   newmain.c
 * Author: nemet
 *
 * Created on 2023. június 10., 13:18
 */

// PIC18F26K80 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config RETEN = OFF      // VREG Sleep Enable bit (Ultra low-power regulator is Disabled (Controlled by REGSLP bit))
#pragma config INTOSCSEL = HIGH // LF-INTOSC Low-power Enable bit (LF-INTOSC in High-power mode during Sleep)
#pragma config SOSCSEL = HIGH   // SOSC Power Selection and mode Configuration bits (High Power SOSC circuit selected)
#pragma config XINST = OFF      // Extended Instruction Set (Disabled)

// CONFIG1H
#pragma config FOSC = HS2       // Oscillator (HS oscillator (High power, 16 MHz - 25 MHz))
#pragma config PLLCFG = OFF     // PLL x4 Enable bit (Disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor (Disabled)
#pragma config IESO = OFF       // Internal External Oscillator Switch Over Mode (Disabled)

// CONFIG2L
#pragma config PWRTEN = OFF     // Power Up Timer (Disabled)
#pragma config BOREN = SBORDIS  // Brown Out Detect (Enabled in hardware, SBOREN disabled)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (1.8V)
#pragma config BORPWR = ZPBORMV // BORMV Power level (ZPBORMV instead of BORMV is selected)

// CONFIG2H
#pragma config WDTEN = SWDTDIS  // Watchdog Timer (WDT enabled in hardware; SWDTEN bit disabled)
#pragma config WDTPS = 1048576  // Watchdog Postscaler (1:1048576)

// CONFIG3H
#pragma config CANMX = PORTB    // ECAN Mux bit (ECAN TX and RX pins are located on RB2 and RB3, respectively)
#pragma config MSSPMSK = MSK7   // MSSP address masking (7 Bit address masking mode)
#pragma config MCLRE = ON       // Master Clear Enable (MCLR Enabled, RE3 Disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Overflow Reset (Enabled)
#pragma config BBSIZ = BB2K     // Boot Block Size (2K word Boot Block size)

// CONFIG5L
#pragma config CP0 = OFF        // Code Protect 00800-03FFF (Disabled)
#pragma config CP1 = OFF        // Code Protect 04000-07FFF (Disabled)
#pragma config CP2 = OFF        // Code Protect 08000-0BFFF (Disabled)
#pragma config CP3 = OFF        // Code Protect 0C000-0FFFF (Disabled)

// CONFIG5H
#pragma config CPB = OFF        // Code Protect Boot (Disabled)
#pragma config CPD = OFF        // Data EE Read Protect (Disabled)

// CONFIG6L
#pragma config WRT0 = OFF       // Table Write Protect 00800-03FFF (Disabled)
#pragma config WRT1 = OFF       // Table Write Protect 04000-07FFF (Disabled)
#pragma config WRT2 = OFF       // Table Write Protect 08000-0BFFF (Disabled)
#pragma config WRT3 = OFF       // Table Write Protect 0C000-0FFFF (Disabled)

// CONFIG6H
#pragma config WRTC = OFF       // Config. Write Protect (Disabled)
#pragma config WRTB = OFF       // Table Write Protect Boot (Disabled)
#pragma config WRTD = OFF       // Data EE Write Protect (Disabled)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protect 00800-03FFF (Disabled)
#pragma config EBTR1 = OFF      // Table Read Protect 04000-07FFF (Disabled)
#pragma config EBTR2 = OFF      // Table Read Protect 08000-0BFFF (Disabled)
#pragma config EBTR3 = OFF      // Table Read Protect 0C000-0FFFF (Disabled)

// CONFIG7H
#pragma config EBTRB = OFF      // Table Read Protect Boot (Disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>


#define _XTAL_FREQ 20000000
char own_add = 10;
 char own_add;
 char lst_add;
 char rcl_add;
 char can_add;
 char can_dat;
 char can_idat;
 char can_iedat;
 char can_ilen;
 char can_itxadd;
 char can_irxadd;
 char call_add;
 char t_cnt;			// table counter
 char tbl_add;			// table address
 char tbl_dat;			// table data

void main(void) {
    
    TRISCbits.TRISC3 = 0;
    TRISBbits.TRISB3 = 1;
    TRISBbits.TRISB2 = 0;
    TRISCbits.TRISC4 = 0;
 

    __delay_ms(2000);
    CANCON = 0x80;
    while (0x80 != (CANSTAT & 0xE0)); // wait until ECAN is in config mode
    
    ECANCON = 0x00;

    CIOCON = 0x01;

    RXM0EIDH = 0x00;
    RXM0EIDL = 0x00;
    RXM0SIDH = 0x00;
    RXM0SIDL = 0x00;
    RXM1EIDH = 0x00;
    RXM1EIDL = 0x00;
    RXM1SIDH = 0x00;
    RXM1SIDL = 0x00;
 
    /**
    Initialize Receive Filters
    */   
    RXF0EIDH = 0x00;
    RXF0EIDL = 0x00;
    RXF0SIDH = 0x00;
    RXF0SIDL = 0x00;
    RXF1EIDH = 0x00;
    RXF1EIDL = 0x00;
    RXF1SIDH = 0x00;
    RXF1SIDL = 0x00;
    RXF2EIDH = 0x00;
    RXF2EIDL = 0x00;
    RXF2SIDH = 0x00;
    RXF2SIDL = 0x00;
    RXF3EIDH = 0x00;
    RXF3EIDL = 0x00;
    RXF3SIDH = 0x00;
    RXF3SIDL = 0x00;
    RXF4EIDH = 0x00;
    RXF4EIDL = 0x00;
    RXF4SIDH = 0x00;
    RXF4SIDL = 0x00;
    RXF5EIDH = 0x00;
    RXF5EIDL = 0x00;
    RXF5SIDH = 0x00;
    RXF5SIDL = 0x00;


    BRGCON1 = 0x3F;
    BRGCON2 = 0xF1;
    BRGCON3 = 0x05;
    CIOCONbits.ENDRHI = 1;
    CIOCONbits.CLKSEL = 1;
    ECANCONbits.MDSEL = 0b00;
    CANCON = 0x00;
    while (0x00 != (CANSTAT & 0xE0)); // wait until ECAN is in Normal mode

    CANCONbits.REQOP = 0;
    while (0x00 != (CANSTAT & 0xE0)); // wait until ECAN is in Normal mode
    CANCON = 0b00001000;
    
    if (TXB0CONbits.TXREQ != 1) 
    {
        TXB0EIDH = 0x00;
    TXB0EIDL = 0x00;
    
    //0x35E    0110 1011 110
    TXB0SIDH = 0x0;
    TXB0SIDL = 0x0;
        TXB0DLC  = 5;
        TXB0D0   = 2;
        TXB0D1   = 0;
        TXB0D2   = 1;

        TXB0CONbits.TXREQ = 1; //Set the buffer to transmit		
        
    } 
    while(1)
    {
        LATCbits.LATC3 ^= 1;
        __delay_ms(10);
    }
    return;
}