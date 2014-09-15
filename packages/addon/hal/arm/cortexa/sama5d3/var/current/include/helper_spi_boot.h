#ifndef CYGONCE_HELPER_SPIBOOT_H
#define CYGONCE_HELPER_SPIBOOT_H
//=============================================================================
//
//      helper_spi_boot.h
//
//      spi boot
//
//=============================================================================
// Author(s):    ychun.w@gamil.com
// Date:         2012-09-18
// Usage:        #include <cyg/hal/helper_spi_boot.h>
//     Only used by "vectors.S"
//
//
//=============================================================================


.macro	LOAD_ATMEL_DATAFLASH
	// 启动这些设备的时钟
	ldr		r1,=AT91C_PMC_PCER
	ldr		r2,=( (1 << AT91C_ID_PIOA ) | (1 << AT91C_ID_SPI0) )
	str		r2,[r1]

	ldr	r1,=AT91C_PIOA_ASR
	ldr	r2,=(AT91C_PA0_SPI0_MISO | AT91C_PA1_SPI0_MOSI | AT91C_PA2_SPI0_SPCK)
	str	r2,[r1]
	ldr	r1,=AT91C_PIOA_PDR
	str	r2,[r1]

	// We use manual model for SPI chip select, so PA3 is in IO model.
	ldr	r1,=AT91C_PIOA_PER
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]
	ldr	r1,=AT91C_PIOA_OER
	str	r2,[r1]

	// 设定SPI0上信号的上拉。

	ldr	r1,=AT91C_PIOA_PPUER
	ldr	r2,=( AT91C_PA1_SPI0_MOSI | AT91C_PA2_SPI0_SPCK | AT91C_PIO_PA3)
	str	r2,[r1]
	// 主入信号设定为浮空。
	ldr	r1,=AT91C_PIOA_MDER
	ldr	r2,=( AT91C_PA0_SPI0_MISO )
	str	r2,[r1]

	ldr	r1,=AT91C_SPI0_CR
	ldr	r2,=(AT91C_SPI_SWRST)
	str	r2,[r1]

	ldr	r1,=AT91C_SPI0_MR
	//ldr	r2,=(AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | AT91C_SPI_PCS)
	ldr	r2,=(AT91C_SPI_MSTR | AT91C_SPI_MODFDIS )
	str	r2,[r1]

	//(AT91C_SPI_NCPHA | (AT91C_SPI_DLYBS & DATAFLASH_TCSS) | (AT91C_SPI_DLYBCT & DATAFLASH_TCHS) | ((MASTER_CLOCK / AT91C_SPI_CLK) << 8))

	ldr	r1,=AT91C_SPI0_CSR
	//		ldr	r2,=( (0x20 << 8) | AT91C_SPI_CPOL | AT91C_SPI_BITS_8 | (0x1 << 16) | (0x1 << 24))
	ldr	r2,=( (0x20 << 8) | AT91C_SPI_BITS_8 | (0x1 << 16) | (0x1 << 24))
	str	r2,[r1]

	/* SPI_Enable */
	ldr	r1,=AT91C_SPI0_CR
	ldr	r2,=(AT91C_SPI_SPIEN)
	str	r2,[r1]

95:
	ldr	r1,=AT91C_PIOA_SODR
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]

	ldr	r1,=AT91C_PIOA_CODR
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]
	LDELAY
	SHOW_DBGU_CHAR 'X'
#define DF_STATUS_READ_CMD                  0x57
	SPI_CHAR DF_STATUS_READ_CMD
	SPI_CHAR 0x0
	and r2,r2,#0x03c
	ldr	r1, =0x2c	// AT45DB161B
	cmp r2, r1
	beq	98f
	ldr	r1, =0x34	// AT45DB321B
	cmp r2, r1
	beq	98f
	ldr	r1, =0x3c	// AT45DB642
	cmp r2, r1
	beq	98f
	b	150f
98:
	// 发送连续读的指令：
	ldr	r1,=AT91C_PIOA_SODR
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]
	SHOW_DBGU_CHAR '*'
	ldr	r1,=AT91C_PIOA_CODR
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]
	LDELAY
#define DF_CONT_ARRAY_READ_CMD              0x68
	SPI_CHAR DF_CONT_ARRAY_READ_CMD
	SPI_CHAR 0x0
	SPI_CHAR 0x0
	SPI_CHAR 0x0
	SPI_CHAR 0x0
	SPI_CHAR 0x0
	SPI_CHAR 0x0
	SPI_CHAR 0x0

	ldr	r3,=START_ADDR
	ldr		r5,=__bss_start
	// 结束地址减去开始地址。
	sub		r5,r5,r3

130:
	ands r4, r5, #0x3f
	bne 140f
	SHOW_DBGU_CHAR '*'
140:
	SPI_CHAR 0x0
	strb r2,[r3], #1
	subs r5, r5, #1
	bne	130b
	ldr	r1,=AT91C_PIOA_SODR
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]
	SHOW_DBGU_CHAR '+'
150:
.endm

//------------------------------------------------------------------------------------------------------------

