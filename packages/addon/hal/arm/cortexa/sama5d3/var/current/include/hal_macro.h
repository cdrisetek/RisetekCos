#ifndef CYGONCE_HAL_MACRO_H
#define CYGONCE_HAL_MACRO_H
#include <cyg/hal/helper_nand_boot.h>
#include <cyg/hal/helper_spi_boot.h>
#include <cyg/hal/helper_sdram_init.h>

#define CYGNUM_HAL_ARM_VECTOR_0x14 4096

// Show HEX Value in R10 (R9 R10 R11 R12 used)
.macro BOOT_SHOW_REG_CHARS
		ldr	r9,=28
		ldr	r11, =AT91_DBG
2:
		ldr	r12,[r11, #AT91_DBG_CSR]
		ands	r12,r12,#AT91_DBG_CSR_TXRDY
		beq	2b
		mov r12,r10, LSR r9
		and r12,r12,#0xf
		cmp r12,#10
		blt	3f
		add r12,#7
3:
		add	r12,#48
		str r12,[r11, #AT91_DBG_THR]
		subs r9,r9,#4
		bcs 2b
.endm

// TODO: FIXME: when we select DBGU as console, so following is ready,
// but when we select another serial port as console, what to do?
.macro BOOT_SHOW_DBGU_CHAR x
		ldr	r11, =AT91_DBG
1:
		ldr	r12,[r11, #AT91_DBG_CSR]
		ands	r12,r12,#AT91_DBG_CSR_TXRDY
		beq	1b
		ldr	r12, =\x
		str	r12,[r11, #AT91_DBG_THR]
.endm

.macro LDELAY
	ldr	r11, =0x1ff
1:
	subs r11,r11,#1
	bne	1b
.endm

// SPI0
.macro SPI_CHAR x
	ldr r1,=AT91_SPI
	ldr	r2,=\x
	str	r2,[r1, #AT91_SPI_TDR]
1:
	ldr	r2,[r1, #AT91_SPI_SR]
	ands r2, r2, #AT91_SPI_SR_RDRF
	beq	1b
	ldr	r2,[r1, #AT91_SPI_RDR]
.endm


// Macro to initialise the EBI interface
.macro _EBI_init
__EBI_init__:
		ldr	r1, =AT91C_CCFG_EBICSA
		ldr	r2, =EBI_CSA_CONFIG
		str		r2,[r1]
		// 初始化 NAND FLASH 接口
		ldr		r1,=AT91C_SMC_SETUP3
		ldr		r2,=(AT91C_SM_NWE_SETUP3 | AT91C_SM_NCS_WR_SETUP3 | AT91C_SM_NRD_SETUP3 | AT91C_SM_NCS_RD_SETUP3)
		str		r2,[r1]

		ldr		r1,=AT91C_SMC_PULSE3
		ldr		r2,=(AT91C_SM_NCS_RD_PULSE3 | AT91C_SM_NRD_PULSE3 | AT91C_SM_NCS_WR_PULSE3 | AT91C_SM_NWE_PULSE3)
		str		r2,[r1]

		ldr		r1,=AT91C_SMC_CYCLE3
		ldr		r2,=(AT91C_SM_NWE_CYCLE3 | AT91C_SM_NRD_CYCLE3)
		str		r2,[r1]

		ldr		r1,=AT91C_SMC_CTRL3
		ldr		r2,=(AT91C_SMC_READMODE | AT91C_SMC_WRITEMODE | AT91C_SMC_NWAITM_NWAIT_DISABLE | AT91C_SMC_DBW_WIDTH_EIGTH_BITS | AT91C_SMC_TDF_2)
		str		r2,[r1]

		// NAND FLASH 使用了PC13 PC14
		ldr		r1,=AT91C_PIOC_PER
		ldr		r2,=( AT91C_PIO_PC13| AT91C_PIO_PC14)
		str		r2,[r1]
		ldr		r1,=AT91C_PIOC_OER
		ldr		r2,=AT91C_PIO_PC14
		str		r2,[r1]
		// PC14 为 NANDFLASH CE信号，先关闭。
		ldr	r1,=AT91C_PIOC_SODR
		ldr	r2,=AT91C_PIO_PC14
		str	r2,[r1]

		ldr		r1,=AT91C_PIOC_IFER
		ldr		r2,=AT91C_PIO_PC13
		str		r2,[r1]
#if		( CYGHWR_CPLD_HW > 0)
		ldr		r1,=AT91C_SMC_SETUP0
		ldr		r2,=(AT91C_SM_NWE_SETUP0 | AT91C_SM_NCS_WR_SETUP0 | AT91C_SM_NRD_SETUP0 | AT91C_SM_NCS_RD_SETUP0)
		str		r2,[r1]

		ldr		r1,=AT91C_SMC_CYCLE0
		ldr		r2,=(AT91C_SM_NWE_CYCLE0 | AT91C_SM_NRD_CYCLE0 )
		str		r2,[r1]

		ldr		r1,=AT91C_SMC_PULSE0
		ldr		r2,=(AT91C_SM_NWE_PULSE0 | AT91C_SM_NCS_WR_PULSE0 | AT91C_SM_NRD_PULSE0 | AT91C_SM_NCS_RD_PULSE0)
		str		r2,[r1]

		ldr		r1,=AT91C_SMC_CTRL0
		ldr		r2,=(AT91C_SMC_NWAITM_NWAIT_DISABLE | AT91C_SMC_DBW_WIDTH_EIGTH_BITS )
		str		r2,[r1]
#endif
.endm


// Flush and disable the caches
.macro _disable_cache
// Flush the entire dcache (and then both TLBs, just in case)
        mov     r0, #0
        mcr     p15,0,r0,c7,c6,0
        mcr     p15,0,r0,c8,c7,0

// Disable and clear caches
        mrc     p15,0,r0,c1,c0,0
        bic     r0,r0,#0x1000           // disable ICache
        bic     r0,r0,#0x0007           // disable DCache,
                                        // MMU and alignment faults
        mcr     p15,0,r0,c1,c0,0
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov     r0, #0
        mcr     p15,0,r0,c7,c6,0        // clear data cache
        mcr     p15,0,r0,c7,c5,0        // clear instruction cache

		/*
		 * disable MMU stuff and caches
		 */
		mrc	MMU_CP, 0, r0, MMU_Control, c0, 0
		bic	r0, r0, #0x00003300	/* clear bits 13:12, 9:8 (--VI- --RS) */
		bic	r0, r0, #0x00000087	/* clear bits 7, 2:0 (B--- -CAM) */
		orr	r0, r0, #0x00000002	/* set bit 2 (A) Align */
		mcr	MMU_CP, 0, r0, MMU_Control, c0, 0

		nop
		nop
		nop
		nop
		nop
		nop
		/*
		 * flush v4 I/D caches
		 */
		mov	r0, #0
		mcr	MMU_CP, 0, r0, c7, c7, 0	/* flush v3/v4 cache */
		mcr MMU_CP,0,r1,c7,c10,4 /* Drain Write Buffer */
		mcr	MMU_CP, 0, r0, c8, c7, 0	/* flush v4 TLB */
.endm

.macro  _turnon_mmu
	/*
	 * flush v4 I/D caches
	 */
	mov	r0, #0
	mcr	MMU_CP, 0, r0, c7, c7, 0	/* flush v3/v4 cache */
	mcr MMU_CP, 0, r1, c7, c10,4 /* Drain Write Buffer */
	mcr	MMU_CP, 0, r0, c8, c7, 0	/* flush v4 TLB */

	// Enable MMU
	mrc		MMU_CP,0,r1,MMU_Control,c0,0
	ldr		r0,=(MMU_Control_Init | MMU_Control_M | MMU_Control_A | MMU_Control_I | MMU_Control_C)
	orr		r1,r1,r0
//	ldr		r0,=(MMU_Control_S & MMU_Control_R)
//	bic		r1,r1,r0
	bic		r1,r1,#(MMU_Control_S & MMU_Control_R)
	mcr		MMU_CP,0,r1,MMU_Control,c0,0
    nop
	nop
	nop
	nop
	nop
.endm

.macro  _platform_setup2
        _disable_cache
        // Create MMU tables
        bl      hal_mmu_init
        _turnon_mmu
.endm

#ifdef	CYGOPT_HAL_PLL_DEFAULT
// AT91SAM9G20
#define DEFAULT_AT91SAM9G20_ICPLLA_VALUE		0
#define DEFAULT_AT91SAM9G20_PMC_MCKR_VALUE		( (1 << 12 ) | ((0x6 >> 1) << 8 )| AT91C_PMC_CSS_PLLA_CLK )
#define	DEFAULT_AT91SAM9G20_PLLA_VALUE			( ( 0x2 << 28 ) | (0x2a << 16) | (0x0 << 14) | (0x3f << 8) | 0x1 )		// Fin=18.432MHz 786,432000 MHz for PLLA
#define DEFAULT_AT91SAM9G20_PMC_MCK				( 786432000 / 6)

// AT91SAM9260
#define DEFAULT_AT91SAM9260_ICPLLA_VALUE		1
#define DEFAULT_AT91SAM9260_PMC_MCKR_VALUE		( (0 << 12 ) | ((0x2 >> 1) << 8 )| AT91C_PMC_CSS_PLLA_CLK )
#define	DEFAULT_AT91SAM9260_PLLA_VALUE			( ( 0x2 << 28 ) | (0x60 << 16) | (0x2 << 14) | (0x3f << 8) | 0x9 )		// Fin=18.432MHz 198656000 Hz for PLLA
#define DEFAULT_AT91SAM9260_PMC_MCK				( 198656000 / 2)
#endif

.macro	_AT91SAM9_PLL_DBGU_INIT
		b	CPUMODEL
		.align 4
		plla_value:				.word	AT91C_PLLA_VALUE
		pmc_mckr_value:			.word	PMC_MCKR_VALUE
		icplla_value:			.word	ICPLLA_VALUE
		pmc_mck:				.word	PMC_MCK
		DBGU_BRGR_VALUE:		.word	((PMC_MCK / ( CYGNUM_HAL_VIRTUAL_VECTOR_CONSOLE_CHANNEL_BAUD << 4)) + 1)
	CPUMODEL:
	// end of checkout CPU Model
		ldr     r0,=AT91_PMC
		ldr		r1,[r0,#AT91_PMC_PLLRA]
		ldr		r2,plla_value
		cmp		r1, r2
		bne		setPLL
	setPLL:
	/* PMC Clock Generator Main Oscillator Register,The Main Oscillator is enabled. */
		ldr		r1,icplla_value		// NOTE: TODO: Page 266, IPLL_PLLA should be 3
		str		r1,[r0,#AT91_PMC_PLLICPR]
		ldr		r1,plla_value
		str		r1,[r0,#AT91_PMC_PLLRA]
	checkPLLA:
		ldr		r1,[r0,#AT91_PMC_SR]
		ands	r1,r1,#AT91_PMC_SR_LOCKA
		beq		checkPLLA
		/* 写入PMC Master Clock Register值 */
		ldr		r1,pmc_mckr_value
		str		r1,[r0,#AT91_PMC_MCKR]
	checkMCKRDY2:
		ldr		r1,[r0,#AT91_PMC_SR]
		ands	r1,r1,#AT91_PMC_SR_MCKRDY
		beq		checkMCKRDY2
		/*时钟：*/
	PLLReady:
		ldr		r1,=~(AT91_PMC_SCER_PCK)
		str		r1,[r0,#AT91_PMC_SCDR]		/* 关闭除了处理器外的其它时钟。包括USB时钟和可编程外部时钟。 */
		ldr		r1,=(AT91_PMC_SCER_PCK | AT91_PMC_SCER_DDRCK)
		str		r1,[r0,#AT91_PMC_SCER]		/* 处理器和DDR时钟打开。 */
	// Init DBGU
		// Should open perical clock DBGU
		ldr		r1,=(AT91_PMC_PCER_DBGU)
		str		r1,[r0,#AT91_PMC_PCER]		/* OPEN CLOCK FOR DBGU */

		ldr	r1,	=AT91_PIOB
		// Control B
		ldr r2, =( (1 << (AT91_DBG_DRXD & 0xFF)) | ( 1 << (AT91_DBG_DTXD & 0xFF)))
		// Peripheral A
		ldr r3, [r1, #AT91_PIO_ABCDSR1]
		bic r3, r3, r2
		str	r3,	[r1, #AT91_PIO_ABCDSR1]
		ldr r3, [r1, #AT91_PIO_ABCDSR2]
 		bic r3, r3, r2
 		str	r3,	[r1, #AT91_PIO_ABCDSR2]
		ldr	r1,	=AT91C_PIOB_PDR
		str	r2,	[r1, #AT91_PIO_PDR]

		ldr	r1, =AT91_DBG	//AT91C_DBGU_CR
		ldr	r2, =(AT91_DBG_CR_RSTSTA|AT91_DBG_CR_TXEN|AT91_DBG_CR_RXEN)
		str	r2,[r1, #AT91_DBG_CR]
		ldr	r2, =(AT91_DBG_MR_CHMODE_NORMAL|AT91_DBG_MR_PAR_NONE)
		str	r2,[r1, #AT91_DBG_MR]
		ldr	r2, =((PMC_MCK / ( CYGNUM_HAL_VIRTUAL_VECTOR_CONSOLE_CHANNEL_BAUD << 4)) + 1)
		str	r2,[r1, #AT91_DBG_BRGR]
#ifdef	CYGPKG_HAL_BOOT_SPI
		ldr		r10,[r1, #AT91_DBG_C1R]
		SHOW_REG_CHARS
		BOOT_SHOW_DBGU_CHAR ' '
#endif
.endm
#endif	// CYGONCE_HAL_MACRO_H



