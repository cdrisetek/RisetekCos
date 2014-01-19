#ifndef CYGONCE_HAL_PLF_IO_SAM9260_H
#define CYGONCE_HAL_PLF_IO_SAM9260_H
//=============================================================================
//
//      plf_io.h
//
//      AT91SAM9260 specific registers
//
//=============================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
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
// Author(s):   
// Contributors:
// Date:        
// Purpose:     Atmel AT91SAM9 board specific registers
// Description:
// Usage:       #include <cyg/hal/plf_io.h>
//
//####DESCRIPTIONEND####
//
//=============================================================================

// Cache translation
#ifndef CYGPKG_REDBOOT
#define CYGARC_KSEG_MASK             0xF0000000
#define CYGARC_KSEG_CACHED           0x20000000
#define CYGARC_KSEG_UNCACHED         0xB0000000
#define CYGARC_CACHED_ADDRESS(x)     ((((cyg_uint32)(x) & CYGARC_KSEG_MASK) == CYGARC_KSEG_UNCACHED) ? \
                                      (((cyg_uint32)(x) & ~CYGARC_KSEG_MASK) | CYGARC_KSEG_CACHED) : (cyg_uint32)(x))
#define CYGARC_UNCACHED_ADDRESS(x)   ((((cyg_uint32)(x) & CYGARC_KSEG_MASK) == CYGARC_KSEG_CACHED) ? \
                                      (((cyg_uint32)(x) & ~CYGARC_KSEG_MASK) | CYGARC_KSEG_UNCACHED) : (cyg_uint32)(x))
#endif

// Peripheral Input/Output Controllers
#define AT91_PIOA   0xFFFFF400
#define AT91_PIOB   0xFFFFF600
#define AT91_PIOC   0xFFFFF800
#define AT91_PIO    AT91_PIOA

// TC - Timer Counter
#define AT91_TC     0xFFFA0000
#define AT91_TC3    (0xFFFDC000 - 0xFFFA0000)
#define AT91_TC4    (AT91_TC3 + AT91_TC_TC_SIZE)
#define AT91_TC5    (AT91_TC3 + 2 * AT91_TC_TC_SIZE)

// UDP - UDP Device Port
#define AT91_UDP    0xFFFA4000

// TWI - Two Wire Interface
#define AT91_TWI    0xFFFAC000

// USART
#define AT91_USART0 0xFFFB0000
#define AT91_USART1 0xFFFB4000
#define AT91_USART2 0xFFFB8000
#define AT91_USART3 0xFFFD0000
#define AT91_USART4 0xFFFD4000
#define AT91_USART5 0xFFFD8000

// USART DMA registers
#define AT91_US_RPR  0x100 // Receive Pointer Register
#define AT91_US_RCR  0x104 // Receive Counter Register
#define AT91_US_TPR  0x108 // Transmit Pointer Register
#define AT91_US_TCR  0x10C // Transmit Counter Register
#define AT91_US_NRPR 0x110 // Next Receive Pointer Register
#define AT91_US_NRCR 0x114 // Next Receive Counter Register
#define AT91_US_NTPR 0x118 // Next Transmit Pointer Register
#define AT91_US_NTCR 0x11C // Next Transmit Counter Register
#define AT91_US_PTCR 0x120 // PDC Transfer Control Register
#define AT91_US_PTSR 0x124 // PDC Transfer Status Register


// DEBUG serial channel
#define AT91_DBG 0xFFFFF200

// Define USART6 to be the debug UART. It is similar enough to a USART
// that both the hal_diag and interrupt driven driver will work.
// However trying to change parity, start/stop bits etc will not work.
#define CYGNUM_HAL_INTERRUPT_USART6 CYGNUM_HAL_INTERRUPT_DBG
#define AT91_USART6 AT91_DBG
#define AT91_USART_RXD6 AT91_DBG_DRXD
#define AT91_USART_TXD6 AT91_DBG_DTXD

