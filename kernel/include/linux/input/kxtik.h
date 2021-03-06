/* include/linux/input/kxtik.h - KXTIK accelerometer driver
 *
 * Copyright (C) 2011 Kionix, Inc.
 * Written by Kuching Tan <kuchingtan@kionix.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __KXTIK_H__
#define __KXTIK_H__

#define KXTIK_I2C_ADDR		0x0F

struct kxtik_platform_data {
	unsigned int min_interval;	/* minimum poll interval (in milli-seconds) */
	unsigned int poll_interval;	/* desired poll interval (in milli-seconds) */

	/*
	 * By default, x is axis 0, y is axis 1, z is axis 2; these can be
	 * changed to account for sensor orientation within the host device.
	 */
	u8 axis_map_x;
	u8 axis_map_y;
	u8 axis_map_z;

	/*
	 * Each axis can be negated to account for sensor orientation within
	 * the host device.
	 */
	bool negate_x;
	bool negate_y;
	bool negate_z;

	/* CTRL_REG1: set resolution, g-range, data ready enable */
	/* Output resolution: 8-bit valid or 12-bit valid */
	#define RES_8BIT		0
	#define RES_12BIT		(1 << 6)
	u8 res_12bit;
	/* Output g-range: +/-2g, 4g, or 8g */
	#define KXTIK_G_2G		0
	#define KXTIK_G_4G		(1 << 3)
	#define KXTIK_G_8G		(1 << 4)
	u8 g_range;

	/* DATA_CTRL_REG: controls the output data rate of the part */
	#define ODR12_5F		0
	#define ODR25F			1
	#define ODR50F			2
	#define ODR100F			3
	#define ODR200F			4
	#define ODR400F			5
	#define ODR800F			6

	int (*init)(void);
	void (*exit)(void);
	int (*power_on)(void);
	int (*power_off)(void);
};
#endif  /* __KXTIK_H__ */
