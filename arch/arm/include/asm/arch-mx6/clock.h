/*
 * (C) Copyright 2009
 * Stefano Babic, DENX Software Engineering, sbabic@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __ASM_ARCH_CLOCK_H
#define __ASM_ARCH_CLOCK_H

#include <common.h>

#ifdef CONFIG_SYS_MX6_HCLK
#define MXC_HCLK	CONFIG_SYS_MX6_HCLK
#else
#define MXC_HCLK	24000000
#endif

#ifdef CONFIG_SYS_MX6_CLK32
#define MXC_CLK32	CONFIG_SYS_MX6_CLK32
#else
#define MXC_CLK32	32768
#endif

enum mxc_clock {
	MXC_ARM_CLK = 0,
	MXC_PER_CLK,
	MXC_AHB_CLK,
	MXC_IPG_CLK,
	MXC_IPG_PERCLK,
	MXC_UART_CLK,
	MXC_CSPI_CLK,
	MXC_AXI_CLK,
	MXC_EMI_SLOW_CLK,
	MXC_DDR_CLK,
	MXC_ESDHC_CLK,
	MXC_ESDHC2_CLK,
	MXC_ESDHC3_CLK,
	MXC_ESDHC4_CLK,
	MXC_SATA_CLK,
	MXC_NFC_CLK,
	MXC_I2C_CLK,
};

u32 imx_get_uartclk(void);
u32 imx_get_fecclk(void);
unsigned int mxc_get_clock(enum mxc_clock clk);
void enable_usboh3_clk(unsigned char enable);
int enable_sata_clock(void);
int enable_i2c_clk(unsigned char enable, unsigned i2c_num);

enum mxc_clko1_parents {
	CLKO1_PLL3_SW_CLK,
	CLKO1_PLL2_MAIN_CLK,
	CLKO1_PLL1_MAIN_CLK,
	CLKO1_PLL5_MAIN_CLK,
	CLKO1_VIDEO_27M_CLK_ROOT,
	CLKO1_AXI_CLK_ROOT,
	CLKO1_ENFC_CLK_ROOT,
	CLKO1_IPU1_DI0_CLK_ROOT,
	CLKO1_IPU1_DI1_CLK_ROOT,
	CLKO1_IPU2_DI0_CLK_ROOT,
	CLKO1_IPU2_DI1_CLK_ROOT,
	CLKO1_AHB_CLK_ROOT,
	CLKO1_IPG_CLK_ROOT,
	CLKO1_PERCLK_ROOT,
	CLKO1_CKIL_SYNC_CLK_ROOT,
	CLKO1_PLL4_MAIN_CLK,
};

void enable_clko1(unsigned parent, unsigned div);

#endif /* __ASM_ARCH_CLOCK_H */