#ifndef __ASSEMBLER__
#ifdef CYGBLD_HAL_ARM_AT91_BAUD_DYNAMIC
extern cyg_uint32 hal_at91_us_baud(cyg_uint32 baud);
#define AT91_US_BAUD(baud) hal_at91_us_baud(baud)
#endif
#endif // __ASSEMBLER__

// SSC - Synchronous Serial Controller
#define AT91_SSC    0xFFFBC000

// ISI - Image Sensor Interface
#define AT91_ISI    0xFFFC0000

// EMAC - Ethernet Medium Access Controller
#define AT91_EMAC   0xFFFC4000

//SPI - Serial Peripheral Interface
#define AT91_SPI0   0xFFFC8000
#define AT91_SPI1   0xFFFCC000
#define AT91_SPI    AT91_SPI0

// SPI DMA registers (same offsets as UART)
#define AT91_SPI_RPR  0x100 // Receive Pointer Register
#define AT91_SPI_RCR  0x104 // Receive Counter Register
#define AT91_SPI_TPR  0x108 // Transmit Pointer Register
#define AT91_SPI_TCR  0x10C // Transmit Counter Register
#define AT91_SPI_NRPR 0x110 // Next Receive Pointer Register
#define AT91_SPI_NRCR 0x114 // Next Receive Counter Register
#define AT91_SPI_NTPR 0x118 // Next Transmit Pointer Register
#define AT91_SPI_NTCR 0x11C // Next Transmit Counter Register
#define AT91_SPI_PTCR 0x120 // PDC Transfer Control Register
#define AT91_SPI_PTSR 0x124 // PDC Transfer Status Register

// ADC - Analog to Digital Converter
#define AT91_ADC    0xFFFE0000

// Power Management Controller
#define AT91_PMC    0xFFFFFC00

#define AT91_PMC_MOR    0x20 // Main Oscillator Register
#define AT91_PMC_MOR_MOSCEN    (1 << 0) // Main Oscillator Enable
#define AT91_PMC_MOR_OSCBYPASS (1 << 1) // Main Oscillator Bypass
#define AT91_PMC_MOR_OSCCOUNT(x) ((x) << 8) // Slow clocks ticks
#define AT91_PMC_MCFR   0x24 // Main Clock Frequency Register
#define AT91_PMC_PLLRA  0x28
#define AT91_PMC_PLLRB  0x2C
#define AT91_PMC_PLLR AT91_PMC_PLLRA
#define AT91_PMC_PLLR_DIV(x)      ((x) <<  0)  // PLL Devide
#define AT91_PMC_PLLR_PLLCOUNT(x) ((x) <<  8)  // PLL Count
#define AT91_PMC_PLLR_MUL(x)      ((x) << 16)  // PLL Devide
#define AT91_PMC_PLLR_OUT_0 (0 << 14)
#define AT91_PMC_PLLR_OUT_1 (1 << 14)
#define AT91_PMC_PLLR_OUT_2 (2 << 14)
#define AT91_PMC_PLLR_OUT_3 (3 << 14)
#define AT91_PMC_PLLR_USBDIV_0 (0 << 28) // USB clock is PLL clock / 1
#define AT91_PMC_PLLR_USBDIV_1 (1 << 28) // USB clock is PLL clock / 2
#define AT91_PMC_PLLR_USBDIV_2 (2 << 28) // USB clock is PLL clock / 4
#define AT91_PMC_MCKR   0x30 // Master Clock Register
#define AT91_PMC_MCKR_SLOW_CLK (0 << 0) // Slow clock selected
#define AT91_PMC_MCKR_MAIN_CLK (1 << 0) // Main clock selected
#define AT91_PMC_MCKR_PLLA_CLK (2 << 0) // PLLA clock selected
#define AT91_PMC_MCKR_PLLB_CLK (3 << 0) // PLLB clock selected
#define AT91_PMC_MCKR_PRES_CLK    (0 << 2) // divide by 1
#define AT91_PMC_MCKR_PRES_CLK_2  (1 << 2) // divide by 2
#define AT91_PMC_MCKR_PRES_CLK_4  (2 << 2) // divide by 4
#define AT91_PMC_MCKR_PRES_CLK_8  (3 << 2) // divide by 8
#define AT91_PMC_MCKR_PRES_CLK_16 (4 << 2) // divide by 16
#define AT91_PMC_MCKR_PRES_CLK_32 (5 << 2) // divide by 32
#define AT91_PMC_MCKR_PRES_CLK_64 (6 << 2) // divide by 64
#define AT91_PMC_PCKR0  0x40  // Programmable Clock Register 0
#define AT91_PMC_PCKR1  0x44  // Programmable Clock Register 1
#define AT91_PMC_IER    0x60 // Interrupt Enable Register
#define AT91_PMC_IDR    0x64 // Interrupt Disable Register
#define AT91_PMC_SR     0x68 // Status Register
#define AT91_PMC_SR_MOSCS   (1 << 0) // Main oscillator stable
#define AT91_PMC_SR_LOCKA   (1 << 1) // PLLA Locked
#define AT91_PMC_SR_LOCKB   (1 << 2) // PLLB Locked
#define AT91_PMC_SR_MCKRDY  (1 << 3) // MCK is ready to be enabled
#define AT91_PMC_SR_OSCSEL  (1 << 7) // External slow clock oscillator selected
#define AT91_PMC_SR_PCK0RDY (1 << 8) // Pad clock 0 is ready to be enabled
#define AT91_PMC_SR_PCK1RDY (1 << 9) // Pad clock 1 is ready to be enabled
#define AT91_PMC_IMR    0x6c // Interrupt Mask Register

