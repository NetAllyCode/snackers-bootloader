#undef MX6PAD
#undef MX6NAME

#ifdef FOR_DL_SOLO
#define MX6PAD(a) MX6DL_PAD_##a
#define MX6NAME(a) mx6dl_solo_##a
#else
#define MX6PAD(a) MX6Q_PAD_##a
#define MX6NAME(a) mx6q_##a
#endif

#define UART_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |	       \
	PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED |	       \
	PAD_CTL_DSE_40ohm   | PAD_CTL_SRE_FAST  | PAD_CTL_HYS)

#define USDHC_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |	       \
	PAD_CTL_PUS_47K_UP  | PAD_CTL_SPEED_LOW |	       \
	PAD_CTL_DSE_80ohm   | PAD_CTL_SRE_FAST  | PAD_CTL_HYS)

#define ENET_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |		\
	PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED	  |		\
	PAD_CTL_DSE_40ohm   | PAD_CTL_HYS)

#define SPI_PAD_CTRL (PAD_CTL_HYS |				\
	PAD_CTL_PUS_100K_DOWN | PAD_CTL_SPEED_MED |		\
	PAD_CTL_DSE_40ohm     | PAD_CTL_SRE_FAST)

#define BUTTON_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
	PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED   |		\
	PAD_CTL_DSE_40ohm   | PAD_CTL_HYS)

#define I2C_PAD_CTRL	(PAD_CTL_PKE | PAD_CTL_PUE |		\
	PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED |		\
	PAD_CTL_DSE_40ohm | PAD_CTL_HYS |			\
	PAD_CTL_ODE | PAD_CTL_SRE_FAST)

iomux_v3_cfg_t MX6NAME(uart1_pads)[] = {
	MX6PAD(SD3_DAT6__UART1_RXD) | MUX_PAD_CTRL(UART_PAD_CTRL),
	MX6PAD(SD3_DAT7__UART1_TXD) | MUX_PAD_CTRL(UART_PAD_CTRL),
};

iomux_v3_cfg_t MX6NAME(uart2_pads)[] = {
	MX6PAD(EIM_D26__UART2_TXD) | MUX_PAD_CTRL(UART_PAD_CTRL),
	MX6PAD(EIM_D27__UART2_RXD) | MUX_PAD_CTRL(UART_PAD_CTRL),
};

#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)

struct i2c_pads_info MX6NAME(i2c_pad_info)[] = {
	{
		/* I2C1, SGTL5000 */
		.scl = {
			.i2c_mode = MX6PAD(EIM_D21__I2C1_SCL) | PC,
			.gpio_mode = MX6PAD(EIM_D21__GPIO_3_21) | PC,
			.gp = IMX_GPIO_NR(3, 21)
		},
		.sda = {
			.i2c_mode = MX6PAD(EIM_D28__I2C1_SDA) | PC,
			.gpio_mode = MX6PAD(EIM_D28__GPIO_3_28) | PC,
			.gp = IMX_GPIO_NR(3, 28)
		}
	}, {
		/* I2C2 Camera, MIPI */
		.scl = {
			.i2c_mode = MX6PAD(KEY_COL3__I2C2_SCL) | PC,
			.gpio_mode = MX6PAD(KEY_COL3__GPIO_4_12) | PC,
			.gp = IMX_GPIO_NR(4, 12)
		},
		.sda = {
			.i2c_mode = MX6PAD(KEY_ROW3__I2C2_SDA) | PC,
			.gpio_mode = MX6PAD(KEY_ROW3__GPIO_4_13) | PC,
			.gp = IMX_GPIO_NR(4, 13)
		}
	}, {
		/* I2C3, J15 - RGB connector */
		.scl = {
			.i2c_mode = MX6PAD(GPIO_5__I2C3_SCL) | PC,
			.gpio_mode = MX6PAD(GPIO_5__GPIO_1_5) | PC,
			.gp = IMX_GPIO_NR(1, 5)
		},
		.sda = {
			.i2c_mode = MX6PAD(GPIO_16__I2C3_SDA) | PC,
			.gpio_mode = MX6PAD(GPIO_16__GPIO_7_11) | PC,
			.gp = IMX_GPIO_NR(7, 11)
		}
	}
};

iomux_v3_cfg_t MX6NAME(usdhc3_pads)[] = {
	MX6PAD(SD3_CLK__USDHC3_CLK)   | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(SD3_CMD__USDHC3_CMD)   | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(SD3_DAT0__USDHC3_DAT0) | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(SD3_DAT1__USDHC3_DAT1) | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(SD3_DAT2__USDHC3_DAT2) | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(SD3_DAT3__USDHC3_DAT3) | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(SD3_DAT5__GPIO_7_0)    | MUX_PAD_CTRL(NO_PAD_CTRL), /* CD */
};

