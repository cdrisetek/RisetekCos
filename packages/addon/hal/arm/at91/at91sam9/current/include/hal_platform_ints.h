#ifndef CYGONCE_HAL_PLATFORM_INTS_H
#define CYGONCE_HAL_PLATFORM_INTS_H
//==========================================================================
//
//      hal_platform_ints.h
//
//      HAL Interrupt and clock assignments for AT91SAM7
//
//==========================================================================
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
//==========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):    gthomas
// Contributors: gthomas, Oliver Munz, Andrew Lunn, John Eigelaar
// Date:         2001-07-12
// Purpose:      Define Interrupt support
// Description:  The interrupt specifics for the AT91SAM9 platform are
//               defined here.
//
// Usage:        #include <cyg/hal/hal_platform_ints.h>
//               ...
//
//
//####DESCRIPTIONEND####
//
//==========================================================================

#include <pkgconf/hal_arm_at91sam9.h>

#define CYGNUM_HAL_INTERRUPT_FIQ        0
#define CYGNUM_HAL_INTERRUPT_SYS        1

#if   defined(CYGHWR_HAL_ARM_AT91SAM9_at91sam9260)
#define CYGNUM_HAL_INTERRUPT_PIOA        2  /** Parallel IO Controller A */
#define CYGNUM_HAL_INTERRUPT_PIOB        3  /** Parallel IO Controller B */
#define CYGNUM_HAL_INTERRUPT_PIOC        4  /** Parallel IO Controller C */
#define CYGNUM_HAL_INTERRUPT_ADC         5  /** Analog Digital Converter */
#define CYGNUM_HAL_INTERRUPT_USART0      6  /** USART 0 */
#define CYGNUM_HAL_INTERRUPT_USART1      7  /** USART 1 */
#define CYGNUM_HAL_INTERRUPT_USART2      8  /** USART 2 */
#define CYGNUM_HAL_INTERRUPT_MCI         9  /** Multimedia Card Interface */
#define CYGNUM_HAL_INTERRUPT_UDP        10  /** USB Device Port */
#define CYGNUM_HAL_INTERRUPT_TWI        11  /** TWI */
#define CYGNUM_HAL_INTERRUPT_SPI        12  /** Serial Peripheral Interface 0 */
#define CYGNUM_HAL_INTERRUPT_SPI1       13  /** Serial Peripheral Interface 1 */
#define CYGNUM_HAL_INTERRUPT_SSC        14  /** Serial Synchronous Controller */
#define CYGNUM_HAL_INTERRUPT_TC0        17  /** Timer Counter 0 */
#define CYGNUM_HAL_INTERRUPT_TC1        18  /** Timer Counter 1 */
#define CYGNUM_HAL_INTERRUPT_TC2        19  /** Timer Counter 2 */
#define CYGNUM_HAL_INTERRUPT_UHP        20  /** USB Host Port */
#define CYGNUM_HAL_INTERRUPT_EMAC       21  /** Ethernet MAC */
#define CYGNUM_HAL_INTERRUPT_USART3     23  /** USART 3 */
#define CYGNUM_HAL_INTERRUPT_USART4     24  /** USART 4 */
#define CYGNUM_HAL_INTERRUPT_USART5     25  /** USART 5 */
#define CYGNUM_HAL_INTERRUPT_TC3        26  /** Timer Counter 3 */
#define CYGNUM_HAL_INTERRUPT_TC4        27  /** Timer Counter 4 */
#define CYGNUM_HAL_INTERRUPT_TC5        28  /** Timer Counter 5 */
#define CYGNUM_HAL_INTERRUPT_IRQ0       29  /** Advanced Interrupt Controller (IRQ0) */
#define CYGNUM_HAL_INTERRUPT_IRQ1       30  /** Advanced Interrupt Controller (IRQ1) */
#define CYGNUM_HAL_INTERRUPT_IRQ2       31  /** Advanced Interrupt Controller (IRQ2) */