#define AT91_PMC_SCER_PCK  (1 << 0) // Processor Clock
#define AT91_PMC_SCER_UHP  (1 << 6) // USB Host Clock
#define AT91_PMC_SCER_UDP  (1 << 7) // USB Device Clock
#define AT91_PMC_SCER_PCK0 (1 << 8) // Programmable Clock Output
#define AT91_PMC_SCER_PCK1 (1 << 9) // Programmable Clock Output

#define AT91_PMC_PCER_FIQ  (1 << 0) // Advanced Interrupt Controller FIQ
#define AT91_PMC_PCER_SYSC (1 << 1) // System Controller Interrupt
#define AT91_PMC_PCER_PIOA (1 << 2) // Parallel IO Controller
#define AT91_PMC_PCER_PIOB (1 << 3) // Parallel IO Controller
#define AT91_PMC_PCER_PIOC (1 << 4) // Parallel IO Controller
#define AT91_PMC_PCER_ADC  (1 << 5) // Analog-to-Digital Converter
#define AT91_PMC_PCER_US0  (1 << 6) // USART 0
#define AT91_PMC_PCER_US1  (1 << 7) // USART 1
#define AT91_PMC_PCER_US2  (1 << 8) // USART 2
#define AT91_PMC_PCER_MCI  (1 << 9) // Multimedia Card Interface
#define AT91_PMC_PCER_UDP  (1 <<10) // USB Device Port
#define AT91_PMC_PCER_TWI  (1 <<11) // Two-Wire Interface
#define AT91_PMC_PCER_SPI  (1 <<12) // Serial Peripheral Interface
#define AT91_PMC_PCER_SPI1 (1 <<13) // Serial Peripheral Interface
#define AT91_PMC_PCER_SSC  (1 <<14) // Serial Synchronous Controller
#define AT91_PMC_PCER_TC0  (1 <<17) // Timer Counter 0
#define AT91_PMC_PCER_TC1  (1 <<18) // Timer Counter 1
#define AT91_PMC_PCER_TC2  (1 <<19) // Timer Counter 2
#define AT91_PMC_PCER_UHP  (1 <<20) // USB Host Port
#define AT91_PMC_PCER_EMAC (1 <<21) // Ethernet MAC
#define AT91_PMC_PCER_ISI  (1 <<22) // Image Sensor Interface
#define AT91_PMC_PCER_US3  (1 <<23) // USART 3
#define AT91_PMC_PCER_US4  (1 <<24) // USART 4
#define AT91_PMC_PCER_US5  (1 <<25) // USART 5
#define AT91_PMC_PCER_TC3  (1 <<26) // Timer Counter 3
#define AT91_PMC_PCER_TC4  (1 <<27) // Timer Counter 4
#define AT91_PMC_PCER_TC5  (1 <<28) // Timer Counter 5
#define AT91_PMC_PCER_IRQ0 (1 <<29) // Advanced Interrupt Controller IRQ0
#define AT91_PMC_PCER_IRQ1 (1 <<30) // Advanced Interrupt Controller IRQ1
#define AT91_PMC_PCER_IRQ2 (1 <<31) // Advanced Interrupt Controller IRQ2

