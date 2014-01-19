/*==========================================================================
//
//      at91sam9g20ek_misc.c
//
//      HAL misc board support code for Atmel AT91SAM9G20-EK board
//
//==========================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 2006 Free Software Foundation, Inc.
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
// Description:  Implementations of HAL board interfaces
//
//####DESCRIPTIONEND####
//
//========================================================================*/

#include <pkgconf/system.h>
#include <pkgconf/hal.h>
#include <pkgconf/io_serial_arm_at91.h>

#include <cyg/hal/hal_io.h>             // IO macros
#include <cyg/hal/hal_diag.h>

// -------------------------------------------------------------------------
// Hardware init

void
hal_plf_hardware_init (void)
{
#ifdef CYGPKG_DEVS_ETH_ARM_AT91
  cyg_uint32 rsr;
#endif

  /* Enable serial port pins and clocks if UARTS are used for debug output */
#if defined(CYGPKG_IO_SERIAL_ARM_AT91_SERIAL0)
  HAL_ARM_AT91_PIO_CFG(AT91_USART_RXD0);
  HAL_ARM_AT91_PIO_CFG(AT91_USART_TXD0);
  HAL_WRITE_UINT32(AT91_PMC+AT91_PMC_PCER, AT91_PMC_PCER_US0);
#endif
#if defined(CYGPKG_IO_SERIAL_ARM_AT91_SERIAL1)
  HAL_ARM_AT91_PIO_CFG(AT91_USART_RXD1);
  HAL_ARM_AT91_PIO_CFG(AT91_USART_TXD1);
  HAL_WRITE_UINT32(AT91_PMC+AT91_PMC_PCER, AT91_PMC_PCER_US1);
#endif
#if defined(CYGPKG_IO_SERIAL_ARM_AT91_SERIAL2)
  HAL_ARM_AT91_PIO_CFG(AT91_USART_RXD2);
  HAL_ARM_AT91_PIO_CFG(AT91_USART_TXD2);
  HAL_WRITE_UINT32(AT91_PMC+AT91_PMC_PCER, AT91_PMC_PCER_US2);
#endif
#if defined(CYGPKG_IO_SERIAL_ARM_AT91_SERIAL3)
  HAL_ARM_AT91_PIO_CFG(AT91_USART_RXD3);
  HAL_ARM_AT91_PIO_CFG(AT91_USART_TXD3);
  HAL_WRITE_UINT32(AT91_PMC+AT91_PMC_PCER, AT91_PMC_PCER_US3);
#endif
#if defined(CYGPKG_IO_SERIAL_ARM_AT91_SERIAL4)
  HAL_ARM_AT91_PIO_CFG(AT91_USART_RXD4);
  HAL_ARM_AT91_PIO_CFG(AT91_USART_TXD4);
  HAL_WRITE_UINT32(AT91_PMC+AT91_PMC_PCER, AT91_PMC_PCER_US4);
#endif
#if defined(CYGPKG_IO_SERIAL_ARM_AT91_SERIAL5)
  HAL_ARM_AT91_PIO_CFG(AT91_USART_RXD5);
  HAL_ARM_AT91_PIO_CFG(AT91_USART_TXD5);
  HAL_WRITE_UINT32(AT91_PMC+AT91_PMC_PCER, AT91_PMC_PCER_US5);
#endif

  /* Setup the Reset controller. Allow user resets */
  HAL_WRITE_UINT32(AT91_RST + AT91_RST_RMR,
                   AT91_RST_RMR_URSTEN | 10 << 8 | AT91_RST_RMR_KEY);

#ifdef CYGBLD_HAL_ARM_AT91_TIMER_TC
  /* Enable peripheral clocks for TC 0 and 2 if they are to be used */
  HAL_WRITE_UINT32(AT91_PMC+AT91_PMC_PCER,
                   AT91_PMC_PCER_TC0 | AT91_PMC_PCER_TC2);
#endif

  /* Initialize GPIOs */
  /* Configure IO pins for LEDS. */
  // Clear the user LED to off and set the power LED to on.
  // The logic is inverted for the user LED.
  HAL_ARM_AT91_GPIO_PUT(AT91_GPIO_PB8, 1);
  HAL_ARM_AT91_GPIO_PUT(AT91_GPIO_PB9, 1);
  HAL_ARM_AT91_GPIO_CFG_DIRECTION(AT91_GPIO_PB8, AT91_PIN_OUT);
  HAL_ARM_AT91_GPIO_CFG_DIRECTION(AT91_GPIO_PB9, AT91_PIN_OUT);
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_GPIO_PB8, AT91_PIN_PULLUP_DISABLE);
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_GPIO_PB9, AT91_PIN_PULLUP_DISABLE);

  /* Configure IO pins for push-button switches.*/
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_GPIO_PA30, AT91_PIN_PULLUP_ENABLE);
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_GPIO_PA31, AT91_PIN_PULLUP_ENABLE);
  HAL_ARM_AT91_GPIO_CFG_DIRECTION(AT91_GPIO_PA30, AT91_PIN_IN);
  HAL_ARM_AT91_GPIO_CFG_DIRECTION(AT91_GPIO_PA31, AT91_PIN_IN);

  /* Enable peripheral clock to PIOA and PIOB and PIOC. */
  HAL_WRITE_UINT32(AT91_PMC + AT91_PMC_PCER,
                   AT91_PMC_PCER_PIOA | AT91_PMC_PCER_PIOB | AT91_PMC_PCER_PIOC);