.macro	LOAD_MP25_DATAFLASH
	// 启动这些设备的时钟
	ldr		r1,=AT91C_PMC_PCER
	ldr		r2,=( (1 << AT91C_ID_PIOA ) | (1 << AT91C_ID_SPI0) )
	str		r2,[r1]

	ldr	r1,=AT91C_PIOA_ASR
	//ldr	r2,=(AT91C_PA0_SPI0_MISO | AT91C_PA1_SPI0_MOSI | AT91C_PA2_SPI0_SPCK | AT91C_PA3_SPI0_NPCS0)
	ldr	r2,=(AT91C_PA0_SPI0_MISO | AT91C_PA1_SPI0_MOSI | AT91C_PA2_SPI0_SPCK)
	str	r2,[r1]
	ldr	r1,=AT91C_PIOA_PDR
	str	r2,[r1]

	ldr	r1,=AT91C_PIOA_PER
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]

	ldr	r1,=AT91C_PIOA_OER
	str	r2,[r1]

	// 设定SPI0上信号的上拉。
	ldr	r1,=AT91C_PIOA_PPUER
//	ldr	r2,=(AT91C_PA0_SPI0_MISO | AT91C_PA1_SPI0_MOSI | AT91C_PA2_SPI0_SPCK | AT91C_PIO_PA3)
	ldr	r2,=(AT91C_PA1_SPI0_MOSI | AT91C_PA2_SPI0_SPCK | AT91C_PIO_PA3)
	str	r2,[r1]
	// 数据输入设定为 开放态。 // AT91C_PA1_SPI0_MOSI
	ldr	r1,=AT91C_PIOA_MDER
	ldr	r2,=AT91C_PA0_SPI0_MISO
	str	r2,[r1]

	ldr	r1,=AT91C_SPI0_CR
	ldr	r2,=(AT91C_SPI_SWRST)
	str	r2,[r1]

	ldr	r1,=AT91C_SPI0_MR
	//ldr	r2,=(AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | AT91C_SPI_PCS)
	ldr	r2,=(AT91C_SPI_MSTR | AT91C_SPI_MODFDIS )
	str	r2,[r1]

	//(AT91C_SPI_NCPHA | (AT91C_SPI_DLYBS & DATAFLASH_TCSS) | (AT91C_SPI_DLYBCT & DATAFLASH_TCHS) | ((MASTER_CLOCK / AT91C_SPI_CLK) << 8))

	ldr	r1,=AT91C_SPI0_CSR
	//		ldr	r2,=( (0x20 << 8) | AT91C_SPI_CPOL | AT91C_SPI_BITS_8 | (0x1 << 16) | (0x1 << 24))
	// AT91C_SPI_CPOL AT91C_SPI_NCPHA
	ldr	r2,=( (0x20 << 8) | AT91C_SPI_BITS_8 | (0x1 << 16) | (0x1 << 24) | AT91C_SPI_NCPHA )
	str	r2,[r1]

	/* SPI_Enable */
	ldr	r1,=AT91C_SPI0_CR
	ldr	r2,=(AT91C_SPI_SPIEN)
	str	r2,[r1]

95:
	ldr	r1,=AT91C_PIOA_SODR
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]

	ldr	r1,=AT91C_PIOA_CODR
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]
	LDELAY
	SHOW_DBGU_CHAR 'X'
	SPI_CHAR 0x9F							// MX25LXXX_CMD_RDID
	SPI_CHAR 0x0
	ands r2,r2,#0xff
	ldr	r1, =0xc2	// ID
	cmp r2, r1
	bne	150f
	SPI_CHAR 0x0
	ldr	r1, =0x20	// 0X20
	ands r2,r2,#0xff
	cmp r2, r1
	bne	150f

	SHOW_DBGU_CHAR ' '
	SHOW_DBGU_CHAR 'M'
	SHOW_DBGU_CHAR 'X'
	SHOW_DBGU_CHAR '2'
	SHOW_DBGU_CHAR '5'
	SHOW_DBGU_CHAR ' '
	SPI_CHAR 0x0
	ands r2,r2,#0xff
	ldr	r1, =0x16
	cmp r2, r1
	beq	98f
	ldr	r1, =0x17
	cmp r2, r1
	beq	98f
	ldr	r1, =0x18
	cmp r2, r1
	beq	98f
	b	95b
98:
	// 发送连续读的指令：
	ldr	r1,=AT91C_PIOA_SODR
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]
	SHOW_DBGU_CHAR '*'
	ldr	r1,=AT91C_PIOA_CODR
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]
	LDELAY

	SPI_CHAR 0x0B						//MX25LXXX_CMD_FREAD
	SPI_CHAR 0x0
	SPI_CHAR 0x0
	SPI_CHAR 0x0
	SPI_CHAR 0x0

	ldr	r3,=START_ADDR
	ldr		r5,=__bss_start
	// 结束地址减去开始地址。
	sub		r5,r5,r3

130:
	ands r4, r5, #0x3f
	bne 140f
	SHOW_DBGU_CHAR '*'
140:
	SPI_CHAR 0x0
	strb r2,[r3], #1
	subs r5, r5, #1
	bne	130b
	ldr	r1,=AT91C_PIOA_SODR
	ldr	r2,=(AT91C_PIO_PA3)
	str	r2,[r1]
	SHOW_DBGU_CHAR '+'
150:
.endm

#ifdef CYGPKG_DEVS_FLASH_SPI_MX25LXXX
#define LOAD_DATAFLASH		LOAD_MP25_DATAFLASH
#else
#define LOAD_DATAFLASH		LOAD_ATMEL_DATAFLASH
#endif

#endif // CYGONCE_HELPER_SPIBOOT_H
