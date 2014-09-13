#ifndef CYGONCE_HAL_PIO_SAM9G45_H
#define CYGONCE_HAL_PIO_SAM9G45_H
//=============================================================================
//
//      pio_sam9g45.h
//
//      Variant specific registers
//
//=============================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003, 2005, 2006, 2009 Free Software Foundation, Inc.
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
// Author(s):   xxxxxx
// Contributors:
// Date:        2011-03-30
// Purpose:     AT91 variant specific registers
// Description:
// Usage:       #include <cyg/hal/var_io.h>
//
//####DESCRIPTIONEND####
//
//=============================================================================
// =============================================================================
// Key-change    Date       Author   Description
// --------------+----------+--------+------------------------------------------
// SAM9G45-0001  2011/04/15 AXONIM   Create file - Update address of peripherals
//
// =============================================================================
/* ----------------------------------------------------------------------------
 * PIN define
 *   #define AT91_PIN(_ctrl_, _periph_, _pin_)
 *      _ctrl_   : PIO Control
 *             0 : Control A      1 : Control B
 *             2 : Control C      3 : Control D
 *			   4 : Control E
 *      _periph_ : Peripheral
 *             0 : Peripheral A   1 : Peripheral B
 *      _pin_    : PIN index (0 -> 31)
 * ---------------------------------------------------------------------------*/
//*****************************************************************************
// CONTROL A
// PIO Controller A Peripheral A
#define AT91_MCCK           AT91_PIN(0, 0, 0) // Multimedia Card 0 Clock
#define AT91_MCCDA          AT91_PIN(0, 0, 1) // Multimedia Card 0 Command
#define AT91_MCDA0          AT91_PIN(0, 0, 2) // Multimedia Card 0 Data 0
#define AT91_MCDA1          AT91_PIN(0, 0, 3) // Multimedia Card 0 Data 1
#define AT91_MCDA2          AT91_PIN(0, 0, 4) // Multimedia Card 0 Data 2
#define AT91_MCDA3          AT91_PIN(0, 0, 5) // Multimedia Card 0 Data 3
#define AT91_MCDA4          AT91_PIN(0, 0, 6) // Multimedia Card 0 Data 4
#define AT91_MCDA5          AT91_PIN(0, 0, 7) // Multimedia Card 0 Data 5
#define AT91_MCDA6          AT91_PIN(0, 0, 8) // Multimedia Card 0 Data 6
#define AT91_MCDA7          AT91_PIN(0, 0, 9) // Multimedia Card 0 Data 7
#define AT91_EMAC_ETX0      AT91_PIN(0, 0, 10) // EMAC 0 Transmit Data 0
#define AT91_EMAC_ETX1      AT91_PIN(0, 0, 11) // EMAC 0 Transmit Data 1
#define AT91_EMAC_ERX0      AT91_PIN(0, 0, 12) // EMAC 0 Receive Data 0
#define AT91_EMAC_ERX1      AT91_PIN(0, 0, 13) // EMAC 0 Receive Data 1
#define AT91_EMAC_ETXEN     AT91_PIN(0, 0, 14) // EMAC 0 Transmit Enable
#define AT91_EMAC_ERXDV     AT91_PIN(0, 0, 15) // EMAC 0 Receive Data Valid
#define AT91_EMAC_ERXER     AT91_PIN(0, 0, 16) // EMAC 0 Receive Coding Error
#define AT91_EMAC_ETXCK     AT91_PIN(0, 0, 17) // EMAC 0 Transmit Clock
#define AT91_EMAC_EMDC      AT91_PIN(0, 0, 18) // EMAC 0 Management Data Clock
#define AT91_EMAC_EMDIO     AT91_PIN(0, 0, 19) // EMAC 0 Management Data IO
#define AT91_TWI0_TWD       AT91_PIN(0, 0, 20) // Two Wire 0 Data 
#define AT91_TWI0_TWCK      AT91_PIN(0, 0, 21) // Two Wire 0 Clock
#define AT91_MCI1_CDA       AT91_PIN(0, 0, 22) // Multimedia Card 1 Command
#define AT91_MCI1_DA0       AT91_PIN(0, 0, 23) // Multimedia Card 1 Data 0
#define AT91_MCI1_DA1       AT91_PIN(0, 0, 24) // Multimedia Card 1 Data 1
#define AT91_MCI1_DA2       AT91_PIN(0, 0, 25) // Multimedia Card 1 Data 2
#define AT91_MCI1_DA3       AT91_PIN(0, 0, 26) // Multimedia Card 1 Data 3
#define AT91_MCI1_DA4       AT91_PIN(0, 0, 27) // Multimedia Card 1 Data 4
#define AT91_MCI1_DA5       AT91_PIN(0, 0, 28) // Multimedia Card 1 Data 5
#define AT91_MCI1_DA6       AT91_PIN(0, 0, 29) // Multimedia Card 1 Data 6
#define AT91_MCI1_DA7       AT91_PIN(0, 0, 30) // Multimedia Card 1 Data 7
#define AT91_MCI1_CK        AT91_PIN(0, 0, 31) // Multimedia Card 1 Clock


