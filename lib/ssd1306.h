/**
 * This library is an adaptation of https://github.com/4ilo/ssd1306-stm32HAL written by
 *  Olivier Van den Eede(4ilo) for use with the RP2040 Pico SDK HAL
 * The changes I made have to do with the I2C write functions.
 * 
 * 
 * Original comment by 4ilo:
 * ################################################################################################
 * This Library is written and optimized by Olivier Van den Eede(4ilo) in 2016
 * for Stm32 Uc and HAL-i2c lib's.
 *
 * To use this library with ssd1306 oled display you will need to customize the defines below.
 *
 * This library uses 2 extra files (fonts.c/h).
 * In this files are 3 different fonts you can use:
 *     - Font_7x10
 *     - Font_11x18
 *     - Font_16x26
 *####################################################################################################
 */

#ifndef _SSD1306_H
#define _SSD1306_H

#include "hardware/i2c.h"
#include "fonts.h"

// I2c address
#ifndef SSD1306_I2C_ADDR
#define SSD1306_I2C_ADDR        0x3C
#endif // SSD1306_I2C_ADDR

// SSD1306 width in pixels
#ifndef SSD1306_WIDTH
#define SSD1306_WIDTH           128
#endif // SSD1306_WIDTH

// SSD1306 LCD height in pixels
#ifndef SSD1306_HEIGHT
#define SSD1306_HEIGHT          64
#endif // SSD1306_HEIGHT


//
//  Enumeration for screen colors
//
typedef enum {
    Black = 0x00,   // Black color, no pixel
    White = 0x01,   // Pixel is set. Color depends on LCD
} SSD1306_COLOR;

//
//  Struct to store transformations
//
typedef struct {
    uint16_t CurrentX;
    uint16_t CurrentY;
    uint8_t Inverted;
    uint8_t Initialized;
} SSD1306_t;

//
//  Function definitions
//

uint8_t ssd1306_Init(i2c_inst_t *hi2c);
void ssd1306_UpdateScreen(i2c_inst_t *hi2c);
void ssd1306_Fill(SSD1306_COLOR color);
void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color);
char ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color);
char ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color);
void ssd1306_SetCursor(uint8_t x, uint8_t y);
void ssd1306_InvertColors(void);


//I2C write to specific device register
int i2c_reg_write(i2c_inst_t *hi2c, const uint addr, const uint8_t reg, uint8_t *buf,const uint8_t nbytes);

// read from specific device register
int i2c_reg_read(   i2c_inst_t *hi2c,const uint addr,const uint8_t reg,uint8_t *buf,const uint8_t nbytes);
#endif  // _SSD1306_H