//PIO Controller A Peripheral A
#define AT91_SPI_MISO       AT91_PIN(0,0, 0) // SPI 0 Input
#define AT91_SPI_MOSI       AT91_PIN(0,0, 1) // SPI 0 Output
#define AT91_SPI_SPCK       AT91_PIN(0,0, 2) // SPI 0 Clock
#define AT91_SPI_NPCS0      AT91_PIN(0,0, 3) // SPI 0 Chip select 0.
#define AT91_USART_RTS2     AT91_PIN(0,0, 4) // USART 2 Ready To Send
#define AT91_USART_CTS2     AT91_PIN(0,0, 5) // USART 2 Clear To Send
#define AT91_MCDA0          AT91_PIN(0,0, 6) // Multimedia Card A Data 0
#define AT91_MCCDA          AT91_PIN(0,0, 7) // Multimedia Card A Command
#define AT91_MCCK           AT91_PIN(0,0, 8) // Multimedia Card Clock
#define AT91_MCDA1          AT91_PIN(0,0, 9) // Multimedia Card A Data 1
#define AT91_MCDA2          AT91_PIN(0,0, 10) // Multimedia Card A Data 2
#define AT91_MCDA3          AT91_PIN(0,0, 11) // Multimedia Card A Data 3
#define AT91_EMAC_ETX0      AT91_PIN(0,0, 12) // EMAC Transmit Data 0
#define AT91_EMAC_ETX1      AT91_PIN(0,0, 13) // EMAC Transmit Data 1
#define AT91_EMAC_ERX0      AT91_PIN(0,0, 14) // EMAC Receive Data 0
#define AT91_EMAC_ERX1      AT91_PIN(0,0, 15) // EMAC Receive Data 1
#define AT91_EMAC_ETXEN     AT91_PIN(0,0, 16) // EMAC Transmit Enable
#define AT91_EMAC_ERXDV     AT91_PIN(0,0, 17) // EMAC Receive Data Valid
#define AT91_EMAC_ERXER     AT91_PIN(0,0, 18) // EMAC Receive Coding Error
#define AT91_EMAC_ETXCK     AT91_PIN(0,0, 19) // EMAC Transmit Clock
#define AT91_EMAC_EREFCK    AT91_EMAC_ETXCK

#define AT91_EMAC_EMDC      AT91_PIN(0,0, 20) // EMAC Management Data Clock
#define AT91_EMAC_EMDIO     AT91_PIN(0,0, 21) // EMAC Management Data IO
#define AT91_ADC_ADTRG      AT91_PIN(0,0, 22) // ADC Trigger
#define AT91_TWI_TWD        AT91_PIN(0,0, 23) // Two Wire Data
#define AT91_TWI_TWCK       AT91_PIN(0,0, 24) // Two Wire Clock
#define AT91_TC_TCLK0       AT91_PIN(0,0, 25) // Timer #0 clock
#define AT91_TC_TIOA0       AT91_PIN(0,0, 26) // Timer #0 signal A
#define AT91_TC_TIOA1       AT91_PIN(0,0, 27) // Timer #1 signal A
#define AT91_TC_TIOA2       AT91_PIN(0,0, 28) // Timer #2 signal A
#define AT91_USART_SCK1     AT91_PIN(0,0, 29) // Serial port #1 clock
#define AT91_USART_SCK2     AT91_PIN(0,0, 30) // Serial port #2 clock
#define AT91_USART_SCK0     AT91_PIN(0,0, 31) // Serial port #0 clock

