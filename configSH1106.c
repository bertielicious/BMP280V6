/*#define SH1106_LCD_WIDTH  132
#define SH1106_LCD_HEIGHT  64
#define SH1106_WRITE_ADDRESS_COMMAND 0x78
#define SH1106_WRITE_ADDRESS_DISPLAY_DATA 0x7a
#define SH1106_READ_ADDRESS 0x79
#define SH1106_SET_LO_COLUMN_ADDR 0x00  // RANGE 0 - 15
#define SH1106_SET_HI_COLUMN_ADDR 0x10  // RANGE 16 - 31
#define SH1106_SET_PUMP_VOLTAGE 0x30 // 6.4V PUMP VOLTAGE
#define SH1106_SET_DISPLAY_START_LINE 0x40  // RANGE 0X40 - 0X7F  LINES 0 TO 63 / 0X00 - 0X3F
#define SH1106_SET_CONTRAST_CTRL_MODE_SET 0x81   //ENABLES THE CONTRAST DATA REGISTER SET
#define SH1106_SET_CONTRAST_DATA_REG_SET 0x80   //SETS THE CONTRAST OF THE DISPLAY FROM 0 - 255, POR VALUE IS 0X80
#define SH1106_SET_SEGMENT_REMAP 0xA0   // RANGE 0xA0 - 0xA1
#define SH1106_SET_ENTIRE_DISPLAY_ON 0xA5   //  0xA5 ON
#define SH1106_SET_ENTIRE_DISPLAY_OFF 0xA4   //  0xA4 OFF
#define SH1106_SET_NORMAL_REVERSE_DISPLAY 0xA6 // 0xA6 - 0xA7
#define SH1106_SET_DISPLAY_ON 0XAF      // 0xAF ON
#define SH1106_SET_DISPLAY_OFF 0XAE      // 0xAE OFF 
#define SH1106_SET_PAGE_ADDRESS 0xB0        // PAGE ADDRESS RANGES FROM 0xB0 TO 0xB7*/

/*CONTROL BYTE SA0 IS CONNECTED TO 0V IN HARDWARE SO ALWAYS READ AS A 0
#define COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW 0x00                         //C0 = 0   D/C = 0 HAPPY XMAS! 24/12/21
//#define COMMAND_NEXT_TWO_BYTES_ARE_A_CTRL_BYTE_AND_A_DATA_BYTE 0x80                  //CO = 1   D/C = 0
#define DISPLAY_DATA_ONE_CTRL_BYTE_DATA_BYTES_TO_FOLLOW 0X40                         //C0 = 0   D/C = 1
//#define DISPLAY_DATA_NEXT_TWO_BYTES_ARE_A_CTRL_BYTE_AND_A_DATA_BYTE 0xCO             //CO = 1   D/C = 1*/


#include "config.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cStop.h"
#include "oLedWrite.h"
#include "clearSH1106.h"
void configSH1106(void)
{
   oLedWrite(0x78, 0x00, 0xae); /* display OFF */
  // oLedWrite(0x78, 0x00, 0xB0); /*set page 0*/
  // oLedWrite(0x78, 0x00, 0xd5); /* divide ratio/osc freq mode set */
 //  oLedWrite(0x78, 0x00, 0x80); /* +15% increase in osc freq */
  // oLedWrite(0x78, 0x00, 0xa8); /* multiplex ratio mode set */
 //  oLedWrite(0x78, 0x00, 0x1f); /* multiplex ratio data set */
   oLedWrite(0x78, 0x00, 0xd3); /* display offset mode set */
   oLedWrite(0x78, 0x00, 0x00); /* display offset data set */
   oLedWrite(0x78, 0x00, 0x40); /* set display start line at line address 0 page 20*/
   oLedWrite(0x78, 0x00, 0xad); /* set dc-dc converter control ON */
   oLedWrite(0x78, 0x00, 0x8b); /* dc-dc mode is ON */
   oLedWrite(0x78, 0x00, 0x33); /* charge pump voltage 9V* page 19*/
   oLedWrite(0x78, 0x00, 0xa1); /* segment re-map */
   oLedWrite(0x78, 0x00, 0xc8); /* scan direction normal */
   oLedWrite(0x78, 0x00, 0xda); /* com pin HW configured */
   oLedWrite(0x78, 0x00, 0x12); /*  */
   oLedWrite(0x78, 0x00, 0x91); /* set contrast control page 20 */
   oLedWrite(0x78, 0x00, 0x80); /* set contrast page 20*/
   oLedWrite(0x78, 0x00, 0xd9); /* set discharge and pre-period data set */
   oLedWrite(0x78, 0x00, 0x22); /* VCOM deselect level mode */
   oLedWrite(0x78, 0x00, 0x28); /* VCOM deselect level data */
   oLedWrite(0x78, 0x00, 0xa4); /* Output RAM to display */
   oLedWrite(0x78, 0x00, 0xa6); /* Normal display = 0xa6, reverse display = a7 */
   oLedWrite(0x78, 0x00, 0x81); /*Enable contrast mode*/
   oLedWrite(0x78, 0x00, 0x00); /*Contrast min = 0x00, contrast max = 0xff, default = 0x80*/
   oLedWrite(0x78, 0x00, 0xaf); /* display ON */
   
}

/*column address p19
 set Pump voltage p19
 set display start line p20
 set contrast control p20
 set segment re-map p21
 set entire display on/off p21
 set normal/ reverse display p21
 set multiplex ratio p 22
 set dc-dc off/on p22
 set display off/on p23
 set page address p23
 set common output scan direction p 24
 set Display offset p 24*/