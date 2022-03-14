/* 
 * File:   config.h
 * Author: User
 *
 * Created on 06 December 2021, 14:08
 *           ___________
 *          |           |
 *          |           |
 *          |           |
 *              
 */

#ifndef CONFIG_H
#define	CONFIG_H

void config(void);



#include <xc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
enum {LO, HI};
typedef unsigned char uchar;
uint8_t state = 1;

typedef struct
{
   uint32_t digT1;
   int32_t digT2;
   int32_t digT3;
}caliTemp;

typedef struct
{
    uint8_t tensThousands;
    uint8_t thousands;
    uint8_t hundreds;
    uint8_t tens;
    uint8_t units;
}splitData;        // new data type declared splitData

typedef struct{
    uint8_t zoomedByte0;    // page 0 zoomed byte
    uint8_t zoomedByte1;    // page 1 zoomed byte
    uint8_t zoomedByte2;    // page 2 zoomed byte
    uint8_t zoomedByte3;    // page 3 zoomed byte
}zoomPix;

#define UP PORTAbits.RA4    // UP button pin 3
#define DOWN PORTAbits.RA5    // DOWN button pin 2
#define ENT PORTBbits.RB5    // ENT button pin 12

#define SDA PORTBbits.RB4   // i2c serial data pin
#define SCL PORTBbits.RB6   // i2c serial clock pin
#define _XTAL_FREQ 16000000
#define  DIAGNOSTIC_LED LATCbits.LATC7   // RC7 pin 9 is connected to DIAGNOSTIC_LED

#define SH1106_LCD_WIDTH  132
#define SH1106_LCD_HEIGHT  64
#define SH1106_WRITE_ADDRESS_COMMAND 0x78
#define SH1106_READ_ADDRESS 0x79
#define SH1106_SET_LO_COLUMN_ADDR 0x00  // RANGE 0 - 15
#define SH1106_SET_HI_COLUMN_ADDR 0x10  // RANGE 16 - 31
#define SH1106_SET_PUMP_VOLTAGE 0x33 // 9V PUMP VOLTAGE
#define SH1106_SET_DISPLAY_START_LINE 0x40  // RANGE 0X40 - 0X7F  LINES 0 TO 63 / 0X00 - 0X3F
#define SH1106_SET_CONTRAST_CTRL_MODE_SET 0x81   //ENABLES THE CONTRAST DATA REGISTER SET
#define SH1106_SET_CONTRAST_DATA_REG_SET 0x80   //SETS THE CONTRAST OF THE DISPLAY FROM 0 - 255, POR VALUE IS 0X80
#define SH1106_SET_SEGMENT_REMAP 0xA1   // RANGE 0xA0 - 0xA1 (A0 = seg0 on LHS)
#define SH1106_SET_ENTIRE_DISPLAY_ON 0xA5   //  0xA5 ON
#define SH1106_SET_ENTIRE_DISPLAY_OFF 0xA4   //  0xA4 OFF
#define SH1106_SET_NORMAL_REVERSE_DISPLAY 0xA6 // 0xA6 - 0xA7
#define SH1106_SET_DISPLAY_ON 0XAF      // 0xAF ON
#define SH1106_SET_DISPLAY_OFF 0XAE      // 0xAE OFF 
#define SH1106_SET_PAGE_ADDRESS 0xB0        // PAGE ADDRESS RANGES FROM 0xB0 TO 0xB7
#define SH1106_SET_DISPLAY_CLK_DIV 0xd5
#define SH1106_SETOSC_FREQ 0x80






/*CONTROL BYTE*/
#define COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW 0x00                         //C0 = 0   D/C = 0 HAPPY XMAS! 24/12/21
#define COMMAND_NEXT_TWO_BYTES_ARE_A_CTRL_BYTE_AND_A_DATA_BYTE 0x80                  //CO = 1   D/C = 0
#define DISPLAY_DATA_ONE_CTRL_BYTE_DATA_BYTES_TO_FOLLOW 0X40                         //C0 = 0   D/C = 1
#define DISPLAY_DATA_NEXT_TWO_BYTES_ARE_A_CTRL_BYTE_AND_A_DATA_BYTE 0xCO             //CO = 1   D/C = 1
#endif	/* CONFIG_H */

const uchar hello[] = {0xff, 0x10, 0x10, 0x10, 0xff, 0x00,   0x00, 0x00, 0xff, 0x89, 0x89, 0x81, 0x00, 0x00, 0x00, 0x00,   
0xff, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,0xff, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00
,   0x00, 0x3c, 0x42, 0x81, 0x81, 0x81, 0x42, 0x3c,  0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,  

0x00, //T
0x01,
0x01,
0xff,
0x01,
0x01,
0x01,
0x00,
        
0x00,//O
0x38,
0x44,
0x82,
0x82,
0x44,
0x38,
0x00,//N
0xFE,
0x02,
0x04,
0x08,
0x10,
0xFE,
0x00,



0x00, 0x01, 0x02, 0x04, 0xf8,0x04,0x03,0x00,

0x00, 0xe0, 0x1c, 0x12, 0x11, 0x12, 0xfc, 0x00,

0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x04, 0x0a, 0x12, 0x24, 0x48, 0x26, 0x12, 0x0c


};

const uchar heart[] = {0x04, 0x0a, 0x12, 0x24, 0x48, 0x26, 0x12, 0x0c};