#ifndef CYGPKG_REDBOOT
#ifndef CYGPKG_IO_WATCHDOG
  /* Disable the watchdog. The eCos philosophy is that the watchdog is
     disabled unless the watchdog driver is used to enable it.
     Whoever if we disable it here we cannot re-enable it in the
     watchdog driver, hence the conditional compilation. */
  HAL_WRITE_UINT32(AT91_WDTC + AT91_WDTC_WDMR, AT91_WDTC_WDMR_DIS);
#endif
#endif

/* Perform some platform specific bits to get the Ethernet hardware
   setup. Specifically if a specific phy is used and does not start in
   the correct mode a function needs to be supplied as part of the plf
   to do the necessary initializations.
*/
#ifdef CYGPKG_DEVS_ETH_ARM_AT91
  /* PHYAD[0..4] */
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_EMAC_ERX0, AT91_PIN_PULLUP_DISABLE);
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_EMAC_ERX1, AT91_PIN_PULLUP_DISABLE);
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_EMAC_ERX2, AT91_PIN_PULLUP_DISABLE);
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_EMAC_ERX3, AT91_PIN_PULLUP_DISABLE);
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_EMAC_ECRS, AT91_PIN_PULLUP_DISABLE);
  /* TESTMODE, RPTR */
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_EMAC_ERXDV, AT91_PIN_PULLUP_DISABLE);
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_EMAC_ERXER, AT91_PIN_PULLUP_DISABLE);
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_EMAC_ERXCK, AT91_PIN_PULLUP_DISABLE);
  /* RMII */
  HAL_ARM_AT91_GPIO_CFG_PULLUP(AT91_EMAC_ECOL, AT91_PIN_PULLUP_DISABLE);
  /* trigger NRST */
  HAL_WRITE_UINT32(AT91_RST + AT91_RST_RCR, AT91_RST_RCR_EXTRST | AT91_RST_RCR_KEY);
  do {
    HAL_READ_UINT32(AT91_RST + AT91_RST_RSR, rsr);
  } while (!(rsr & AT91_RST_RSR_NRST_SET));
#endif
}

// -------------------------------------------------------------------------
// Helper functions

// The AT91SAM9G20-EK board has 2 LEDs attached to GPIOs.
static void
hal_at91sam9g20ek_led (int val)
{
  // Turn LEDs on or off.
  // The logic is inverted for the user LED.
  HAL_ARM_AT91_GPIO_PUT(AT91_GPIO_PB8, !(val & 1));
  HAL_ARM_AT91_GPIO_PUT(AT91_GPIO_PB9, val & 2);
}

void
hal_at91_set_leds(int val)
{
    hal_at91sam9g20ek_led(val);
}

// The AT92SAM9G20 board has 2 user push-buttons attached to GPIOs.
static cyg_uint32
hal_at91sam9g20_pushbutton(void)
{
  cyg_uint32 pb0, pb1;

  HAL_ARM_AT91_GPIO_GET(AT91_GPIO_PA30, pb0);
  HAL_ARM_AT91_GPIO_GET(AT91_GPIO_PA31, pb1);

  return (pb1 << 1) | pb0;
}

cyg_uint32
hal_at91_pushbutton(void)
{
  return hal_at91sam9g20_pushbutton();
}

//--------------------------------------------------------------------------
// EOF at91sam9g20ek_misc.c