//PIO Controller A Peripheral B
#define AT91_TC_TCLK3       AT91_PIN(0, 1, 0)  // Timer #3 clock
#define AT91_TC_TIOA3       AT91_PIN(0, 1, 1)  // Timer #3 signal A
#define AT91_TC_TIOB3       AT91_PIN(0, 1, 2)  // Timer #3 signal B
#define AT91_TC_TCLK4       AT91_PIN(0, 1, 3)  // Timer #4 clock
#define AT91_TC_TIOA4       AT91_PIN(0, 1, 4)  // Timer #4 signal A
#define AT91_TC_TIOB4       AT91_PIN(0, 1, 5)  // Timer #4 signal B
#define AT91_EMAC_ETX2      AT91_PIN(0, 1, 6)  // EMAC 0 Transmit Data 2
#define AT91_EMAC_ETX3      AT91_PIN(0, 1, 7)  // EMAC 0 Transmit Data 3
#define AT91_EMAC_ERX2      AT91_PIN(0, 1, 8)  // EMAC 0 Recieve Data 2
#define AT91_EMAC_ERX3      AT91_PIN(0, 1, 9)  // EMAC 0 Recieve Data 3
#define AT91_USART_RTS3     AT91_PIN(0, 1, 23) // Serial port #3 Ready To Send
#define AT91_USART_CTS3     AT91_PIN(0, 1, 24) // Serial port #3 Clear To Send
#define AT91_PWM_PWM3       AT91_PIN(0, 1, 25) // Pulse Width Modulation 3
#define AT91_TC_TIOB2       AT91_PIN(0, 1, 26) // Timer #2 signal B
#define AT91_EMAC_ETXER     AT91_PIN(0, 1, 27) // EMAC 0 Transmit error
#define AT91_EMAC_ERXCK     AT91_PIN(0, 1, 28) // EMAC 0 Receive Clock
#define AT91_EMAC_ECRS      AT91_PIN(0, 1, 29) // EMAC 0 Carrier Sense
#define AT91_EMAC_ECOL      AT91_PIN(0, 1, 30) // EMAC 0 Collision Detected
#define AT91_PCK_PCK0       AT91_PIN(0, 1, 31) // Programmable Clock Output 0

