#ifndef CYGONCE_HAL_PIO_SAM9X25_H
#define CYGONCE_HAL_PIO_SAM9X25_H
//=============================================================================
//
//      pio_sam9x25.h
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
// SAM9X25-0001  2011/03/30 TuPN     Create file - Update address of peripherals
//
// =============================================================================
/* ----------------------------------------------------------------------------
 * PIN define
 *   #define AT91_PIN(_ctrl_, _periph_, _pin_)
 *      _ctrl_   : PIO Control
 *             0 : Control A      1 : Control B
 *             2 : Control C      3 : Control D
 *      _periph_ : Peripheral
 *             0 : Peripheral A   1 : Peripheral B
 *             2 : Peripheral C
 *      _pin_    : PIN index (0 -> 31)
 * ---------------------------------------------------------------------------*/
//*****************************************************************************
// CONTROL A
// PIO Controller A Peripheral A
#define AT91_USART_TXD0     AT91_PIN(0, 0,  0) // Serial port #0 TxD
#define AT91_USART_RXD0     AT91_PIN(0, 0,  1) // Serial port #0 RxD
#define AT91_USART_RTS0     AT91_PIN(0, 0,  2) // USART 0 Ready To Send
#define AT91_USART_CTS0     AT91_PIN(0, 0,  3) // USART 0 Clear To Send
#define AT91_USART_SCK0     AT91_PIN(0, 0,  4) // Serial port #0 clock
#define AT91_USART_TXD1     AT91_PIN(0, 0,  5) // Serial port #1 TxD
#define AT91_USART_RXD1     AT91_PIN(0, 0,  6) // Serial port #1 RxD
#define AT91_USART_TXD2     AT91_PIN(0, 0,  7) // Serial port #2 TxD
#define AT91_USART_RXD2     AT91_PIN(0, 0,  8) // Serial port #2 RxD
#define AT91_DBG_DRXD       AT91_PIN(0, 0,  9) // Debug UART Receive            //OK
#define AT91_DBG_DTXD       AT91_PIN(0, 0, 10) // Debug UART Transmi            //OK
#define AT91_SPI_MISO       AT91_PIN(0, 0, 11) // SPI 0 Input
#define AT91_SPI_MOSI       AT91_PIN(0, 0, 12) // SPI 0 Output
#define AT91_SPI_SPCK       AT91_PIN(0, 0, 13) // SPI 0 Clock
#define AT91_SPI0_NPCS0      AT91_PIN(0, 0, 14) // SPI 0 Chip select 0.
#define AT91_MCDA0          AT91_PIN(0, 0, 15) // Multimedia Card 0 Data 0
#define AT91_MCCDA          AT91_PIN(0, 0, 16) // Multimedia Card 0 Command
#define AT91_MCCK           AT91_PIN(0, 0, 17) // Multimedia Card 0 Clock
#define AT91_MCDA1          AT91_PIN(0, 0, 18) // Multimedia Card 0 Data 1
#define AT91_MCDA2          AT91_PIN(0, 0, 19) // Multimedia Card 0 Data 2
#define AT91_MCDA3          AT91_PIN(0, 0, 20) // Multimedia Card 0 Data 3
#define AT91_TC_TIOA0       AT91_PIN(0, 0, 21) // Timer #0 signal A
#define AT91_TC_TIOA1       AT91_PIN(0, 0, 22) // Timer #1 signal A
#define AT91_TC_TIOA2       AT91_PIN(0, 0, 23) // Timer #2 signal A
#define AT91_TC_TCLK0       AT91_PIN(0, 0, 24) // Timer #0 clock
#define AT91_TC_TCLK1       AT91_PIN(0, 0, 25) // Timer #1 clock
#define AT91_TC_TCLK2       AT91_PIN(0, 0, 26) // Timer #2 clock
#define AT91_TC_TIOB0       AT91_PIN(0, 0, 27) // Timer #0 signal B
#define AT91_TC_TIOB1       AT91_PIN(0, 0, 28) // Timer #1 signal B
#define AT91_TC_TIOB2       AT91_PIN(0, 0, 29) // Timer #2 signal B
#define AT91_TWI_TWD        AT91_PIN(0, 0, 30) // Two Wire 0 Data  /* T.D.B Must add new TW1,2 */
#define AT91_TWI_TWCK       AT91_PIN(0, 0, 31) // Two Wire 0 Clock