//PIO Controller A Peripheral B
#define AT91_MCDB0          AT91_PIB(0,1, 0) // Multimedia Card B Data 0
#define AT91_MCCDB          AT91_PIB(0,1, 1) // Multimedia Card B Command
#define AT91_MCDB3          AT91_PIB(0,1, 3) // Multimedia Card B Data 3
#define AT91_MCDB2          AT91_PIB(0,1, 4) // Multimedia Card B Data 2
#define AT91_MCDB1          AT91_PIB(0,1, 5) // Multimedia Card B Data 1
#define AT91_EMAC_ETX2X     AT91_PIN(0,1, 10) // EMAC Transmit Data 2 (again)
#define AT91_EMAC_ETX3X     AT91_PIN(0,1, 11) // EMAC Transmit Data 3 (again)
#define AT91_EMAC_ETXER     AT91_PIN(0,1, 22) // EMAC Transmit Coding Error
#define AT91_EMAC_ETX2      AT91_PIN(0,1, 23) // EMAC Transmit Data 2
#define AT91_EMAC_ETX3      AT91_PIN(0,1, 24) // EMAC Transmit Data 3
#define AT91_EMAC_ERX2      AT91_PIN(0,1, 25) // EMAC Receive Data 2
#define AT91_EMAC_ERX3      AT91_PIN(0,1, 26) // EMAC Receive Data 3
#define AT91_EMAC_ERXCK     AT91_PIN(0,1, 27) // EMAC Receive Clock
#define AT91_EMAC_ECRS      AT91_PIN(0,1, 28) // EMAC Carrier Sense
#define AT91_EMAC_ECOL      AT91_PIN(0,1, 29) // EMAC Collision Detected
#define AT91_USART_RXD4     AT91_PIN(0,1, 30) // Serial port #4 RxD
#define AT91_USART_TXD4     AT91_PIN(0,1, 31) // Serial port #4 TxD

//PIO Controller B Peripheral A
#define AT91_SPI1_MISO      AT91_PIN(1,0, 0) // SPI 1 Input
#define AT91_SPI1_MOSI      AT91_PIN(1,0, 1) // SPI 1 Output
#define AT91_SPI1_SPCK      AT91_PIN(1,0, 2) // SPI 1 Clock
#define AT91_SPI1_NPCS0     AT91_PIN(1,0, 3) // SPI 1 Chip select 0.
#define AT91_USART_TXD0     AT91_PIN(1,0, 4) // Serial port #0 TxD
#define AT91_USART_RXD0     AT91_PIN(1,0, 5) // Serial port #0 RxD
#define AT91_USART_TXD1     AT91_PIN(1,0, 6) // Serial port #1 TxD
#define AT91_USART_RXD1     AT91_PIN(1,0, 7) // Serial port #1 RxD
#define AT91_USART_TXD2     AT91_PIN(1,0, 8) // Serial port #2 TxD
#define AT91_USART_RXD2     AT91_PIN(1,0, 9) // Serial port #2 RxD
#define AT91_USART_TXD3     AT91_PIN(1,0, 10) // Serial port #3 TxD
#define AT91_USART_RXD3     AT91_PIN(1,0, 11) // Serial port #3 RxD
#define AT91_USART_TXD5     AT91_PIN(1,0, 12) // Serial port #5 TxD
#define AT91_USART_RXD5     AT91_PIN(1,0, 13) // Serial port #5 RxD
#define AT91_DBG_DRXD       AT91_PIN(1,0, 14) // Debug UART Receive
#define AT91_DBG_DTXD       AT91_PIN(1,0, 15) // Debug UART Transmit
#define AT91_SSC_TK         AT91_PIN(1,0, 16) // SSC Transmit Clock
#define AT91_SSC_TF         AT91_PIN(1,0, 17) // SSC Transmit Frame Sync
#define AT91_SSC_TD         AT91_PIN(1,0, 18) // SSC Transmit Data
#define AT91_SSC_RD         AT91_PIN(1,0, 19) // SSC Receive Data
#define AT91_SSC_RK         AT91_PIN(1,0, 20) // SSC Receive Clock
#define AT91_SSC_RF         AT91_PIN(1,0, 21) // SSC Receive Frame Sync
#define AT91_USART_DSR0     AT91_PIN(1,0, 22) // USART 0 Data Set Ready
#define AT91_USART_DCD0     AT91_PIN(1,0, 23) // USART 0 Data Carrier Detect
#define AT91_USART_DTR0     AT91_PIN(1,0, 24) // USART 0 Data Terminal Ready
#define AT91_USART_RI0      AT91_PIN(1,0, 25) // USART 0 Ring Indication
#define AT91_USART_RTS0     AT91_PIN(1,0, 26) // USART 0 Ready To Send
#define AT91_USART_CTS0     AT91_PIN(1,0, 27) // USART 0 Clear To Send
#define AT91_USART_RTS1     AT91_PIN(1,0, 28) // USART 1 Ready To Send
#define AT91_USART_CTS1     AT91_PIN(1,0, 29) // USART 1 Clear To Send
#define AT91_PCK_PCK0       AT91_PIN(1,0, 30) // Programmable Clock Output 0
#define AT91_PCK_PCK1       AT91_PIN(1,0, 31) // Programmable Clock Output 1