//*****************************************************************************
// CONTROL B
// PIO Controller B Peripheral A
#define AT91_SPI0_MISO      AT91_PIN(1, 0, 0) // SPI 0 Input
#define AT91_SPI0_MOSI      AT91_PIN(1, 0, 1) // SPI 0 Output
#define AT91_SPI0_SPCK      AT91_PIN(1, 0, 2) // SPI 0 Clock
#define AT91_SPI0_NPCS0     AT91_PIN(1, 0, 3) // SPI 0 Chip select 0.
#define AT91_USART_TXD1     AT91_PIN(1, 0, 4) // Serial port #1 TxD
#define AT91_USART_RXD1     AT91_PIN(1, 0, 5) // Serial port #1 RxD
#define AT91_USART_TXD2     AT91_PIN(1, 0, 6) // Serial port #2 TxD
#define AT91_USART_RXD2     AT91_PIN(1, 0, 7) // Serial port #2 RxD
#define AT91_USART_TXD3     AT91_PIN(1, 0, 8) // Serial port #3 TxD
#define AT91_USART_RXD3     AT91_PIN(1, 0, 9) // Serial port #3 RxD
#define AT91_TWI1_TWD       AT91_PIN(1, 0, 10) // Two Wire 1 Data 
#define AT91_TWI1_TWCK      AT91_PIN(1, 0, 11) // Two Wire 1 Clock
#define AT91_DBG_DRXD       AT91_PIN(1, 0, 12) // Debug UART Receive
#define AT91_DBG_DTXD       AT91_PIN(1, 0, 13) // Debug UART Transmit
#define AT91_SPI1_MISO      AT91_PIN(1, 0, 14) // SPI 1 Input
#define AT91_SPI1_MOSI      AT91_PIN(1, 0, 15) // SPI 1 Output
#define AT91_SPI1_SPCK      AT91_PIN(1, 0, 16) // SPI 1 Clock
#define AT91_SPI1_NPCS0     AT91_PIN(1, 0, 17) // SPI 1 Chip select 0.
#define AT91_USART_TXD0     AT91_PIN(1, 0, 19) // Serial port #0 TxD
#define AT91_USART_RXD0     AT91_PIN(1, 0, 18) // Serial port #0 RxD
#define AT91_ISI_D0		    AT91_PIN(1, 0, 20) // Image Sensor Interface Data 0
#define AT91_ISI_D1		    AT91_PIN(1, 0, 21) // Image Sensor Interface Data 1
#define AT91_ISI_D2		    AT91_PIN(1, 0, 22) // Image Sensor Interface Data 2
#define AT91_ISI_D3		    AT91_PIN(1, 0, 23) // Image Sensor Interface Data 3
#define AT91_ISI_D4		    AT91_PIN(1, 0, 24) // Image Sensor Interface Data 4
#define AT91_ISI_D5		    AT91_PIN(1, 0, 25) // Image Sensor Interface Data 5
#define AT91_ISI_D6		    AT91_PIN(1, 0, 26) // Image Sensor Interface Data 6
#define AT91_ISI_D7		    AT91_PIN(1, 0, 27) // Image Sensor Interface Data 7
#define AT91_ISI_PCLK	    AT91_PIN(1, 0, 28) // Image Sensor Interface Pixel Clock
#define AT91_ISI_VSYNC	    AT91_PIN(1, 0, 29) // Image Sensor Interface Vertical Sync
#define AT91_ISI_HSYNC	    AT91_PIN(1, 0, 30) // Image Sensor Interface Horizontal Sync
#define AT91_ISI_MCLK	    AT91_PIN(1, 0, 31) // Image Sensor Interface Master Clock

// PIO Controller B Peripheral B
#define AT91_ISI_D8		    AT91_PIN(1, 1, 8)  // Image Sensor Interface Data 8
#define AT91_ISI_D9		    AT91_PIN(1, 1, 9)  // Image Sensor Interface Data 9
#define AT91_ISI_D10	    AT91_PIN(1, 1, 10) // Image Sensor Interface Data 10
#define AT91_ISI_D11	    AT91_PIN(1, 1, 11) // Image Sensor Interface Data 11
#define AT91_USART_CTS0     AT91_PIN(1, 1, 15) // Serial port #0 Clear To Send
#define AT91_USART_SCK0     AT91_PIN(1, 1, 16) // Serial port #0 clock
#define AT91_USART_RTS0     AT91_PIN(1, 1, 17) // Serial port #0 Ready To Send
#define AT91_SPI0_NPCS1     AT91_PIN(1, 1, 18) // SPI 0 Chip select 1.
#define AT91_SPI0_NPCS2     AT91_PIN(1, 1, 19) // SPI 0 Chip select 2.
#define AT91_PCK_PCK1       AT91_PIN(1, 1, 31) // Programmable Clock Output 1	

