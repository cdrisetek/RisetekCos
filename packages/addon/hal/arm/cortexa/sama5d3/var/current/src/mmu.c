/*==========================================================================
//
//      mmu.c
//
//      HAL board support code for Atmel AT91SAM9260 board.
//
//==========================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003, 2006 Free Software Foundation, Inc.
//
// eCos is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 or (at your option) any later
// version.
//
// eCos is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License
// along with eCos; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
// As a special exception, if other files instantiate templates or use
// macros or inline functions from this file, or you compile this file
// and link it with other works to produce a work based on this file,
// this file does not by itself cause the resulting work to be covered by
// the GNU General Public License. However the source code for this file
// must still be made available in accordance with section (3) of the GNU
// General Public License v2.
//
// This exception does not invalidate any other reasons why a work based
// on this file might be covered by the GNU General Public License.
// -------------------------------------------
// ####ECOSGPLCOPYRIGHTEND####
//==========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):    danielh
// Date:         2010-01-01
// Purpose:      HAL board support
// Description:  MMU handling
//
//####DESCRIPTIONEND####
//
//========================================================================*/
#include <pkgconf/system.h>

#include <pkgconf/hal.h>
#include <cyg/hal/platform_cfg.h>
#include <string.h>
#include <cyg/hal/hal_io.h>
#include <cyg/hal/hal_mmu.h>
#include <cyg/hal/var_mmu.h>
#include <cyg/hal/hal_cache.h>
#include <cyg/hal/hal_sdramcfg.h>
#include <cyg/hal/hal_intr.h>