#define AT91_PIO_PSR_DRXD     (1 << 14)     // Debug UART Receive
#define AT91_PIO_PSR_DTXD     (1 << 15)     // Debug UART Transmit

//PIO Controller B Peripheral B
#define AT91_TC_TIOA3       AT91_PIN(1,1, 0) // Timer #3 signal A
#define AT91_TC_TIOB3       AT91_PIN(1,1, 1) // Timer #3 signal B
#define AT91_TC_TIOA4       AT91_PIN(1,1, 2) // Timer #3 signal A
#define AT91_TC_TIOA5       AT91_PIN(1,1, 3) // Timer #3 signal A
#define AT91_TC_TCLK1X      AT91_PIN(1,1, 6) // Timer #1 clock (again)
#define AT91_TC_TCLK2X      AT91_PIN(1,1, 7) // Timer #2 clock (again)
#define AT91_ISI_D8         AT91_PIN(1,1, 10) // ISI Data 8
#define AT91_ISI_D9         AT91_PIN(1,1, 11) // ISI Data 9
#define AT91_ISI_D10        AT91_PIN(1,1, 12) // ISI Data 10
#define AT91_ISI_D11        AT91_PIN(1,1, 13) // ISI Data 11
#define AT91_TC_TCLK3       AT91_PIN(1,1, 16) // Timer #3 clock
#define AT91_TC_TCLK4       AT91_PIN(1,1, 17) // Timer #4 clock
#define AT91_TC_TIOB4       AT91_PIN(1,1, 18) // Timer #4 signal B
#define AT91_TC_TIOB5       AT91_PIN(1,1, 19) // Timer #5 signal B
#define AT91_ISI_D0         AT91_PIN(1,1, 20) // ISI Data 1
#define AT91_ISI_D1         AT91_PIN(1,1, 21) // ISI Data 2
#define AT91_ISI_D2         AT91_PIN(1,1, 22) // ISI Data 3
#define AT91_ISI_D3         AT91_PIN(1,1, 23) // ISI Data 4
#define AT91_ISI_D4         AT91_PIN(1,1, 24) // ISI Data 5
#define AT91_ISI_D5         AT91_PIN(1,1, 25) // ISI Data 6
#define AT91_ISI_D6         AT91_PIN(1,1, 26) // ISI Data 7
#define AT91_ISI_D7         AT91_PIN(1,1, 27) // ISI Data 8
#define AT91_ISI_PCK        AT91_PIN(1,1, 28) // ISI Pixel Clock
#define AT91_ISI_VSYNC      AT91_PIN(1,1, 29) // ISI Vertical Sync
#define AT91_ISI_HSYNC      AT91_PIN(1,1, 30) // ISI Horizontal Sync

