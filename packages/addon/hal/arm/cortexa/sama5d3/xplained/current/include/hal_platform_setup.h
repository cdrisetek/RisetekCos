#ifndef CYGONCE_HAL_PLATFORM_SETUP_H
#define CYGONCE_HAL_PLATFORM_SETUP_H
//=============================================================================
//
//      hal_platform_setup.h
//
//      Riser������������
//
//=============================================================================
// Author(s):    ychun.w@gamil.com
// Date:         2012-12-05
// Usage:        #include <cyg/hal/hal_platform_setup.h>
//     Only used by "vectors.S"
//
//
//=============================================================================

#include <pkgconf/system.h>           // System-wide configuration info
#include CYGBLD_HAL_VARIANT_H         // Variant specific configuration
#include CYGBLD_HAL_PLATFORM_H        // Platform specific configuration
#include CYGHWR_MEMORY_LAYOUT_H
#include BOARD_CONFIG_H
#include <cyg/hal/hal_mmu.h>          // MMU definitions
#include <cyg/hal/at91sam9260.h>         // Platform specific hardware definitions
#include <cyg/hal/memcfg.h>           // Platform specific memory configuration
#include <cyg/hal/platform_cfg.h>
#include <cyg/hal/hal_sdramcfg.h>
#include <cyg/hal/hal_macro.h>


// Macro to initialise the EBI interface
#ifdef CYG_HAL_STARTUP_ROMRAM

#define PLATFORM_SETUP1 _platform_setup1

#define CYGHWR_HAL_ARM_HAS_MMU
#define CYGSEM_HAL_ROM_RESET_USES_JUMP
// This macro represents the initial startup code for the platform
        .macro  _platform_setup1

		mrs r1,cpsr
		bic r1,r1,#0x1F  /* Put processor in SVC mode */
		orr r1,r1,#0x13
		msr cpsr,r1
// Eanble PIT, It is useful for a random number general
		ldr		r1,=AT91C_PITC_PIMR
		ldr		r0, =(AT91C_PITC_PITEN | 0xfffff)
		str		r0,[r1]

   		 _disable_cache

		// �����ⲿ��λ�ź�
		ldr	r1, =AT91C_RSTC_RMR
		ldr	r2, =( AT91C_RSTC_KEY | AT91C_RSTC_ERSTL | AT91C_RSTC_URSTEN )
		str	r2,[r1]

		// ��ֹ�ж�
		ldr		r1,=AT91C_AIC_IDCR
		ldr		r2,=0xffffffff
		str		r2,[r1]

		// ���WATCHDOG
		// DISABLE WATCHDOG
#ifdef CYGNUM_HAL_ARM_AT91SAM9260_DISABLE_WATCHDOG
		ldr		r1,=AT91C_WDTC_WDMR
		ldr		r2,=AT91C_WDTC_WDDIS
		str		r2,[r1]
#endif
		// ����ȷ�� ���Ϊ �͡�
		ldr		r0,= AT91C_PIOB_CODR
		ldr		r1,=CONTROL_OUT_IO_B
		str		r1, [r0]
		// ��ȷ����Щ�˿��� IO �ڡ�
		ldr		r0,= AT91C_PIOB_PER
		ldr		r1,=CONTROL_OUT_IO_B
		str		r1, [r0]
		// ȷ���������
		ldr		r0,= AT91C_PIOB_OER
		ldr		r1,=CONTROL_OUT_IO_B
		str		r1, [r0]
		// ȷ����д
		ldr		r0,= AT91C_PIOB_OWER
		ldr		r1,=CONTROL_OUT_IO_B
		str		r1, [r0]
 //		RAW_LED_MACRO	0xff	// �����еĵƶ���

		_AT91SAM9_PLL_DBGU_INIT
		// ���������ڸ�ʱ�����ˡ�
		_EBI_init

		_SDRAMC_init

        // Set up a stack [for calling C code]
        ldr     r1,=__startup_stack
        ldr     r2,=AT91SAM9260_SDRAM_PHYS_BASE
        orr     sp,r1,r2

#ifdef	CYGPKG_HAL_ARM_ARM9_AT91SAM9260_BOOT_SPI
		LOAD_DATAFLASH
#else	// CYGPKG_HAL_ARM_ARM9_AT91SAM9260_BOOT_SPI
		LOAD_NAND
#endif // CYGPKG_HAL_ARM_ARM9_AT91SAM9260_BOOT_SPI

        ldr     r2,=10f
        mov     pc,r2    /* Change address spaces */

10:
        nop
        nop
        nop
		BOOT_SHOW_DBGU_CHAR ':'

#ifndef	NO_MMU
  		 _disable_cache

        // Create MMU tables
        bl      hal_mmu_init

        _turnon_mmu
#endif
		BOOT_SHOW_DBGU_CHAR ')'
		BOOT_SHOW_DBGU_CHAR '\r'
		BOOT_SHOW_DBGU_CHAR '\n'

		.endm

#else // defined(CYG_HAL_STARTUP_ROM) || defined(CYG_HAL_STARTUP_ROMRAM)
#define PLATFORM_SETUP1 _platform_setup2
#endif


//-----------------------------------------------------------------------------
// end of hal_platform_setup.h
#endif // CYGONCE_HAL_PLATFORM_SETUP_H