const uchar zero[8] = {0x00,0x7e,0xe1,0x91,0x89,0x85,0x7e,0x00};
const uchar one[8] = {0x00,0x84,0x82,0xff,0x80,0x80,0x00,0x00};
const uchar two[8] = {0x00,0xe2,0x91,0x91,0x89,0x89,0xc6,0x00};
const uchar three[8] = {0x00,0x42,0x81,0x89,0x89,0x89,0x76,0x00};
const uchar four[8] = {0x10,0x18,0x14,0x92,0xff,0x90,0x10,0x00};
const uchar five[8] = {0x00,0x47,0x89,0x89,0x89,0x89,0x71,0x00};
const uchar six[8] = {0x00,0x7c,0x8a,0x89,0x89,0x89,0x70,0x00};
const uchar seven[8] = {0x00,0x03,0x01,0xf1,0x09,0x05,0x03,0x00};
const uchar eight[8] = {0x00,0x76,0x89,0x89,0x89,0x89,0x76,0x00};
const uchar nine[8] = {0x00,0x06,0x89,0x89,0x89,0x49,0x3e,0x00};

#define BMP280_WRITE_ADDR 0xEC      // write addess 0b11101100 lsb is R/W bit
#define BMP280_READ_ADDR 0xED       // read addess  0b11101101 lsb is R/W bit

#define BMP280_REG_DIG_T1     0x88
#define BMP280_REG_DIG_T2     0x8A
#define BMP280_REG_DIG_T3     0x8C

#define BMP280_REG_DIG_P1     0x8E
#define BMP280_REG_DIG_P2     0x90
#define BMP280_REG_DIG_P3     0x92
#define BMP280_REG_DIG_P4     0x94
#define BMP280_REG_DIG_P5     0x96
#define BMP280_REG_DIG_P6     0x98
#define BMP280_REG_DIG_P7     0x9A
#define BMP280_REG_DIG_P8     0x9C
#define BMP280_REG_DIG_P9     0x9E

#define CHIP_ID_REG 0xD0        // read only 8 bit register containing the chip ID, which is 0x58 (d'88)

#define RESET_REG 0xE0     // software reset for BMP280 achieved by writing 0xB6 to this register

#define STATUS_REG 0xF3    // bit 3 measuring[0] is auto set to 1 when conversion is running and back to 0 when results have been transfered to data registers 
                                    // bit 0 im_update[0] is set to 1 when NVM data are being copied to image registers and back to 0 when copying is complete.
                                    // STATUS_REG contains two bits which indicate the status of the BMP280

#define CTRL_MEAS_REG 0xF4 // bit 7, 6, 5 osrs_t[2.0]  controls oversampling of temperature data
                                    // bit 4, 3, 2 osrs_p[2.0]  controls oversampling of pressure data
                                    // bit 1,0 mode[1.0] controls the power mode of the device

#define CONFIG_REG 0xF5    // bit 7, 6, 5 t_sb[2.0]  controls inactive duration of t_standby in normal mode
                                    // bit 4, 3, 2 t_sb[2.0]  controls time constant of IIR filter
                                    // bit 0 spi3w_en[0] enables 3-wire SPI interface when set

#define PRESS_MSB 0xF7    //contains raw 20-bit pressure measurement data, which is split over three 8-bit registers
                                   // press_msb[7:0] contains MSB part [19:12] of the raw pressure reading
#define PRESS_LSB 0xF8    //contains raw pressure measurement data, which is split over three 8-bit registers
                                   // press_msb[7:0] contains LSB part [11:4] of the raw pressure reading
#define PRESS_XLSB 0xF9    //bit 7, 6, 5, 4 contains raw  pressure measurement data, which is split over three 8-bit registers
                                   // press_msb[7:0] contains XLSB part [3:0] of the raw pressure reading

#define TEMP_MSB 0xFA    //contains raw 20-bit temperature measurement data, which is split over three 8-bit registers
                                  // temp_msb[7:0] contains MSB part [19:12] 
#define TEMP_LSB 0xFB    // contains raw temperature measurement data, which is split over three 8-bit registers
                                  // temp_msb[7:0] contains LSB part [11:4]
#define TEMP_XLSB 0xFC   // bit 7, 6, 5, 4 contains raw  temperature measurement data, which is split over three 8-bit registers
                                  // temp_msb[7:0] contains XLSB part [3:0] 

enum {FALSE = 0, TRUE = 1};
enum BMP280_MODE
{
  MODE_SLEEP  = 0x00,   // sleep mode = 0   // Three power modes, selected by bits [1:0] of CTRL_MEAS_REG
  MODE_FORCED = 0x01,   // forced mode = 1
  MODE_NORMAL = 0x03    // normal mode = 3
} ;

enum STANDBY_TIME
{
  STANDBY_0_5   =  0x00,  // standby time = 0.5 ms
  STANDBY_62_5  =  0x01,  // standby time = 62.5 ms
  STANDBY_125   =  0x02,  // standby time = 125 ms
  STANDBY_250   =  0x03,  // standby time = 250 ms
  STANDBY_500   =  0x04,  // standby time = 500 ms
  STANDBY_1000  =  0x05,  // standby time = 1000 ms
  STANDBY_2000  =  0x06,  // standby time = 2000 ms
  STANDBY_4000  =  0x07   // standby time = 4000 ms 
};

enum BMP280_SAMPLING
{
    SAMPLING_SKIPPED = 0x00,
    SAMPLING_X1      = 0x01,
    SAMPLING_X2      = 0x02,
    SAMPLING_X4      = 0x03,
    SAMPLING_X8      = 0x04,
    SAMPLING_X16     = 0x05,   
};

enum BMP280_FILTER
{
    FILTER_OFF = 0x00,
    FILTER_2   = 0x01,
    FILTER_4   = 0x02,
    FILTER_8   = 0x03,
    FILTER_16  = 0x04,
};
