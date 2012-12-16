/**
 ******************************************************************************
 * @addtogroup PIOS PIOS Core hardware abstraction layer
 * @{
 * @addtogroup PIOS_MPU6000 MPU6000 Functions
 * @brief Deals with the hardware interface to the 3-axis gyro
 * @{
 *
 * @file       PIOS_MPU6000.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2012.
 * @brief      MPU6000 3-axis gyor function headers
 * @see        The GNU Public License (GPL) Version 3
 *
 ******************************************************************************
 */
/* 
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 3 of the License, or 
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 * for more details.
 * 
 * You should have received a copy of the GNU General Public License along 
 * with this program; if not, write to the Free Software Foundation, Inc., 
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef PIOS_MPU6000_H
#define PIOS_MPU6000_H

#include "pios.h"

#define MPU6000_REV_C                           0x14
#define MPU6000_REV_D                           0x58
                                                        // Product ID Description for MPU6000
                                                        // high 4 bits          low 4 bits
     	 	 	 	 	 	 	 	 	 	 	 	 	// Product Name Product Revision
#define MPU6000ES_REV_C4                        0x14    // 0001                 0100
#define MPU6000ES_REV_C5                        0x15    // 0001                 0101
#define MPU6000ES_REV_D6                        0x16    // 0001                 0110
#define MPU6000ES_REV_D7                        0x17    // 0001                 0111
#define MPU6000ES_REV_D8                        0x18    // 0001                 1000
#define MPU6000_REV_C4                          0x54    // 0101                 0100
#define MPU6000_REV_C5                          0x55    // 0101                 0101
#define MPU6000_REV_D6                          0x56    // 0101                 0110
#define MPU6000_REV_D7                          0x57    // 0101                 0111
#define MPU6000_REV_D8                          0x58    // 0101                 1000
#define MPU6000_REV_D9                          0x59    // 0101                 1001



/* MPU6000 Addresses */
#define MPUREG_XG_OFFS_TC                               0x00
#define MPUREG_YG_OFFS_TC                               0x01
#define MPUREG_ZG_OFFS_TC                               0x02
#define MPUREG_X_FINE_GAIN                              0x03
#define MPUREG_Y_FINE_GAIN                              0x04
#define MPUREG_Z_FINE_GAIN                              0x05
#define MPUREG_XA_OFFS_H                                0x06    // X axis accelerometer offset (high byte)
#define MPUREG_XA_OFFS_L                                0x07    // X axis accelerometer offset (low byte)
#define MPUREG_YA_OFFS_H                                0x08    // Y axis accelerometer offset (high byte)
#define MPUREG_YA_OFFS_L                                0x09    // Y axis accelerometer offset (low byte)
#define MPUREG_ZA_OFFS_H                                0x0A    // Z axis accelerometer offset (high byte)
#define MPUREG_ZA_OFFS_L                                0x0B    // Z axis accelerometer offset (low byte)

#define PIOS_MPU6000_MPUREG_PRODUCT_ID    0x0C    // Product ID Register
/* MPU6000 Addresses */
#define PIOS_MPU6000_SMPLRT_DIV_REG       0X19
#define PIOS_MPU6000_DLPF_CFG_REG         0X1A
#define PIOS_MPU6000_GYRO_CFG_REG         0X1B
#define PIOS_MPU6000_ACCEL_CFG_REG        0X1C
#define PIOS_MPU6000_FIFO_EN_REG          0x23
#define PIOS_MPU6000_INT_CFG_REG          0x37
#define PIOS_MPU6000_INT_EN_REG           0x38
#define PIOS_MPU6000_INT_STATUS_REG       0x3A
#define PIOS_MPU6000_ACCEL_X_OUT_MSB      0x3B
#define PIOS_MPU6000_ACCEL_X_OUT_LSB      0x3C
#define PIOS_MPU6000_ACCEL_Y_OUT_MSB      0x3D
#define PIOS_MPU6000_ACCEL_Y_OUT_LSB      0x3E
#define PIOS_MPU6000_ACCEL_Z_OUT_MSB      0x3F
#define PIOS_MPU6000_ACCEL_Z_OUT_LSB      0x40
#define PIOS_MPU6000_TEMP_OUT_MSB         0x41
#define PIOS_MPU6000_TEMP_OUT_LSB         0x42
#define PIOS_MPU6000_GYRO_X_OUT_MSB       0x43
#define PIOS_MPU6000_GYRO_X_OUT_LSB       0x44
#define PIOS_MPU6000_GYRO_Y_OUT_MSB       0x45
#define PIOS_MPU6000_GYRO_Y_OUT_LSB       0x46
#define PIOS_MPU6000_GYRO_Z_OUT_MSB       0x47
#define PIOS_MPU6000_GYRO_Z_OUT_LSB       0x48
#define PIOS_MPU6000_USER_CTRL_REG        0x6A
#define PIOS_MPU6000_PWR_MGMT_REG         0x6B
#define PIOS_MPU6000_FIFO_CNT_MSB         0x72
#define PIOS_MPU6000_FIFO_CNT_LSB         0x73
#define PIOS_MPU6000_FIFO_REG             0x74
#define PIOS_MPU6000_WHOAMI               0x75

/* FIFO enable for storing different values */
#define PIOS_MPU6000_FIFO_TEMP_OUT        0x80
#define PIOS_MPU6000_FIFO_GYRO_X_OUT      0x40
#define PIOS_MPU6000_FIFO_GYRO_Y_OUT      0x20
#define PIOS_MPU6000_FIFO_GYRO_Z_OUT      0x10
#define PIOS_MPU6000_ACCEL_OUT            0x08

