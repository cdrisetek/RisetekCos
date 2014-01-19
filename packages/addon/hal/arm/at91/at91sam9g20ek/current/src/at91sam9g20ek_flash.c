//==========================================================================
//
//      at91sam9g20ek_flash.c
//
//      Support for the flash devices on Atmel AT91SAM9G20-EK board.
//
//==========================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 2004, 2006, 2008 Free Software Foundation, Inc.
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
// Author(s):   danielh
// Date:        2010-01-01
//
//####DESCRIPTIONEND####
//=============================================================================

#include <pkgconf/system.h>
#ifdef CYGPKG_IO_FLASH
#include <cyg/io/spi_at91.h>
#include <cyg/io/dataflash.h>

// There is an Atmel 45DB642D-CNU dataflash on SPI bus 0, CS1.

__externC cyg_spi_at91_device_t spi_dataflash_dev0;

CYG_DATAFLASH_FLASH_DRIVER(hal_at91sam9g20ek_dataflash,
                           &spi_dataflash_dev0,
                           0xC0000000,                  // address
                           0,                           // start sector
                           -1                           // end sector (use all)
);

#endif  // CYGPKG_IO_FLASH

// EOF at91sam9g20ek_flash.c