// Interrupts which are multiplexed on to the System Interrupt
//#define CYGNUM_HAL_INTERRUPT_SDRAMC     32
#define CYGNUM_HAL_INTERRUPT_PITC       33
#define CYGNUM_HAL_INTERRUPT_RTTC       34
//#define CYGNUM_HAL_INTERRUPT_PMC        35
#define CYGNUM_HAL_INTERRUPT_WDTC       36
//#define CYGNUM_HAL_INTERRUPT_RSTC       37
#define CYGNUM_HAL_INTERRUPT_DBG        38

#elif defined(CYGHWR_HAL_ARM_AT91SAM9_at91sam9g20)
#define CYGNUM_HAL_INTERRUPT_PIOA       2
#define CYGNUM_HAL_INTERRUPT_PIOB       3
#define CYGNUM_HAL_INTERRUPT_PIOC       4
#define CYGNUM_HAL_INTERRUPT_ADC        5
#define CYGNUM_HAL_INTERRUPT_USART0     6
#define CYGNUM_HAL_INTERRUPT_USART1     7
#define CYGNUM_HAL_INTERRUPT_USART2     8
#define CYGNUM_HAL_INTERRUPT_MCI        9
#define CYGNUM_HAL_INTERRUPT_UDP        10
#define CYGNUM_HAL_INTERRUPT_TWI        11
#define CYGNUM_HAL_INTERRUPT_SPI        12
#define CYGNUM_HAL_INTERRUPT_SPI1       13
#define CYGNUM_HAL_INTERRUPT_SSC        14

#define CYGNUM_HAL_INTERRUPT_TC0        17
#define CYGNUM_HAL_INTERRUPT_TC1        18
#define CYGNUM_HAL_INTERRUPT_TC2        19
#define CYGNUM_HAL_INTERRUPT_UHP        20
#define CYGNUM_HAL_INTERRUPT_EMAC       21
#define CYGNUM_HAL_INTERRUPT_ISI        22
#define CYGNUM_HAL_INTERRUPT_USART3     23
#define CYGNUM_HAL_INTERRUPT_USART4     24
#define CYGNUM_HAL_INTERRUPT_USART5     25
#define CYGNUM_HAL_INTERRUPT_TC3        26
#define CYGNUM_HAL_INTERRUPT_TC4        27
#define CYGNUM_HAL_INTERRUPT_TC5        28
#define CYGNUM_HAL_INTERRUPT_IRQ0       29
#define CYGNUM_HAL_INTERRUPT_IRQ1       30
#define CYGNUM_HAL_INTERRUPT_IRQ2       31

// Interrupts which are multiplexed on to the System Interrupt
//#define CYGNUM_HAL_INTERRUPT_SDRAMC     32
#define CYGNUM_HAL_INTERRUPT_PITC       33
#define CYGNUM_HAL_INTERRUPT_RTTC       34
//#define CYGNUM_HAL_INTERRUPT_PMC        35
#define CYGNUM_HAL_INTERRUPT_WDTC       36
//#define CYGNUM_HAL_INTERRUPT_RSTC       37
#define CYGNUM_HAL_INTERRUPT_DBG        38