//PIO Controller A Peripheral B
#define AT91_SPI1_NPCS1     AT91_PIN(0, 1,  0) // SPI 1 Chip select 1
#define AT91_SPI0_NPCS2      AT91_PIN(0, 1,  1) // SPI 0 Chip select 2
#define AT91_MCI1_DA1       AT91_PIN(0, 1,  2) // Multimedia Card 1 Data 1  /* T.B.D New */
#define AT91_MCI1_DA2       AT91_PIN(0, 1,  3) // Multimedia Card 1 Data 2  /* T.B.D New */
#define AT91_MCI1_DA3       AT91_PIN(0, 1,  4) // Multimedia Card 1 Data 3  /* T.B.D New */
#define AT91_CAN_CANTX1     AT91_PIN(0, 1,  5) // CAN Transmit  /* T.B.D New */
#define AT91_CAN_CANRX1     AT91_PIN(0, 1,  6) // CAN Receive   /* T.B.D New */
#define AT91_SPI0_NPCS1      AT91_PIN(0, 1,  7) // SPI 0 Chip select 1
#define AT91_SPI1_NPCS0     AT91_PIN(0, 1,  8) // SPI 1 Chip select 0.
#define AT91_CAN_CANRX0     AT91_PIN(0, 1,  9) // CAN Receive  /* T.B.D New */
#define AT91_CAN_CANTX0     AT91_PIN(0, 1, 10) // CAN Transmit /* T.B.D New */
#define AT91_MCI1_DA0       AT91_PIN(0, 1, 11) // Multimedia Card 1 Data 0  /* T.B.D New */
#define AT91_MCI1_CDA       AT91_PIN(0, 1, 12) // Multimedia Card 1 Command /* T.B.D New */
#define AT91_MCI1_CK        AT91_PIN(0, 1, 13) // Multimedia Card 1 Clock   /* T.B.D New */
#define AT91_SPI1_MISO      AT91_PIN(0, 1, 21) // SPI 1 Input
#define AT91_SPI1_MOSI      AT91_PIN(0, 1, 22) // SPI 1 Output
#define AT91_SPI1_SPCK      AT91_PIN(0, 1, 23) // SPI 1 Clock
#define AT91_SSC_TK         AT91_PIN(0, 1, 24) // SSC Transmit Clock
#define AT91_SSC_TF         AT91_PIN(0, 1, 25) // SSC Transmit Frame Sync
#define AT91_SSC_TD         AT91_PIN(0, 1, 26) // SSC Transmit Data
#define AT91_SSC_RD         AT91_PIN(0, 1, 27) // SSC Receive Data
#define AT91_SSC_RK         AT91_PIN(0, 1, 28) // SSC Receive Clock
#define AT91_SSC_RF         AT91_PIN(0, 1, 29) // SSC Receive Frame Sync
#define AT91_SPI1_NPCS3     AT91_PIN(0, 1, 30) // SPI 1 Chip select 3
#define AT91_SPI1_NPCS2     AT91_PIN(0, 1, 31) // SPI 1 Chip select 1

//PIO Controller A Peripheral C
#define AT91_EMAC_ETX0X     AT91_PIN(0, 0,  2) // EMAC 0 Transmit Data 0
#define AT91_EMAC_ETX1X     AT91_PIN(0, 0,  3) // EMAC 0 Transmit Data 1
#define AT91_EMAC_ETXERX    AT91_PIN(0, 0,  4) // EMAC 0 Transmit Coding Error
#define AT91_EMAC_EMDCX     AT91_PIN(0, 0, 30) // EMAC 0 Management Data Clock
#define AT91_EMAC_ETXENX    AT91_PIN(0, 0, 31) // EMAC 0 Transmit Enable

