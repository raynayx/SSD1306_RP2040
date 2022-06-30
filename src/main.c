#include <stdio.h>
#include <hardware/i2c.h>
#include <hardware/gpio.h>
#include "ssd1306.h"

static void i2c_setup(void);
int main(void)
{
  i2c_setup();


  ssd1306_Init(i2c0);

  ssd1306_Fill(White);
  ssd1306_UpdateScreen(i2c0);

  sleep_ms(1000);
  
  ssd1306_SetCursor(30, 0);
  ssd1306_WriteString("LoRa", Font_11x18, Black);

  ssd1306_SetCursor(0, 20);
  ssd1306_WriteString("SNR:", Font_7x10, Black);
  ssd1306_SetCursor(0, 31);
  ssd1306_WriteString("RSSI:",Font_7x10,Black);
  ssd1306_SetCursor(0,41);
  ssd1306_WriteString("Dist:",Font_7x10,Black);
  ssd1306_UpdateScreen(i2c0);
  return 0;
}




static void i2c_setup(void)
{
	i2c_init(i2c0, 100 * 1000);
	#ifdef _BOARDS_SEEED_XIAO_RP2040_H
		gpio_set_function(XIAO_I2C_SDA_PIN, GPIO_FUNC_I2C);
		gpio_set_function(XIAO_I2C_SCL_PIN, GPIO_FUNC_I2C);
		gpio_pull_up(XIAO_I2C_SDA_PIN);
		gpio_pull_up(XIAO_I2C_SCL_PIN);
	#else
		gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
		gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
		gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
		gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
	#endif
}