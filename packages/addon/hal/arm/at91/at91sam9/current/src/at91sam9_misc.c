/*==========================================================================
//
//      at91sam7s_misc.c
//
//      HAL misc board support code for Atmel AT91sam7s
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
// Author(s):    Owen Kirby
// Contributors: gthomas, jskov, nickg, tkoeller, Oliver Munz, Andrew Lunn
// Date:         2009-11-12
// Purpose:      HAL board support
// Description:  Implementations of HAL board interfaces. Copied from
//               blatantly from at91sam7s_misc.c
//
//####DESCRIPTIONEND####
//
//========================================================================*/

#include <pkgconf/system.h>
#include <pkgconf/hal.h>

#include <cyg/infra/cyg_type.h>         // base types
#include <cyg/infra/cyg_trac.h>         // tracing macros
#include <cyg/infra/cyg_ass.h>          // assertion macros

#include <cyg/hal/hal_io.h>             // IO macros
#include <cyg/hal/hal_arch.h>           // Register state info
#include <cyg/hal/hal_diag.h>
#include <cyg/hal/hal_intr.h>           // necessary?
#include <cyg/hal/hal_cache.h>
#include <cyg/hal/hal_if.h>             // calling interface
#include <cyg/hal/hal_misc.h>           // helper functions
#ifdef CYGDBG_HAL_DEBUG_GDB_BREAK_SUPPORT
#include <cyg/hal/drv_api.h>            // HAL ISR support
#endif

#include <cyg/hal/hal_mmu.h>
#include <cyg/hal/var_mmu.h>

#if 0
// -------------------------------------------------------------------------
// MMU init
#define AT91SAM9_SDRAM_PHYS_BASE 0x20000000u

void
hal_mmu_init(void)
{
    unsigned long ttb_base = 0x300000; // SRAM1
    unsigned long i;

    // Set the TTB register
    asm volatile ("mcr  p15,0,%0,c2,c0,0" : : "r"(ttb_base) /*:*/);
    // Set the Domain Access Control Register
    i = ARC_ARM_ACCESS_TYPE_MANAGER(0)    |
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

    // First clear all TT entries - ie Set them to Faulting
    memset((void *)ttb_base, 0, ARC_ARM_FIRST_LEVEL_PAGE_TABLE_SIZE);
    //                    Actual  Virtual  Size   Attributes                                                                Function
    //	                  Base     Base     MB        cached?              buffered?        access permissions
    //                  xxx00000  xxx00000
    ARC_X_ARM_MMU_SECTION(0x0,    0x0,       1,  ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW); // Internal SRAM0
    ARC_X_ARM_MMU_SECTION(0x003,  0x003,     1,  ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW); // Internal SRAM1
    ARC_X_ARM_MMU_SECTION(0x100,  0x100,     4,  ARC_ARM_CACHEABLE,   ARC_ARM_BUFFERABLE,   ARC_ARM_ACCESS_PERM_RW_RW); // NOR FLASH on CS0
    ARC_X_ARM_MMU_SECTION(0x100,  0x900,     4,  ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW); // NOR FLASH on CS0
    ARC_X_ARM_MMU_SECTION(0x200,  0x200,    16,  ARC_ARM_CACHEABLE,   ARC_ARM_BUFFERABLE,   ARC_ARM_ACCESS_PERM_RW_RW); // SDRAM on CS1
    ARC_X_ARM_MMU_SECTION(0x200,  0xA00,    16,  ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW); // SDRAM on CS1
    ARC_X_ARM_MMU_SECTION(0xF00,  0xF00,   256,  ARC_ARM_UNCACHEABLE, ARC_ARM_UNBUFFERABLE, ARC_ARM_ACCESS_PERM_RW_RW); // Internal Peripherals
}
#endif

// -------------------------------------------------------------------------
// Helper functions

// Calculate the baud value to be programmed into the serial port baud
// rate generators. This function will determine what the clock speed
// is that is driving the generator so it can be used in situations
// when the application dynamically changes the clock speed.
cyg_uint32
hal_at91_us_baud(cyg_uint32 baud_rate)
{
  cyg_uint32 val, pll;
  cyg_uint32 main_clock = 0;
  cyg_uint32 baud_value = 0;

  HAL_READ_UINT32((AT91_PMC+AT91_PMC_MCKR), val);
  switch (val & 0x03) {
    /* Slow clock */
    case AT91_PMC_MCKR_SLOW_CLK:
      main_clock = CYGNUM_HAL_ARM_AT91_SLOW_CLOCK;
      break;

      /* Main clock */
    case AT91_PMC_MCKR_MAIN_CLK:
      main_clock = CYGNUM_HAL_ARM_AT91_CLOCK_OSC_MAIN;
      break;
      /* PLLA */
    case AT91_PMC_MCKR_PLLA_CLK:
      HAL_READ_UINT32((AT91_PMC+AT91_PMC_PLLRA), pll);
      main_clock = CYGNUM_HAL_ARM_AT91_CLOCK_OSC_MAIN *
        (((pll & 0x7FF0000) >> 16) + 1) / (pll & 0xFF);
      break;
  }

  // Process prescale
  val = ((val & 0x1C) >> 2) + ((val & 0x300) >> 8);
  main_clock = main_clock >> val;

  /* Define the baud rate divisor register, (round) */
  baud_value = (main_clock/(8*baud_rate)+1)/2;

  return baud_value;
}


//==========================================================================
// When compiling C++ code with static objects the compiler
// inserts a call to __cxa_atexit() with __dso_handle as one of the
// arguments. __cxa_atexit() would normally be provided by glibc, and
// __dso_handle is part of crtstuff.c. eCos applications
// are linked rather differently, so either a differently-configured
// compiler is needed or dummy versions of these symbols should be
// provided. If these symbols are not actually used then providing
// them is still harmless, linker garbage collection will remove them.

void
__cxa_atexit(void (*arg1)(void*), void* arg2, void* arg3)
{
}

void*   __dso_handle = (void*) &__dso_handle;

//--------------------------------------------------------------------------
// EOF at91sam9_misc.c