#elif defined(CYGHWR_HAL_ARM_AT91SAM9_at91sam9g45)
#define CYGNUM_HAL_INTERRUPT_PIOA        2  /** Parallel IO Controller A */
#define CYGNUM_HAL_INTERRUPT_PIOB        3  /** Parallel IO Controller B */
#define CYGNUM_HAL_INTERRUPT_PIOC        4  /** Parallel IO Controller C */
#define CYGNUM_HAL_INTERRUPT_PIOD_E      5  /** Parallel IO Controller D and E */
#define CYGNUM_HAL_INTERRUPT_TRNG        6  /** True Random Number Generator */
#define CYGNUM_HAL_INTERRUPT_USART0      7  /** USART 0 */
#define CYGNUM_HAL_INTERRUPT_USART1      8  /** USART 1 */
#define CYGNUM_HAL_INTERRUPT_USART2      9  /** USART 2 */
#define CYGNUM_HAL_INTERRUPT_USART3     10  /** USART 3 */
#define CYGNUM_HAL_INTERRUPT_MCI0       11  /** Multimedia Card Interface 0 */
#define CYGNUM_HAL_INTERRUPT_TWI0       12  /** TWI 0 */
#define CYGNUM_HAL_INTERRUPT_TWI1       13  /** TWI 1 */
#define CYGNUM_HAL_INTERRUPT_SPI        14  /** Serial Peripheral Interface */
#define CYGNUM_HAL_INTERRUPT_SPI1       15  /** Serial Peripheral Interface */
#define CYGNUM_HAL_INTERRUPT_SSC0       16  /** Serial Synchronous Controller 0 */
#define CYGNUM_HAL_INTERRUPT_SSC1       17  /** Serial Synchronous Controller 1 */
#define CYGNUM_HAL_INTERRUPT_TC0        18  /** Timer Counter 0, 1, 2, 3, 4, 5 */
#define CYGNUM_HAL_INTERRUPT_PWMC       19  /** Pulse Width Modulation Controller */
#define CYGNUM_HAL_INTERRUPT_TSADC      20  /** Touch Screen Controller */
#define CYGNUM_HAL_INTERRUPT_HDMA       21  /** HDMA */
#define CYGNUM_HAL_INTERRUPT_UHPHS      22  /** USB Host High Speed */
#define CYGNUM_HAL_INTERRUPT_LCDC       23  /** LCD Controller */
#define CYGNUM_HAL_INTERRUPT_AC97C      24  /** AC97 Controller */
#define CYGNUM_HAL_INTERRUPT_EMAC       25  /** Ethernet MAC */
#define CYGNUM_HAL_INTERRUPT_ISI        26  /** Image Sensor Interface */
#define CYGNUM_HAL_INTERRUPT_UDPHS      27  /** USB Device HS */
#define CYGNUM_HAL_INTERRUPT_MCI1       29  /** Multimedia Card Interface 1 */
#define CYGNUM_HAL_INTERRUPT_IRQ0       31  /** Advanced Interrupt Controller (IRQ0) */

// Interrupts which are multiplexed on to the System Interrupt
#define CYGNUM_HAL_INTERRUPT_PITC       33
#define CYGNUM_HAL_INTERRUPT_RTTC       34
//#define CYGNUM_HAL_INTERRUPT_PMC        35
#define CYGNUM_HAL_INTERRUPT_WDTC       36
//#define CYGNUM_HAL_INTERRUPT_RSTC       37
#define CYGNUM_HAL_INTERRUPT_DBG        38

#else // Something unknown
#error Unknown AT91 variant
#endif

#define CYGNUM_HAL_ISR_MIN              0
#define CYGNUM_HAL_ISR_MAX              38

#define CYGNUM_HAL_ISR_COUNT            (CYGNUM_HAL_ISR_MAX + 1)

// The vector used by the Real time clock
#ifdef CYGBLD_HAL_ARM_AT91_TIMER_TC
#define CYGNUM_HAL_INTERRUPT_RTC        CYGNUM_HAL_INTERRUPT_TC0
#endif
#ifdef CYGBLD_HAL_ARM_AT91_TIMER_PIT
#define CYGNUM_HAL_INTERRUPT_RTC        CYGNUM_HAL_INTERRUPT_PITC
#endif

//----------------------------------------------------------------------------
// Reset.
__externC void hal_at91_reset_cpu(void);
#define HAL_PLATFORM_RESET() hal_at91_reset_cpu()

#define HAL_PLATFORM_RESET_ENTRY 0x0000000

#endif // CYGONCE_HAL_PLATFORM_INTS_H