//*****************************************************************************
// CONTROL B
// PIO Controller B Peripheral A
#define AT91_EMAC_ERX0      AT91_PIN(1, 0,  0) // EMAC 0 Receive Data 0
#define AT91_EMAC_ERX1      AT91_PIN(1, 0,  1) // EMAC 0 Receive Data 1
#define AT91_EMAC_ERXER     AT91_PIN(1, 0,  2) // EMAC 0 Receive Coding Error
#define AT91_EMAC_ERXDV     AT91_PIN(1, 0,  3) // EMAC 0 Receive Data Valid
#define AT91_EMAC_ETXCK     AT91_PIN(1, 0,  4) // EMAC 0 Transmit Clock
#define AT91_EMAC_EMDIO     AT91_PIN(1, 0,  5) // EMAC 0 Management Data IO
#define AT91_EMAC_EMDC      AT91_PIN(1, 0,  6) // EMAC 0 Management Data Clock (again)
#define AT91_EMAC_ETXEN     AT91_PIN(1, 0,  7) // EMAC 0 Transmit Enable (again)
#define AT91_EMAC_ETXER     AT91_PIN(1, 0,  8) // EMAC 0 Transmit Coding Error (again)
#define AT91_EMAC_ETX0      AT91_PIN(1, 0,  9) // EMAC 0 Transmit Data 0 (again)
#define AT91_EMAC_ETX1      AT91_PIN(1, 0, 10) // EMAC 0 Transmit Data 1 (again)
#define AT91_EMAC_ETX2      AT91_PIN(1, 0, 11) // EMAC 0 Transmit Data 2
#define AT91_EMAC_ETX3      AT91_PIN(1, 0, 12) // EMAC 0 Transmit Data 3
#define AT91_EMAC_ERX2      AT91_PIN(1, 0, 13) // EMAC 0 Receive Data 2
#define AT91_EMAC_ERX3      AT91_PIN(1, 0, 14) // EMAC 0 Receive Data 3
#define AT91_EMAC_ERXCK     AT91_PIN(1, 0, 15) // EMAC 0 Receive Clock
#define AT91_EMAC_ECRS      AT91_PIN(1, 0, 16) // EMAC 0 Carrier Sense
#define AT91_EMAC_ECOL      AT91_PIN(1, 0, 17) // EMAC 0 Collision Detected
#define AT91_INT_IRQ0       AT91_PIN(1, 0, 18) // IRQ #0

// PIO Controller B Peripheral B
#define AT91_USART_RTS2     AT91_PIN(1, 1,  0) // USART 2 Ready To Send
#define AT91_USART_CTS2     AT91_PIN(1, 1,  1) // USART 2 Clear To Send
#define AT91_USART_SCK2     AT91_PIN(1, 1,  2) // Serial port #2 clock
#define AT91_SPI0_NPCS3     AT91_PIN(1, 1,  3) // SPI 1 Chip select 1
#define AT91_TWI_TWD2       AT91_PIN(1, 1,  4) // Two Wire 2 Data  /* T.D.B New */
#define AT91_TWI_TWCK2      AT91_PIN(1, 1,  5) // Two Wire 2 Clock /* T.D.B New */
#define AT91_PCK_PCK1       AT91_PIN(1, 1,  9) // Programmable Clock Output 1
#define AT91_PCK_PCK0       AT91_PIN(1, 1, 10) // Programmable Clock Output 0
#define AT91_PWM_PWM0       AT91_PIN(1, 1, 11) // Pulse Width Modulation 0 /* T.B.D New */
#define AT91_PWM_PWM1       AT91_PIN(1, 1, 12) // Pulse Width Modulation 1 /* T.B.D New */
#define AT91_PWM_PWM2       AT91_PIN(1, 1, 13) // Pulse Width Modulation 2 /* T.B.D New */
#define AT91_PWM_PWM3       AT91_PIN(1, 1, 14) // Pulse Width Modulation 3 /* T.B.D New */
#define AT91_ADC_ADTRG      AT91_PIN(1, 1, 18) // ADC Trigger