iomux_v3_cfg_t MX6NAME(usdhc4_pads)[] = {
	MX6PAD(SD4_CLK__USDHC4_CLK)   | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(SD4_CMD__USDHC4_CMD)   | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(SD4_DAT0__USDHC4_DAT0) | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(SD4_DAT1__USDHC4_DAT1) | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(SD4_DAT2__USDHC4_DAT2) | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(SD4_DAT3__USDHC4_DAT3) | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	MX6PAD(NANDF_D6__GPIO_2_6)    | MUX_PAD_CTRL(NO_PAD_CTRL), /* CD */
};

iomux_v3_cfg_t MX6NAME(enet_pads1)[] = {
	MX6PAD(ENET_MDIO__ENET_MDIO)		| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(ENET_MDC__ENET_MDC)		| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(RGMII_TXC__ENET_RGMII_TXC)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(RGMII_TD0__ENET_RGMII_TD0)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(RGMII_TD1__ENET_RGMII_TD1)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(RGMII_TD2__ENET_RGMII_TD2)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(RGMII_TD3__ENET_RGMII_TD3)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(RGMII_TX_CTL__RGMII_TX_CTL)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(ENET_REF_CLK__ENET_TX_CLK)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	/* pin 35 - 1 (PHY_AD2) on reset */
	MX6PAD(RGMII_RXC__GPIO_6_30)		| MUX_PAD_CTRL(NO_PAD_CTRL),
	/* pin 32 - 1 - (MODE0) all */
	MX6PAD(RGMII_RD0__GPIO_6_25)		| MUX_PAD_CTRL(NO_PAD_CTRL),
	/* pin 31 - 1 - (MODE1) all */
	MX6PAD(RGMII_RD1__GPIO_6_27)		| MUX_PAD_CTRL(NO_PAD_CTRL),
	/* pin 28 - 1 - (MODE2) all */
	MX6PAD(RGMII_RD2__GPIO_6_28)		| MUX_PAD_CTRL(NO_PAD_CTRL),
	/* pin 27 - 1 - (MODE3) all */
	MX6PAD(RGMII_RD3__GPIO_6_29)		| MUX_PAD_CTRL(NO_PAD_CTRL),
	/* pin 33 - 1 - (CLK125_EN) 125Mhz clockout enabled */
	MX6PAD(RGMII_RX_CTL__GPIO_6_24)	| MUX_PAD_CTRL(NO_PAD_CTRL),
	/* pin 42 PHY nRST */
	MX6PAD(EIM_D23__GPIO_3_23)		| MUX_PAD_CTRL(NO_PAD_CTRL),
};

iomux_v3_cfg_t MX6NAME(enet_pads2)[] = {
	MX6PAD(RGMII_RXC__ENET_RGMII_RXC)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(RGMII_RD0__ENET_RGMII_RD0)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(RGMII_RD1__ENET_RGMII_RD1)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(RGMII_RD2__ENET_RGMII_RD2)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(RGMII_RD3__ENET_RGMII_RD3)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
	MX6PAD(RGMII_RX_CTL__RGMII_RX_CTL)	| MUX_PAD_CTRL(ENET_PAD_CTRL),
};

/* Button assignments for J14 */
static iomux_v3_cfg_t MX6NAME(button_pads)[] = {
	/* Menu */
	MX6PAD(NANDF_D1__GPIO_2_1)	| MUX_PAD_CTRL(BUTTON_PAD_CTRL),
	/* Back */
	MX6PAD(NANDF_D2__GPIO_2_2)	| MUX_PAD_CTRL(BUTTON_PAD_CTRL),
	/* Labelled Search (mapped to Power under Android) */
	MX6PAD(NANDF_D3__GPIO_2_3)	| MUX_PAD_CTRL(BUTTON_PAD_CTRL),
	/* Home */
	MX6PAD(NANDF_D4__GPIO_2_4)	| MUX_PAD_CTRL(BUTTON_PAD_CTRL),
	/* Volume Down */
	MX6PAD(GPIO_19__GPIO_4_5)	| MUX_PAD_CTRL(BUTTON_PAD_CTRL),
	/* Volume Up */
	MX6PAD(GPIO_18__GPIO_7_13)	| MUX_PAD_CTRL(BUTTON_PAD_CTRL),
};

iomux_v3_cfg_t MX6NAME(usb_pads)[] = {
	MX6PAD(GPIO_17__GPIO_7_12) | MUX_PAD_CTRL(NO_PAD_CTRL),
};

#ifdef CONFIG_MXC_SPI
iomux_v3_cfg_t MX6NAME(ecspi1_pads)[] = {
	/* SS1 */
	MX6PAD(EIM_D19__GPIO_3_19)   | MUX_PAD_CTRL(SPI_PAD_CTRL),
	MX6PAD(EIM_D17__ECSPI1_MISO) | MUX_PAD_CTRL(SPI_PAD_CTRL),
	MX6PAD(EIM_D18__ECSPI1_MOSI) | MUX_PAD_CTRL(SPI_PAD_CTRL),
	MX6PAD(EIM_D16__ECSPI1_SCLK) | MUX_PAD_CTRL(SPI_PAD_CTRL),
};
#endif