//*****************************************************************************
// CONTROL C
// PIO Controller C Peripheral A
#define AT91_NANDALE        AT91_PIN(2, 0, 4)  //NAND Flash
#define AT91_NANDCLE        AT91_PIN(2, 0, 5)  //NAND Flash
#define AT91_NCS2           AT91_PIN(2, 0, 13) //Chip select #2
#define AT91_NCS3           AT91_PIN(2, 0, 14) //Chip select #3
#define AT91_NCS4           AT91_PIN(2, 0, 10) //Chip select #2
#define AT91_NCS5           AT91_PIN(2, 0, 11) //Chip select #3

//*****************************************************************************
// CONTROL D
// PIO Controller D Peripheral A
#define AT91_AC97RX         AT91_PIN(3, 0, 6)  // AC97 RX
#define AT91_AC97TX         AT91_PIN(3, 0, 7)  // AC97 TX
#define AT91_AC97FS         AT91_PIN(3, 0, 8)  // AC97 FS
#define AT91_AC97CK         AT91_PIN(3, 0, 9)  // AC97 CK


// PIO Controller D Peripheral B
#define AT91_INT_IRQ        AT91_PIN(3, 1, 18) // IRQ
#define AT91_INT_FIQ        AT91_PIN(3, 1, 19) // FIQ


#define AT91_SPI0_NPCS3        AT91_PIN(3, 1, 27) // SPI0_NPCS3
#define AT91_SPI1_NPCS1        AT91_PIN(3, 1, 28) // SPI1_NPCS1
#define AT91_SPI1_NPCS2        AT91_PIN(3, 0, 18) // SPI1_NPCS1
#define AT91_SPI1_NPCS3        AT91_PIN(3, 1, 19) // SPI1_NPCS1


//*****************************************************************************
// Redefine
#define AT91_UTXD0          AT91_USART_TXD0   //Redefine serial port #0
#define AT91_URXD0          AT91_USART_RXD0   //
#define AT91_UTXD1          AT91_USART_TXD1   //Redefine serial port #1
#define AT91_URXD1          AT91_USART_RXD1   //
#define AT91_A21_NANDALE    AT91_NANDALE
#define AT91_A22_NANDCLE    AT91_NANDCLE
#define AT91_EMAC_EREFCK    AT91_EMAC_ETXCK
#define AT91_MCI0_DA0       AT91_MCDA0         // Multimedia Card 0
#define AT91_MCI0_DA1       AT91_MCDA1
#define AT91_MCI0_DA2       AT91_MCDA2
#define AT91_MCI0_DA3       AT91_MCDA3
#define AT91_MCI0_CDA       AT91_MCCDA
#define AT91_MCI0_CK        AT91_MCCK
#define AT91_TWI_TWD        AT91_TWI0_TWD
#define AT91_TWI_TWCK       AT91_TWI0_TWCK
#define AT91_SPI_MISO		AT91_SPI0_MISO
#define AT91_SPI_MOSI		AT91_SPI0_MOSI
#define AT91_SPI_SPCK		AT91_SPI0_SPCK
#define AT91_SPI_NPCS0		AT91_SPI0_NPCS0
#define AT91_SPI_NPCS1		AT91_SPI0_NPCS1
#define AT91_SPI_NPCS2		AT91_SPI0_NPCS2
#define AT91_SPI_NPCS3		AT91_SPI0_NPCS3

//-----------------------------------------------------------------------------
#endif // CYGONCE_HAL_PIO_SAM9X45_H