// -------------------------------------------------------------------------
// MMU init
extern int __ram_data_start;
#define SDRAM_PHYS_END			(AT91SAM9260_SDRAM_PHYS_BASE + AT91SAM9260_SDRAM_SIZE)
#define AT91SAM9260_SDRAM_SIZE_xMB		(AT91SAM9260_SDRAM_SIZE >> 20)
void hal_mmu_init(void)
{
	// Now we are in sdram space, we should checkout memory size configure
	// here we a without mmu enable
	cyg_uint32	cr_value;
	HAL_READ_UINT32(AT91C_SDRAMC_CR, cr_value);
	if( cr_value == SDRAMC_CR_VALUE_32X2 )
		hal_dram_size = 64;
	else if( cr_value == SDRAMC_CR_VALUE_32X2 )
		hal_dram_size = 32;
	else if( cr_value == SDRAMC_CR_VALUE_8X2 )
		hal_dram_size = 16;
	else if( cr_value == SDRAMC_CR_VALUE_8X1 )
		hal_dram_size = 8;
	else
		hal_dram_size = 0;

	hal_dram_size -=8;	// We leave the head.

    unsigned long ttb_base = AT91SAM9260_SDRAM_PHYS_BASE;
    unsigned long system_fine_table = ttb_base +  ARC_ARM_FIRST_LEVEL_PAGE_TABLE_SIZE;
    unsigned long fine_table = system_fine_table + ARC_ARM_SECOND_LEVEL_FINE_TABLE_SIZE;
    unsigned long vector_table = fine_table + ARC_ARM_SECOND_LEVEL_FINE_TABLE_SIZE;// 0x400; // 1K

    unsigned long sdram_vma_page_table = vector_table + 0x400;	// ARC_ARM_SECOND_LEVEL_PAGE_TABLE_SIZE;
    unsigned long sdram_lma_page_table = sdram_vma_page_table + ARC_ARM_SECOND_LEVEL_PAGE_TABLE_SIZE;
    unsigned long sdram_lma_high_page_table = sdram_lma_page_table + ARC_ARM_SECOND_LEVEL_PAGE_TABLE_SIZE;

    // First clear all TT entries - ie Set them to Faulting
    memset((void *)ttb_base, 0, MMU_TABLE_SIZE);

    // Memory layout after MMU is turned on
    //               Actual  Virtual  Size   Attributes                                                  Function
    //               Base     Base     MB     cached?          buffered?         access permissions
    //             xxx00000  xxx00000

#ifdef CYG_HAL_STARTUP_ROMRAM

    // MMU TABLE
    ARC_X_ARM_MMU_FINE_TABLE((AT91SAM9260_SDRAM_PHYS_BASE),(AT91SAM9260_SDRAM_PHYS_BASE), (AT91SAM9260_SDRAM_PHYS_BASE+MMU_TABLE_SIZE),
    		fine_table, ARC_ARM_CACHEABLE,	ARC_ARM_BUFFERABLE,	ARC_ARM_ACCESS_PERM_RO_RO);

    // REDBOOT
    ARC_X_ARM_MMU_FINE_TABLE((AT91SAM9260_SDRAM_PHYS_BASE+MMU_TABLE_SIZE),(AT91SAM9260_SDRAM_PHYS_BASE+MMU_TABLE_SIZE), (AT91SAM9260_SDRAM_PHYS_BASE+REDBOOT_SIZE),
    		fine_table, ARC_ARM_CACHEABLE,	ARC_ARM_UNBUFFERABLE,	ARC_ARM_ACCESS_PERM_RW_RW);

    // HEAP SPACE
    ARC_X_ARM_MMU_FINE_TABLE((AT91SAM9260_SDRAM_PHYS_BASE+REDBOOT_SIZE),(AT91SAM9260_SDRAM_PHYS_BASE+REDBOOT_SIZE), (SDRAM_PHYS_END),
    		fine_table, ARC_ARM_CACHEABLE,	ARC_ARM_BUFFERABLE,	ARC_ARM_ACCESS_PERM_RW_RW);

#else
    ARC_X_ARM_MMU_PAGE_TABLE(AT91SAM9260_SDRAM_PHYS_BASE, AT91SAM9260_SDRAM_PHYS_BASE, (AT91SAM9260_SDRAM_PHYS_BASE+MMU_TABLE_SIZE), (AT91SAM9260_SDRAM_PHYS_BASE+REDBOOT_SIZE),
    		sdram_lma_page_table, ARC_ARM_CACHEABLE, ARC_ARM_BUFFERABLE, ARC_ARM_ACCESS_PERM_RO_RO, ARC_ARM_ACCESS_PERM_RW_RW); // cached RAM

    unsigned long RAM_DATA_START = (unsigned long)&__ram_data_start;
    if( (RAM_DATA_START - AT91SAM9260_SDRAM_PHYS_BASE) < (0x100000)) {
    	// TODO: it is not finish.
        ARC_X_ARM_MMU_PAGE_TABLE((AT91SAM9260_SDRAM_PHYS_BASE+REDBOOT_SIZE), (AT91SAM9260_SDRAM_PHYS_BASE+REDBOOT_SIZE), RAM_DATA_START, (SDRAM_PHYS_END),
        		sdram_lma_page_table, ARC_ARM_CACHEABLE, ARC_ARM_BUFFERABLE, ARC_ARM_ACCESS_PERM_RO_RO, ARC_ARM_ACCESS_PERM_RW_RW); // cached RAM
        // TODO: DMA AREA

    } else {
        ARC_X_ARM_MMU_PAGE_TABLE((AT91SAM9260_SDRAM_PHYS_BASE+REDBOOT_SIZE), (AT91SAM9260_SDRAM_PHYS_BASE+REDBOOT_SIZE), (AT91SAM9260_SDRAM_PHYS_BASE+REDBOOT_SIZE), (RAM_DATA_START & 0xfff00000),
        		sdram_lma_page_table, ARC_ARM_CACHEABLE, ARC_ARM_BUFFERABLE, ARC_ARM_ACCESS_PERM_RO_RO, ARC_ARM_ACCESS_PERM_RO_RO); // First 1M

        ARC_X_ARM_MMU_PAGE_TABLE((RAM_DATA_START & 0xfff00000), (RAM_DATA_START & 0xfff00000), (RAM_DATA_START), (SDRAM_PHYS_END),
        		sdram_lma_high_page_table, ARC_ARM_CACHEABLE, ARC_ARM_BUFFERABLE, ARC_ARM_ACCESS_PERM_RO_RO, ARC_ARM_ACCESS_PERM_RW_RW); // Second 1M

    }
    // DMA
    ARC_X_ARM_MMU_PAGE_TABLE((RAM_DATA_START & 0xfff00000), ((RAM_DATA_START & 0xfff00000) + BUFFER2UNBUFFER_OFFSET ), (RAM_DATA_START+BUFFER2UNBUFFER_OFFSET), (SDRAM_PHYS_END+BUFFER2UNBUFFER_OFFSET),
    		sdram_vma_page_table, ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_NONE_NONE, ARC_ARM_ACCESS_PERM_RW_RW); // Second 1M

#endif
    // We configure extra memory space
    ARC_X_ARM_MMU_SECTION(((AT91SAM9260_SDRAM_PHYS_BASE >> 20) + AT91SAM9260_SDRAM_SIZE_xMB),  ((AT91SAM9260_SDRAM_PHYS_BASE >> 20) + AT91SAM9260_SDRAM_SIZE_xMB),
    		hal_dram_size,  ARC_ARM_CACHEABLE,   ARC_ARM_BUFFERABLE,   ARC_ARM_ACCESS_PERM_RW_RW);
    ARC_X_ARM_MMU_SECTION(((AT91SAM9260_SDRAM_PHYS_BASE >> 20) + AT91SAM9260_SDRAM_SIZE_xMB),  (((AT91SAM9260_SDRAM_PHYS_BASE+BUFFER2UNBUFFER_OFFSET) >> 20)+ AT91SAM9260_SDRAM_SIZE_xMB),
    		hal_dram_size,  ARC_ARM_UNCACHEABLE,   ARC_ARM_UNBUFFERABLE,   ARC_ARM_ACCESS_PERM_RW_RW);

#if	( CYGHWR_CPLD_HW > 0)
	ARC_X_ARM_MMU_SECTION((AT91C_EBI_CS0 >>20), (AT91C_EBI_CS0 >>20),   1,  ARC_ARM_UNCACHEABLE,   ARC_ARM_UNBUFFERABLE,   ARC_ARM_ACCESS_PERM_RW_RW); // EBI for CPLD
#endif
    // Notes: MVA address should within 1M space, so that we needs only one final_talbe. else we should provide another final_table for each.
#if 0	// It is not used.
	// SRAM0 and SRAM1
    // SRAM0 ( base: 0xFFF10000 )
	ARC_X_ARM_MMU_FINE_TABLE(AT91C_IRAM_1, SRAM1_MVA, (SRAM1_MVA + AT91C_IRAM_1_SIZE), system_fine_table, ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW);		// SRAM0 16K
    // SRAM1 ( base: 0xFFF20000 )
    ARC_X_ARM_MMU_FINE_TABLE(AT91C_IRAM_2, SRAM2_MVA, (SRAM2_MVA + AT91C_IRAM_2_SIZE), system_fine_table, ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW);
#endif

    // SRAM 0-1
    ARC_X_ARM_MMU_SECTION((AT91C_IRAM_1 >>20), (AT91C_IRAM_1 >>20),   1,  ARC_ARM_UNCACHEABLE,   ARC_ARM_UNBUFFERABLE,   ARC_ARM_ACCESS_PERM_RW_RW); // AT91C_IRAM_1 for ATMEL ETHERNET
    ARC_X_ARM_MMU_SECTION((AT91C_IRAM_2 >>20), (AT91C_IRAM_2 >>20),   1,  ARC_ARM_UNCACHEABLE,   ARC_ARM_UNBUFFERABLE,   ARC_ARM_ACCESS_PERM_RW_RW); // AT91C_IRAM_2 for ATMEL AT91SAM9G20 RESET Process

    // USB HOST REG 16K (base: 0xFFF30000)
    ARC_X_ARM_MMU_FINE_TABLE(AT91C_BASE_UHP, USBHOST_REG_MVA,	(USBHOST_REG_MVA + 0x4000),		system_fine_table,		ARC_ARM_UNCACHEABLE,	ARC_ARM_UNBUFFERABLE,	ARC_ARM_ACCESS_PERM_RW_RW);

    // NANDFLASH DATA
    ARC_X_ARM_MMU_FINE_TABLE(AT91C_EBI_CS3,   			NANDFLASH_DATA_MVA,	(NANDFLASH_ALE_MVA),	system_fine_table,	ARC_ARM_UNCACHEABLE,	ARC_ARM_UNBUFFERABLE,	ARC_ARM_ACCESS_PERM_RW_RW);
    // NANDFLASH ALE
    ARC_X_ARM_MMU_FINE_TABLE((AT91C_EBI_CS3 | (1<<21)),	NANDFLASH_ALE_MVA,	(NANDFLASH_CLE_MVA),	system_fine_table,	ARC_ARM_UNCACHEABLE,	ARC_ARM_UNBUFFERABLE,	ARC_ARM_ACCESS_PERM_RW_RW);		// NANDFLASH ALE
    // NANDFLASH CLE
    ARC_X_ARM_MMU_FINE_TABLE((AT91C_EBI_CS3 | (1<<22)),	NANDFLASH_CLE_MVA,	(NANDFLASH_CLE_MVA + ARC_ARM_TINY_PAGE_SIZE),	system_fine_table,	ARC_ARM_UNCACHEABLE,	ARC_ARM_UNBUFFERABLE,	ARC_ARM_ACCESS_PERM_RW_RW);		// NANDFLASH CLE

    //    ARC_X_ARM_MMU_SECTION(0xfff,  0xfff,	1,  ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW); // SFRs
    // Internal Peripherals
    ARC_X_ARM_MMU_FINE_TABLE(0xFFFA0000,   0xFFFA0000, 0xFFFE4000, system_fine_table, ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW);
    // System Controller
	ARC_X_ARM_MMU_FINE_TABLE(0xFFFFE800,   0xFFFFE800, 0x00000000, system_fine_table, ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW);

    // High exception Vector table (base:0xFFFF0000 length:0x400)
    ARC_X_ARM_MMU_FINE_TABLE(vector_table, INTERRUPT_VECTOR_MVA, (INTERRUPT_VECTOR_MVA+INTERRUPT_VECTOR_LENGTH), system_fine_table, ARC_ARM_CACHEABLE, ARC_ARM_BUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW);

    // Set the Domain Access Control Register
    unsigned long i =
    	ARC_ARM_ACCESS_TYPE_CLIENT(0)     |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(1)  |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(2)  |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(3)  |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(4)  |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(5)  |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(6)  |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(7)  |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(8)  |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(9)  |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(10) |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(11) |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(12) |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(13) |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(14) |
        ARC_ARM_ACCESS_TYPE_NO_ACCESS(15);

    // TODO: FIXME: why CYG_INTERWORKING_MACRO_START does not work?
    CYG_MACRO_START;
    // Set the TTB register
    asm volatile (
#ifdef	__thumb__
            "ldr     r1,=10f;"
            "bx      r1;"
            ".pool;"
            ".code   32;"
    		"10:;"
#endif // __thumb__
    		"mcr  p15,0,%0,c2,c0,0;"
    		"mcr  p15,0,%1,c3,c0,0;"
    		// Set High Exception vectors / enable ROM Protection
    		"mrc  p15,0,%1,c1,c0,0;"
    		// clear S
    		"bic  %1, %1, #0x100;"
    		// set V+R
    		"orr  %1, %1, #0x2200;"
    		"mcr  p15,0,%1,c1,c0,0;"
#ifdef	__thumb__
            "ldr     r1,=20f+1;"
            "bx      r1;"
            ".pool;"
            ".code   16;"
            ".thumb_func;"
    		"20:"
#endif // __thumb__
    		:: "r"(ttb_base), "r"(i) : "r1");
    CYG_MACRO_END;
}
//--------------------------------------------------------------------------
// EOF mmu.c