//*****************************************************************************
// CONTROL C
// PIO Controller C Peripheral A
#define AT91_INT_FIQ        AT91_PIN(2, 0, 31) // FIQ

// PIO Controller C Peripheral B
#define AT91_EMAC1_ERXER    AT91_PIN(2, 1, 16) // EMAC 1 Receive Coding Error /* T.B.D New */
#define AT91_EMAC1_ETX0     AT91_PIN(2, 1, 18) // EMAC 1 Transmit Data 0    /* T.B.D New */
#define AT91_EMAC1_ETX1     AT91_PIN(2, 1, 19) // EMAC 1 Transmit Data 1    /* T.B.D New */
#define AT91_EMAC1_ERX0     AT91_PIN(2, 1, 20) // EMAC 1 Receive Data 0 /* T.B.D New */
#define AT91_EMAC1_ERX1     AT91_PIN(2, 1, 21) // EMAC 1 Receive Data 1 /* T.B.D New */
#define AT91_USART_TXD3     AT91_PIN(2, 1, 22) // Serial port #3 TxD
#define AT91_USART_RXD3     AT91_PIN(2, 1, 23) // Serial port #3 RxD
#define AT91_USART_RTS3     AT91_PIN(2, 1, 24) // USART 3 Ready To Send
#define AT91_USART_CTS3     AT91_PIN(2, 1, 25) // USART 0 Clear To Send
#define AT91_USART_SCK3     AT91_PIN(2, 1, 26) // Serial port #3 clock
#define AT91_EMAC1_ETXEN    AT91_PIN(2, 1, 27) // EMAC 1 Transmit Enable  /* T.B.D New */
#define AT91_EMAC1_ERXDV    AT91_PIN(2, 1, 28) // EMAC 1 Receive Data Valid /* T.B.D New */
#define AT91_EMAC1_ETXCK    AT91_PIN(2, 1, 29) // EMAC 1 Transmit Clock /* T.B.D New */
#define AT91_EMAC1_EMDC     AT91_PIN(2, 1, 30) // EMAC 1 Management Data Clock /* T.B.D New */
#define AT91_EMAC1_EMDIO    AT91_PIN(2, 1, 31) // EMAC 1 Management Data IO /* T.B.D New */

