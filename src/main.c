#include <stdio.h>
#include <hardware/i2c.h>
#include <hardware/gpio.h>
#include "ssd1306.h"
#include "rene.h"

int main(void)
{
  ssd1306_Init(i2c0);

  ssd1306_Fill(White);
  ssd1306_UpdateScreen(i2c0);

  // sleep_ms(1000);
  
  ssd1306_SetCursor(35, 0);
  ssd1306_WriteString("LoRa", Font_11x18, Black);

  ssd1306_SetCursor(0, 20);
  ssd1306_WriteString("SNR: ", Font_7x10, Black);
  ssd1306_WriteString("-7dB", Font_7x10, Black);

  ssd1306_SetCursor(0, 31);
  ssd1306_WriteString("RSSI:  ",Font_7x10,Black);
  ssd1306_WriteString("-70dBm", Font_7x10, Black);

  ssd1306_SetCursor(0,50);
  ssd1306_WriteString("Dist:  ",Font_7x10,Black);
  ssd1306_SetCursor(35,42);
  ssd1306_WriteString("400m", Font_11x18, Black);


  // ssd1306_DrawBitmap(0,0,rene_bmp,128,64,Black);

  ssd1306_UpdateScreen(i2c0);
  return 0;
}