/* Interrupt Configuration */
#define PIOS_MPU6000_INT_ACTL             0x80
#define PIOS_MPU6000_INT_OPEN             0x40
#define PIOS_MPU6000_INT_LATCH_EN         0x20
#define PIOS_MPU6000_INT_CLR_ANYRD        0x10

#define PIOS_MPU6000_INTEN_OVERFLOW       0x10
#define PIOS_MPU6000_INTEN_DATA_RDY       0x01

/* Interrupt status */
#define PIOS_MPU6000_INT_STATUS_FIFO_FULL 0x80
#define PIOS_MPU6000_INT_STATUS_IMU_RDY   0X04
#define PIOS_MPU6000_INT_STATUS_DATA_RDY  0X01

/* User control functionality */
#define PIOS_MPU6000_USERCTL_FIFO_EN      0X40
#define PIOS_MPU6000_USERCTL_DIS_I2C      0X10
#define PIOS_MPU6000_USERCTL_FIFO_RST     0X02
#define PIOS_MPU6000_USERCTL_GYRO_RST     0X01

/* Power management and clock selection */
#define PIOS_MPU6000_PWRMGMT_IMU_RST      0X80
#define PIOS_MPU6000_PWRMGMT_INTERN_CLK   0X00
#define PIOS_MPU6000_PWRMGMT_PLL_X_CLK    0X01
#define PIOS_MPU6000_PWRMGMT_PLL_Y_CLK    0X02
#define PIOS_MPU6000_PWRMGMT_PLL_Z_CLK    0X03
#define PIOS_MPU6000_PWRMGMT_STOP_CLK     0X07

enum pios_mpu6000_range {
	PIOS_MPU6000_SCALE_250_DEG  = 0x00,
	PIOS_MPU6000_SCALE_500_DEG  = 0x08,
	PIOS_MPU6000_SCALE_1000_DEG = 0x10,
	PIOS_MPU6000_SCALE_2000_DEG = 0x18
};

enum pios_mpu6000_filter {
	PIOS_MPU6000_LOWPASS_256_HZ = 0x00,
	PIOS_MPU6000_LOWPASS_188_HZ = 0x01,
	PIOS_MPU6000_LOWPASS_98_HZ  = 0x02,
	PIOS_MPU6000_LOWPASS_42_HZ  = 0x03,
	PIOS_MPU6000_LOWPASS_20_HZ  = 0x04,
	PIOS_MPU6000_LOWPASS_10_HZ  = 0x05,
	PIOS_MPU6000_LOWPASS_5_HZ   = 0x06
};

enum pios_mpu6000_accel_range {
	PIOS_MPU6000_ACCEL_2G = 0x00,
	PIOS_MPU6000_ACCEL_4G = 0x08,
	PIOS_MPU6000_ACCEL_8G = 0x10,
	PIOS_MPU6000_ACCEL_16G = 0x18
};

enum pios_mpu6000_orientation { // clockwise rotation from board forward
	PIOS_MPU6000_TOP_0DEG    = 0x00,
	PIOS_MPU6000_TOP_90DEG   = 0x01,
	PIOS_MPU6000_TOP_180DEG  = 0x02,
	PIOS_MPU6000_TOP_270DEG  = 0x03
};

struct pios_mpu6000_data {
	int16_t gyro_x;
	int16_t gyro_y;
	int16_t gyro_z;
#if defined(PIOS_MPU6000_ACCEL)
	int16_t accel_x;
	int16_t accel_y;
	int16_t accel_z;
#endif /* PIOS_MPU6000_ACCEL */
	int16_t temperature;
};

struct pios_mpu6000_cfg {
	const struct pios_exti_cfg * exti_cfg; /* Pointer to the EXTI configuration */
	
	uint8_t Fifo_store;		/* FIFO storage of different readings (See datasheet page 31 for more details) */
	uint8_t Smpl_rate_div;	/* Sample rate divider to use (See datasheet page 32 for more details) */
	uint8_t interrupt_cfg;	/* Interrupt configuration (See datasheet page 35 for more details) */
	uint8_t interrupt_en;	/* Interrupt configuration (See datasheet page 35 for more details) */
	uint8_t User_ctl;		/* User control settings (See datasheet page 41 for more details)  */
	uint8_t Pwr_mgmt_clk;	/* Power management and clock selection (See datasheet page 32 for more details) */
	enum pios_mpu6000_accel_range accel_range;
	enum pios_mpu6000_range gyro_range;
	enum pios_mpu6000_filter filter;
	enum pios_mpu6000_orientation orientation;
};

/* Public Functions */
extern int32_t PIOS_MPU6000_Init(uint32_t spi_id, uint32_t slave_num, const struct pios_mpu6000_cfg * new_cfg);
extern xQueueHandle PIOS_MPU6000_GetQueue();
extern int32_t PIOS_MPU6000_ReadGyros(struct pios_mpu6000_data * buffer);
extern int32_t PIOS_MPU6000_ReadID();
extern int32_t PIOS_MPU6000_Test();
extern float PIOS_MPU6000_GetScale();
extern float PIOS_MPU6000_GetAccelScale();
extern bool PIOS_MPU6000_IRQHandler(void);
extern int32_t PIOS_MPU6000_Read_PRODUCT_ID();

#endif /* PIOS_MPU6000_H */

/** 
  * @}
  * @}
  */