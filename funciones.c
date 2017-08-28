#include "funciones.h"
#include "lcd.h"

void mcu_init(void) 
{
    
    INTCON =0X00;
    TRISD = 0x00;
    TRISE = 0x00;
    RW1=0;
    ADCON1bits.PCFG=0b1111;
    Lcd_Init();
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    TRISA = TRISB = TRISC = TRISD = 0;
    //        PIE1bits.RCIE=1;
    //Inicialización del MCU
    int i = 0;
    __delay_ms(40);
    OSCCONbits.IRCF = 0b111; // Oscilador Interno a 8 Mhz
    //        OSCTUNEbits.PLLEN = 1; // PLL Activado (8 Mhz x 4 = 32 Mhz)_
    //        __delay_ms(40);
    //        ODCON2bits.U2OD = 1; // Activa Open Drain en USART2
    //        TRISGbits.TRISG1 = 0; // USART2 TX
    TRISA = 0;
    PORTA = 0;
    TRISCbits.TRISC7 = 1;
    TRISCbits.TRISC6 = 0;
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB3 = 1;
    TRISBbits.TRISB4 = 1;
    for (i = 1; i <= 50; i++)
      __delay_ms(20);
    PORTE = 0;
    PORTB = 0;
    Lcd_Clear();
    Lcd_Set_Cursor(1, 1);
    Lcd_Write_String("INICIO");
  
}

void RobotControl(void)
{
    int sensed=0;
    sensed = getCNY70Value();
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_Integer(sensed);
    Lcd_Set_Cursor(2,1);
    switch ( sensed) {
           case 0 :     
               
               Lcd_Write_String("Go ahead");
               break;
            case 1 :
              
               Lcd_Write_String("Left");
               break;
            case 2 :
               
               Lcd_Write_String("More Left"); 
               break;
            case -1 :
              
               Lcd_Write_String("Right");
               break;
            case -2 :
              
               Lcd_Write_String("More Right");
               break;
            default:   
               
               Lcd_Write_String("Go ahead");
               break;
    }

  
}

