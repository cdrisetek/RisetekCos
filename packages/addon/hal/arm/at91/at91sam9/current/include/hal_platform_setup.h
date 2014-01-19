#ifndef CYGONCE_HAL_PLATFORM_SETUP_H
#define CYGONCE_HAL_PLATFORM_SETUP_H

/*=============================================================================
//
//      hal_platform_setup.h
//
//      Platform specific support for HAL
//
//=============================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 1998, 1999, 2000, 2001, 2002, 2006 Free Software Foundation, Inc.
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
//=============================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):   Owen Kirby
// Contributors:gthomas, asl
// Date:        2009-11-12
// Purpose:     AT91SAM9 platform specific support routines
// Description:
// Usage:       #include <cyg/hal/hal_platform_setup.h>
//
//####DESCRIPTIONEND####
//
//===========================================================================*/

#include <cyg/hal/var_io.h>
#include <cyg/hal/plf_io.h>
#include <cyg/hal/hal_mmu.h>

#ifdef CYGPKG_REDBOOT
#define PLATFORM_SETUP1
#else

// Flush and disable the caches
        .macro _disable_cache
__disable_cache:
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
        .endm

        .macro _setup
        _disable_cache
        ldr     sp,.__startup_stack
        bl      hal_mmu_init

        // Enable MMU
        ldr     r1, =1f
        mrc     MMU_CP,0,r0,MMU_Control,c0
        orr     r0, r0, #MMU_Control_M
        mcr     MMU_CP,0,r0,MMU_Control,c0
        mov     pc, r1                  // Change address spaces
        nop
        nop
        nop
        nop
        nop
1:
        // force init of SWI exception vector
        mov     r0, #(CPSR_IRQ_DISABLE|CPSR_FIQ_DISABLE|CPSR_UNDEF_MODE)
        msr     cpsr, r0
        .endm

#define PLATFORM_SETUP1 _setup
#endif

//-----------------------------------------------------------------------------
// end of hal_platform_setup.h
#endif // CYGONCE_HAL_PLATFORM_SETUP_H
