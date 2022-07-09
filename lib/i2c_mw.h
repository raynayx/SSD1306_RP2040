/***
 * 
 * 
 * 
 * 
 ***/

#ifndef _I2C_MW_H_
#define _I2C_MW_H_
#include <hardware/i2c.h>
#include <hardware/gpio.h>

void i2c_setup(i2c_inst_t *i2c_num);

//I2C write to specific device register
int i2c_reg_write(i2c_inst_t *hi2c, const uint addr, const uint8_t reg, uint8_t *buf,const uint8_t nbytes);

// read from specific device register
int i2c_reg_read(   i2c_inst_t *hi2c,const uint addr,const uint8_t reg,uint8_t *buf,const uint8_t nbytes);


#endif //_I2C_MW_H_