// PIO Controller C Peripheral C
#define AT91_TWI_TWD1       AT91_PIN(2, 2,  0) // Two Wire 2 Data  /* T.D.B New */
#define AT91_TWI_TWCK1      AT91_PIN(2, 2,  1) // Two Wire 2 Clock /* T.D.B New */
#define AT91_TC_TIOA3       AT91_PIN(2, 2,  2) // Timer #3 signal A
#define AT91_TC_TIOB3       AT91_PIN(2, 2,  3) // Timer #3 signal B
#define AT91_TC_TCLK3       AT91_PIN(2, 2,  4) // Timer #3 clock
#define AT91_TC_TIOA4       AT91_PIN(2, 2,  5) // Timer #3 signal A
#define AT91_TC_TIOB4       AT91_PIN(2, 2,  6) // Timer #4 signal B
#define AT91_TC_TCLK4       AT91_PIN(2, 2,  7) // Timer #4 clock
#define AT91_USART_TXD4     AT91_PIN(2, 2,  8) // Serial port #4 TxD
#define AT91_USART_RXD4     AT91_PIN(2, 2,  9) // Serial port #4 RxD
#define AT91_PWM_PWM0X      AT91_PIN(2, 2, 10) // Pulse Width Modulation 0 (again) /* T.B.D New */
#define AT91_PWM_PWM1X      AT91_PIN(2, 2, 11) // Pulse Width Modulation 1 (again) /* T.B.D New */
#define AT91_TC_TIOA5       AT91_PIN(2, 2, 12) // Timer #3 signal A
#define AT91_TC_TIOB5       AT91_PIN(2, 2, 13) // Timer #5 signal B
#define AT91_TC_TCLK5       AT91_PIN(2, 2, 14) // Timer #5 clock
#define AT91_PCK_PCK0X      AT91_PIN(2, 2, 15) // Programmable Clock Output 0 (again)
#define AT91_USART_TXD5     AT91_PIN(2, 2, 16) // Serial port #5 TxD
#define AT91_USART_RXD5     AT91_PIN(2, 2, 17) // Serial port #5 RxD
#define AT91_PWM_PWM0XX     AT91_PIN(2, 2, 18) // Pulse Width Modulation 0 (again) /* T.B.D New */
#define AT91_PWM_PWM1XX     AT91_PIN(2, 2, 19) // Pulse Width Modulation 1 (again) /* T.B.D New */
#define AT91_PWM_PWM2XX     AT91_PIN(2, 2, 20) // Pulse Width Modulation 2 (again) /* T.B.D New */
#define AT91_PWM_PWM3XX     AT91_PIN(2, 2, 21) // Pulse Width Modulation 3 (again) /* T.B.D New */
#define AT91_USART_RTS1     AT91_PIN(2, 2, 27) // USART 1 Ready To Send
#define AT91_USART_CTS1     AT91_PIN(2, 2, 28) // USART 1 Clear To Send
#define AT91_USART_SCK1     AT91_PIN(2, 2, 29) // Serial port #1 clock
#define AT91_PCK_PCK1X      AT91_PIN(2, 2, 31) // Programmable Clock Output 1 (again)

//*****************************************************************************
// CONTROL D
// PIO Controller D Peripheral A
#define AT91_NANDOE         AT91_PIN(3, 0, 0) //NAND Flash - /* T.B.D Need check */
#define AT91_NANDWE         AT91_PIN(3, 0, 1) //NAND Flash - /* T.B.D Need check */
#define AT91_NANDALE        AT91_PIN(3, 0, 2) //NAND Flash - /* T.B.D Need check */
#define AT91_NANDCLE        AT91_PIN(3, 0, 3) //NAND Flash - /* T.B.D Need check */
#define AT91_NCS3           AT91_PIN(3, 0, 4) //Chip select #3 - /* T.B.D Need check */
#define AT91_NWAIT          AT91_PIN(3, 0, 5) // EBI: External Wait Signal

// PIO Controller D Peripheral B
#define AT91_NCS2           AT91_PIN(3, 1, 19) //Chip select #3 - /* T.B.D Need check */
#define AT91_NCS4           AT91_PIN(3, 1, 20) //Chip select #3 - /* T.B.D Need check */
#define AT91_NCS5           AT91_PIN(3, 1, 21) //Chip select #3 - /* T.B.D Need check */

//*****************************************************************************
// Redefine
#define AT91_UTXD0          AT91_USART_TXD4   //Redefine serial port #0
#define AT91_URXD0          AT91_USART_RXD4   //
#define AT91_UTXD1          AT91_USART_TXD5   //Redefine serial port #1
#define AT91_URXD1          AT91_USART_RXD5   //
#define AT91_A21_NANDALE    AT91_NANDALE
#define AT91_A22_NANDCLE    AT91_NANDCLE
#define AT91_EMAC_EREFCK    AT91_EMAC_ETXCK
#define AT91_MCI0_DA0       AT91_MCDA0         // Multimedia Card 0
#define AT91_MCI0_DA1       AT91_MCDA1
#define AT91_MCI0_DA2       AT91_MCDA2
#define AT91_MCI0_DA3       AT91_MCDA3
#define AT91_MCI0_CDA       AT91_MCCDA
#define AT91_MCI0_CK        AT91_MCK

//-----------------------------------------------------------------------------
#endif // CYGONCE_HAL_PIO_SAM9X25_H