//PIO Controller C Peripheral A
#define AT91_EBI_A23        AT91_PIN(2,0, 4) // Address line (default at POR)
#define AT91_EBI_A24        AT91_PIN(2,0, 5) // Address line (default at POR)
#define AT91_TC_TIOB2       AT91_PIN(2,0, 6) // Timer #2 signal B
#define AT91_TC_TIOB1       AT91_PIN(2,0, 7) // Timer #1 signal B
#define AT91_NCS4_CFCS0     AT91_PIN(2,0, 8) // CompactFlash Chip Select 0
#define AT91_NCS5_CFCS1     AT91_PIN(2,0, 9) // CompactFlash Chip Select 1
#define AT91_CFRNW          AT91_PIN(2,0, 10) // CompactFlash Read Not Write
#define AT91_NCS2           AT91_PIN(2,0, 11) // Chip Select 2
#define AT91_INT_IRQ0       AT91_PIN(2,0, 12) // IRQ #0
#define AT91_INT_FIQ        AT91_PIN(2,0, 13) // FIQ
#define AT91_NCS3_NANDCS    AT91_PIN(2,0, 14) // Chip Select 3 (NAND Flash)
#define AT91_NWAIT          AT91_PIN(2,0, 15) // External Signal Wait

//PIO Controller C Peripheral B
#define AT91_USART_SCK3     AT91_PIN(2,1, 0) // Serial port #3 clock
#define AT91_PCK_PCK0X      AT91_PIN(2,1, 1) // Programmable Clock Output 0 (again)
#define AT91_PCK_PCK1X      AT91_PIN(2,1, 2) // Programmable Clock Output 1 (again)
#define AT91_SPI1_NPCS3     AT91_PIN(2,1, 3) // SPI 1 Chip select 3
#define AT91_SPI1_NPCS2     AT91_PIN(2,1, 4) // SPI 1 Chip select 2
#define AT91_SPI1_NPCS1     AT91_PIN(2,1, 5) // SPI 1 Chip select 1
#define AT91_CFCE1          AT91_PIN(2,1, 6) // CompactFlash Chip Enable 1
#define AT91_CFCE2          AT91_PIN(2,1, 7) // CompactFlash Chip Enable 2
#define AT91_USART_RTS3     AT91_PIN(2,1, 8) // USART 3 Ready To Send
#define AT91_TC_TIOB0       AT91_PIN(2,1, 9) // Timer #0 signal B
#define AT91_USART_CTS3     AT91_PIN(2,1, 10) // USART 0 Clear To Send
#define AT91_SPI_NPCS1      AT91_PIN(2,1, 11) // SPI 0 Chip select 1
#define AT91_NCS7           AT91_PIN(2,1, 12) // Chip Select 7
#define AT91_NCS6           AT91_PIN(2,1, 13) // Chip Select 6
#define AT91_INT_IRQ2       AT91_PIN(2,1, 14) // IRQ #2
#define AT91_INT_IRQ1       AT91_PIN(2,1, 15) // IRQ #1
#define AT91_SPI_NPCS2      AT91_PIN(2,1, 16) // SPI 1 Chip select 1
#define AT91_SPI_NPCS3      AT91_PIN(2,1, 17) // SPI 1 Chip select 1
#define AT91_SPI1_NPCS1X    AT91_PIN(2,1, 18) // SPI 1 Chip select 1 (again)
#define AT91_SPI1_NPCS2X    AT91_PIN(2,1, 19) // SPI 1 Chip select 1 (again)
#define AT91_SPI1_NPCS3X    AT91_PIN(2,1, 20) // SPI 1 Chip select 1 (again)
#define AT91_EMAC_TF100     AT91_PIN(2,1, 21) // EMAC Force 100MBIT
#define AT91_TC_TCLK5       AT91_PIN(2,1, 22) // Timer #5 clock

#endif //CYGONCE_HAL_PLF_IO_SAM9260_H

