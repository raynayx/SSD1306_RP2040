#include "i2c_mw.h"

#ifdef _BOARDS_SEEED_XIAO_RP2040_H
#define XIAO_I2C_SDA_PIN 4u //28u		//found on A2/D2
#define XIAO_I2C_SCL_PIN 5u //29u		//found on A3/D3
#endif

void i2c_setup(i2c_inst_t *i2c_num)
{
	i2c_init(i2c_num, 100 * 1000);
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


int i2c_reg_write(  i2c_inst_t *hi2c,const uint addr, const uint8_t reg, uint8_t *buf,const uint8_t nbytes)
{
	int num_bytes_read = 0;
	uint8_t msg[nbytes + 1];

	// Check to make sure caller is sending 1 or more bytes
	if (nbytes < 1) {
		return 0;
	}

	// Append register address to front of data packet
	msg[0] = reg;
	for (int i = 0; i < nbytes; i++) {
		msg[i + 1] = buf[i];
	}

	// Write data to register(s) over I2C
	i2c_write_blocking(hi2c, addr, msg, (nbytes + 1), false);

	return num_bytes_read;
}


int i2c_reg_read(  i2c_inst_t *hi2c,const uint addr,const uint8_t reg,uint8_t *buf,const uint8_t nbytes)
{
	int num_bytes_read = 0;

	// Check to make sure caller is asking for 1 or more bytes
	if (nbytes < 1) {
		return 0;
	}

	// Read data from register(s) over I2C
	i2c_write_blocking(hi2c, addr, &reg, 1, true);
	num_bytes_read = i2c_read_blocking(hi2c, addr, buf, nbytes, false);

	return num_bytes_read;
}

