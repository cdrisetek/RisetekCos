/*==========================================================================
//
//      at91sam9260ek_mmu.c
//
//      HAL board support code for Atmel AT91SAM9260-EK board.
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
#include <string.h>
#include <cyg/hal/hal_io.h>
#include <cyg/hal/hal_mmu.h>
#include <cyg/hal/var_mmu.h>

// -------------------------------------------------------------------------
// MMU init

#define AT91SAM9_SDRAM_PHYS_BASE 0x20000000u

extern int __ram_data_start;

void
hal_mmu_init(void)
{
    unsigned long ttb_base = AT91SAM9_SDRAM_PHYS_BASE; // 0x20000000
    unsigned long fine_table = 0x200000;               // SRAM0
    unsigned long page_table = 0x300000;               // SRAM1
    unsigned long vector_table = page_table + ARC_ARM_SECOND_LEVEL_PAGE_TABLE_SIZE; // 0x300400
    unsigned long sram_end = vector_table + ARC_ARM_TINY_PAGE_SIZE;                 // 0x300800
    unsigned long i;

    // Set the TTB register
    asm volatile ("mcr  p15,0,%0,c2,c0,0" : : "r"(ttb_base) /*:*/);
    // Set the Domain Access Control Register
    i = ARC_ARM_ACCESS_TYPE_CLIENT(0)    |
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
    asm volatile ("mcr  p15,0,%0,c3,c0,0" : : "r"(i) /*:*/);

    // Set High Exception vectors / enable ROM Protection
    asm volatile ("mrc  p15,0,%0,c1,c0,0;" : "=r"(i) );
    i &= ~0x100; // clear S
    i |= 0x2200; // set V+R
    asm volatile ("mcr  p15,0,%0,c1,c0,0" : : "r"(i));

    // First clear all TT entries - ie Set them to Faulting
    memset((void *)ttb_base, 0, ARC_ARM_FIRST_LEVEL_PAGE_TABLE_SIZE);
    memset((void *)fine_table, 0, ARC_ARM_SECOND_LEVEL_FINE_TABLE_SIZE);
    memset((void *)page_table, 0, sram_end - page_table);

    //                    Actual  Virtual  Size   Attributes                                                                Function
    //	                  Base     Base     MB        cached?              buffered?        access permissions
    //                  xxx00000  xxx00000
    ARC_X_ARM_MMU_PAGE_TABLE(0x20000000,   0x20000000, (unsigned)&__ram_data_start, 0x24000000, page_table, ARC_ARM_CACHEABLE, ARC_ARM_BUFFERABLE, ARC_ARM_ACCESS_PERM_RO_RO, ARC_ARM_ACCESS_PERM_RW_RW); // cached RAM
    ARC_X_ARM_MMU_SECTION(0x200,  0xB00,   64,  ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW); // uncached RAM
    ARC_X_ARM_MMU_FINE_TABLE(0xFFFA0000,   0xFFFA0000, 0xFFFE4000, fine_table, ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW); // Internal Peripherals
    ARC_X_ARM_MMU_FINE_TABLE(vector_table, 0xFFFF0000, 0xFFFF0400, fine_table, ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW); // High exception Vector table
    ARC_X_ARM_MMU_FINE_TABLE(0xFFFFE800,   0xFFFFE800, 0x00000000, fine_table, ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW); // System Controller
}

//--------------------------------------------------------------------------
// EOF at91sam9260ek_mmu.c
