#ifndef CYGONCE_HAL_PLF_IO_SAMA5D3_H
#define CYGONCE_HAL_PLF_IO_SAMA5D3_H
//=============================================================================
//
//      plf_io.h
//
//      AT91SAMA5D3 specific registers
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
#define CYGARC_KSEG_CACHED           0x70000000
#define CYGARC_KSEG_UNCACHED         0xB0000000
#define CYGARC_CACHED_ADDRESS(x)     ((((cyg_uint32)(x) & CYGARC_KSEG_MASK) == CYGARC_KSEG_UNCACHED) ? \
                                      (((cyg_uint32)(x) & ~CYGARC_KSEG_MASK) | CYGARC_KSEG_CACHED) : (cyg_uint32)(x))
#define CYGARC_UNCACHED_ADDRESS(x)   ((((cyg_uint32)(x) & CYGARC_KSEG_MASK) == CYGARC_KSEG_CACHED) ? \
                                      (((cyg_uint32)(x) & ~CYGARC_KSEG_MASK) | CYGARC_KSEG_UNCACHED) : (cyg_uint32)(x))
#endif

// Error Correcting Code Controller
#define AT91_ECC    0xFFFFE200

// DDRAM Controller(s)
#define AT91_DDRAMC0 0xFFFFE600    // memory at 0x70000000
#define AT91_DDRAMC1 0xFFFFE400    // memory at 0x20000000

// SDRAM Controller
#define AT91_SDRAMC NOT_ABAILABLE

// Peripheral Input/Output Controllers
#define AT91_PIOA   0xFFFFF200
#define AT91_PIOB   0xFFFFF400
#define AT91_PIOC   0xFFFFF600
#define AT91_PIOD   0xFFFFF800
#define AT91_PIOE   0xFFFFFA00
#define AT91_PIO    AT91_PIOA

//Select POI controllers
#define AT91_PIO_ABCDSR1    0x70    //POI Peripheral Select Register 1
#define AT91_PIO_ABCDSR2    0x74    //POI Peripheral Select Register 2

// Periodic Interval Timer Controller
#define AT91_PITC           0xFFFFFD30

// Bus Matrix
#define AT91_MATRIX         0xFFFFEA00
// TODO: many more registers here...
#define AT91_CCFG_EBICSA    0x128
#define AT91_EBI_CS1A       0x00000002 // EBI CS1 assigned to SDRAM controller
#define AT91_EBI_CS3A       0x00000008 // EBI CS3 uses SmartMedia Logic
#define AT91_EBI_CS4A       0x00000010 // EBI CS4 uses Compact Flash Logic Slot 0
#define AT91_EBI_CS5A       0x00000020 // EBI CS5 uses Compact Flash Logic Slot 1
#define AT91_EBI_DBPUC      0x00000100 // EBI PULLUP Disable D0..15
#define AT91_EBI_3VMEM      0x00010000 // EBI 3.3V memories
#define AT91_EBI_DRIVE      0x00020000 // EBI High drive
#define AT91_DDR_DRIVE      0x00040000 // DDR2 High drive

// Static Memory Controller
#define AT91_SMC            0xFFFFE800

// Programmable I/O Delays up to 4ns
#define AT91_SMC_DELAY1     0xC0 // D0..7
#define AT91_SMC_DELAY2     0xC4 // D8..15
#define AT91_SMC_DELAY3     0xC8 // D16..D23
#define AT91_SMC_DELAY4     0xCC // D24..D31
#define AT91_SMC_DELAY5     0xD0 // A0..A7
#define AT91_SMC_DELAY6     0xD4 // A8..A15
#define AT91_SMC_DELAY7     0xD8 // A16..A23
#define AT91_SMC_DELAY8     0xDC // A24..A25

// Watchdog
#define AT91_WD             0xFFFFFD40

// Real Time Timer Controller
#define AT91_RTTC           0xFFFFFD20

// TC - Timer Counter
#define AT91_TC     0xFFF7C000
#define AT91_TC3    (0xFFFD4000 - 0xFFF7C000)
#define AT91_TC4    (AT91_TC3 + AT91_TC_TC_SIZE)
#define AT91_TC5    (AT91_TC3 + 2 * AT91_TC_TC_SIZE)

// UDP - UDP Device Port
#define AT91_UDP    0xFFF78000

// TWI - Two Wire Interface
#define AT91_TWI0   0xFFF84000
#define AT91_TWI1   0xFFF88000
#define AT91_TWI    AT91_TWI0

// USART
#define AT91_USART0 0xFFF8C000
#define AT91_USART1 0xFFF90000
#define AT91_USART2 0xFFF94000
#define AT91_USART3 0xFFF98000

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

//Reset Controller (RSTC)
#define AT91_RST            0xFFFFFD00

// DEBUG serial channel
#define AT91_DBG            0xFFFFEE00

//#define AT91_PIO_PSR_DRXD   (1 << 30)     // Debug UART Receive
//#define AT91_PIO_PSR_DTXD   (1 << 31)     // Debug UART Transmit

// Define USART4 to be the debug UART. It is similar enough to a USART
// that both the hal_diag and interrupt driven driver will work.
// However trying to change parity, start/stop bits etc will not work.
#define CYGNUM_HAL_INTERRUPT_USART4 CYGNUM_HAL_INTERRUPT_DBG
#define AT91_USART4 AT91_DBG
#define AT91_USART_RXD4 AT91_DBG_DRXD
#define AT91_USART_TXD4 AT91_DBG_DTXD

#ifndef __ASSEMBLER__
#ifdef CYGBLD_HAL_ARM_AT91_BAUD_DYNAMIC
extern cyg_uint32 hal_at91_us_baud(cyg_uint32 baud);
#define AT91_US_BAUD(baud) hal_at91_us_baud(baud)
#endif
#endif // __ASSEMBLER__

// SSC - Synchronous Serial Controller
#define AT91_SSC0   0xFFF9C000
#define AT91_SSC1   0xFFFA0000
#define AT91_SSC    AT91_SSC0


// EMAC - Ethernet Medium Access Controller
#define AT91_EMAC   0xFFFBC000

//SPI - Serial Peripheral Interface
#define AT91_SPI0   0xFFFA4000
#define AT91_SPI1   0xFFFA8000
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

// ADC - Analog to Digital Converter (G45: TSADC=Touch Screen ADC)
#define AT91_ADC    0xFFFB0000

/******************************************************************************
 * Power Management Controller
 *
 * ***************************************************************************/
#define AT91_PMC    0xFFFFFC00

//Address of all registers
#define AT91_PMC_SCER_DDRCK         (1 << 2) // DDR Clock
#define AT91_PMC_SCER_UHP           (1 << 6) // USB Host Clock
#define AT91_PMC_SCER_PCK7          (1 << 7) // Programmable Clock Output
#define AT91_PMC_SCER_PCK0          (1 << 8) // Programmable Clock Output
#define AT91_PMC_SCER_PCK1          (1 << 9) // Programmable Clock Output
#define AT91_PMC_SCER_PCK4          (1 << 10) // Programmable Clock Output
#define AT91_PMC_SCER_PCK5          (1 << 11) // Programmable Clock Output





#define ID_FIQ    ( 0) /**< \brief Advanced Interrupt Controller (FIQ) */
#define ID_SYS    ( 1) /**< \brief System Controller Interrupt (SYS) */
#define ID_DBGU   ( 2) /**< \brief Debug Unit Interrupt (DBGU) */
#define ID_PIT    ( 3) /**< \brief Periodic Interval Timer Interrupt (PIT) */
#define ID_WDT    ( 4) /**< \brief Watchdog timer Interrupt (WDT) */
#define ID_SMC    ( 5) /**< \brief Multi-bit ECC Interrupt (SMC) */
#define ID_PIOA   ( 6) /**< \brief Parallel I/O Controller A (PIOA) */
#define ID_PIOB   ( 7) /**< \brief Parallel I/O Controller B (PIOB) */
#define ID_PIOC   ( 8) /**< \brief Parallel I/O Controller C (PIOC) */
#define ID_PIOD   ( 9) /**< \brief Parallel I/O Controller D (PIOD) */
#define ID_PIOE   (10) /**< \brief Parallel I/O Controller E (PIOE) */
#define ID_SMD    (11) /**< \brief SMD Soft Modem (SMD) */
#define ID_USART0 (12) /**< \brief USART 0 (USART0) */
#define ID_USART1 (13) /**< \brief USART 1 (USART1) */
#define ID_USART2 (14) /**< \brief USART 2 (USART2) */
#define ID_USART3 (15) /**< \brief USART 3 (USART3) */
#define ID_UART0  (16) /**< \brief UART 0 (UART0) */
#define ID_UART1  (17) /**< \brief UART 1 (UART1) */
#define ID_TWI0   (18) /**< \brief Two-Wire Interface 0 (TWI0) */
#define ID_TWI1   (19) /**< \brief Two-Wire Interface 1 (TWI1) */
#define ID_TWI2   (20) /**< \brief Two-Wire Interface 2 (TWI2) */
#define ID_HSMCI0 (21) /**< \brief High Speed Multimedia Card Interface 0 (HSMCI0) */
#define ID_HSMCI1 (22) /**< \brief High Speed Multimedia Card Interface 1 (HSMCI1) */
#define ID_HSMCI2 (23) /**< \brief High Speed Multimedia Card Interface 2 (HSMCI2) */
#define ID_SPI0   (24) /**< \brief Serial Peripheral Interface 0 (SPI0) */
#define ID_SPI1   (25) /**< \brief Serial Peripheral Interface 1 (SPI1) */
#define ID_TC0    (26) /**< \brief Timer Counter 0 (ch. 0, 1, 2) (TC0) */
#define ID_TC1    (27) /**< \brief Timer Counter 1 (ch. 3, 4, 5) (TC1) */
#define ID_PWM    (28) /**< \brief Pulse Width Modulation Controller (PWM) */
#define ID_ADC    (29) /**< \brief Touch Screen ADC Controller (ADC) */
#define ID_DMAC0  (30) /**< \brief DMA Controller 0 (DMAC0) */
#define ID_DMAC1  (31) /**< \brief DMA Controller 1 (DMAC1) */
#define ID_UHPHS  (32) /**< \brief USB Host High Speed (UHPHS) */
#define ID_UDPHS  (33) /**< \brief USB Device High Speed (UDPHS) */
#define ID_GMAC   (34) /**< \brief Gigabit Ethernet MAC (GMAC) */
#define ID_EMAC   (35) /**< \brief Ethernet MAC (EMAC) */
#define ID_LCDC   (36) /**< \brief LCD Controller (LCDC) */
#define ID_ISI    (37) /**< \brief Image Sensor Interface (ISI) */
#define ID_SSC0   (38) /**< \brief Synchronous Serial Controller 0 (SSC0) */
#define ID_SSC1   (39) /**< \brief Synchronous Serial Controller 1 (SSC1) */
#define ID_CAN0   (40) /**< \brief CAN controller 0 (CAN0) */
#define ID_CAN1   (41) /**< \brief CAN controller 1 (CAN1) */
#define ID_SHA    (42) /**< \brief Secure Hash Algorithm (SHA) */
#define ID_AES    (43) /**< \brief Advanced Encryption Standard (AES) */
#define ID_TDES   (44) /**< \brief Triple Data EncryptionStandard (TDES) */
#define ID_TRNG   (45) /**< \brief True Random Number Generator (TRNG) */
#define ID_ARM    (46) /**< \brief Performance Monitor Unit (ARM) */
#define ID_IRQ    (47) /**< \brief Advanced Interrupt Controller (IRQ) */
#define ID_FUSE   (48) /**< \brief Fuse Controller (FUSE) */
#define ID_MPDDRC (49) /**< \brief MPDDR controller (MPDDRC) */

#define ID_PERIPH_COUNT (50) /**< \brief Number of peripheral IDs */






#define AT91_PMC_PCER_FIQ           (1 << 0) // Advanced Interrupt Controller FIQ
#define AT91_PMC_PCER_SYSC          (1 << 1) // System Controller Interrupt
#define AT91_PMC_PCER_DBGU          (1 << 2) // Debug Unit Interrupt
//#define AT91_PMC_PCER_PIOA          (1 << 2) // Parallel IO Controller
#define AT91_PMC_PCER_PIOB          (1 << 3) // Parallel IO Controller
#define AT91_PMC_PCER_PIOC          (1 << 4) // Parallel IO Controller
#define AT91_PMC_PCER_PIOD          (1 << 5) // Parallel IO Controller
#define AT91_PMC_PCER_TRNG          (1 << 6) // True Random Generator
#define AT91_PMC_PCER_US0           (1 << 7) // USART 0
#define AT91_PMC_PCER_US1           (1 << 8) // USART 1
#define AT91_PMC_PCER_US2           (1 << 9) // USART 2
#define AT91_PMC_PCER_US3           (1 <<10) // USART 3
#define AT91_PMC_PCER_HSMCI0        (1 <<11) // High Speed Multimedia Card Interface 0
#define AT91_PMC_PCER_TWI           (1 <<12) // Two-Wire Interface 0
#define AT91_PMC_PCER_TWI1          (1 <<13) // Two-Wire Interface 1
#define AT91_PMC_PCER_SPI           (1 <<14) // Serial Peripheral Interface
#define AT91_PMC_PCER_SPI1          (1 <<15) // Serial Peripheral Interface
#define AT91_PMC_PCER_SSC0          (1 <<16) // Serial Synchronous Controller 0
#define AT91_PMC_PCER_SSC1          (1 <<17) // Serial Synchronous Controller 1
#define AT91_PMC_PCER_TC0           (1 <<18) // Timer Counter 0
#define AT91_PMC_PCER_TC1           (1 <<18) // Timer Counter 1
#define AT91_PMC_PCER_TC2           (1 <<18) // Timer Counter 2
#define AT91_PMC_PCER_TC3           (1 <<18) // Timer Counter 3
#define AT91_PMC_PCER_TC4           (1 <<18) // Timer Counter 4
#define AT91_PMC_PCER_TC5           (1 <<18) // Timer Counter 5
#define AT91_PMC_PCER_PWM           (1 <<19) // Pulse Width Modulation Controller
#define AT91_PMC_PCER_ADC           (1 <<20) // Analog-to-Digital Converter
#define AT91_PMC_PCER_DMAC          (1 <<21) // DMA Controller 0
#define AT91_PMC_PCER_UHP           (1 <<22) // USB Host Port
#define AT91_PMC_PCER_LCDC          (1 <<23) // LCD Controller
#define AT91_PMC_PCER_AC97C         (1 <<24) // AC97 Controller
#define AT91_PMC_PCER_EMAC          (1 <<25) // Ethernet MAC
#define AT91_PMC_PCER_ISI           (1 <<26) // Image Sensor Interface
#define AT91_PMC_PCER_UDHS          (1 <<27) // USB Device High Speed
#define AT91_PMC_PCER_HSMCI1        (1 <<29) // High Speed Multimedia Card Interface 1
#define AT91_PMC_PCER_IRQ0          (1 <<31) // Advanced Interrupt Controller IRQ0

#define AT91_PMC_MOR                0x20     // Main Oscillator Register
#define AT91_PMC_MOR_MOSCEN         (1 << 0) // Main Oscillator Enable
#define AT91_PMC_MOR_OSCBYPASS      (1 << 1) // Main Oscillator Bypass
#define AT91_PMC_MOR_OSCCOUNT(x)    ((x) << 8) // Slow clocks ticks

#define AT91_PMC_MCFR               0x24     // Main Clock Frequency Register
#define AT91_PMC_PLLRA              0x28
#define AT91_PMC_PLLR               AT91_PMC_PLLRA
#define AT91_PMC_PLLR_DIV(x)       ((x) <<  0)  // PLL Devide
#define AT91_PMC_PLLR_PLLCOUNT(x)  ((x) <<  8)  // PLL Count
#define AT91_PMC_PLLR_MUL(x)       ((x) << 16)  // PLL Devide
#define AT91_PMC_PLLR_OUT_0        (0 << 14)
#define AT91_PMC_PLLR_OUT_1        (1 << 14)
#define AT91_PMC_PLLR_OUT_2        (2 << 14)
#define AT91_PMC_PLLR_OUT_3        (3 << 14)
#define AT91_PMC_MCKR              0x30     // Master Clock Register
#define AT91_PMC_MCKR_SLOW_CLK     (0 << 0) // Slow clock selected
#define AT91_PMC_MCKR_MAIN_CLK     (1 << 0) // Main clock selected
#define AT91_PMC_MCKR_PLLA_CLK     (2 << 0) // PLLA clock selected
#define AT91_PMC_MCKR_UPLL_CLK     (3 << 0) // UPLL clock selected /* T.B.D New in g45 */
#define AT91_PMC_MCKR_PRES_CLK     (0 << 2) // divide by 1
#define AT91_PMC_MCKR_PRES_CLK_2   (1 << 2) // divide by 2
#define AT91_PMC_MCKR_PRES_CLK_4   (2 << 2) // divide by 4
#define AT91_PMC_MCKR_PRES_CLK_8   (3 << 2) // divide by 8
#define AT91_PMC_MCKR_PRES_CLK_16  (4 << 2) // divide by 16
#define AT91_PMC_MCKR_PRES_CLK_32  (5 << 2) // divide by 32
#define AT91_PMC_MCKR_PRES_CLK_64  (6 << 2) // divide by 64

#define AT91_PMC_PCKR0  0x40  // Programmable Clock Register 0
#define AT91_PMC_PCKR1  0x44  // Programmable Clock Register 1
#define AT91_PMC_IER    0x60 // Interrupt Enable Register
#define AT91_PMC_IDR    0x64 // Interrupt Disable Register
#define AT91_PMC_SR     0x68 // Status Register
#define AT91_PMC_PLLICPR     0x80 // PLL Charge Pump Current Register
#define AT91_PMC_SR_MOSCS   (1 << 0) // Main oscillator stable
#define AT91_PMC_SR_LOCKA   (1 << 1) // PLL Locked A /* SAMA5D3-0001.ADD */
#define AT91_PMC_SR_MCKRDY  (1 << 3) // MCK is ready to be enabled
#define AT91_PMC_SR_LOCKU   (1 << 6) // PLL Locked U /* SAMA5D3-0001.ADD */
#define AT91_PMC_SR_PCK0RDY (1 << 8) // Pad clock 0 is ready to be enabled
#define AT91_PMC_SR_PCK1RDY (1 << 9) // Pad clock 1 is ready to be enabled
#define AT91_PMC_IMR    0x6c // Interrupt Mask Register

/* ----------------------------------------------------------------------------
 * PIN define
 *   #define AT91_PIN(_ctrl_, _periph_, _pin_)
 *      _ctrl_   : PIO Control
 *             0 : Control A      1 : Control B
 *             2 : Control C      3 : Control D
 *             4 : Control E
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
#define AT91_EMAC_ERX2      AT91_PIN(0, 1, 8)  // EMAC 0 Receive Data 2
#define AT91_EMAC_ERX3      AT91_PIN(0, 1, 9)  // EMAC 0 Receive Data 3
#define AT91_USART_SCK3     AT91_PIN(0, 1, 22) // Serial port #3 clock
#define AT91_USART_RTS3     AT91_PIN(0, 1, 23) // Serial port #3 Ready To Send
#define AT91_USART_CTS3     AT91_PIN(0, 1, 24) // Serial port #3 Clear To Send
#define AT91_PWM_PWM3       AT91_PIN(0, 1, 25) // Pulse Width Modulation 3
#define AT91_TC_TIOB2       AT91_PIN(0, 1, 26) // Timer #2 signal B
#define AT91_EMAC_ETXER     AT91_PIN(0, 1, 27) // EMAC 0 Transmit Error
#define AT91_EMAC_ERXCK     AT91_PIN(0, 1, 28) // EMAC 0 Receive Clock
#define AT91_EMAC_ECRS      AT91_PIN(0, 1, 29) // EMAC 0 Carrier Sense
#define AT91_EMAC_ECOL      AT91_PIN(0, 1, 30) // EMAC 0 Collision Detected
#define AT91_PCK_PCK0       AT91_PIN(0, 1, 31) // Programmable Clock Output 0

//*****************************************************************************
// CONTROL B
// PIO Controller B Peripheral A
#define AT91_SPI_MISO       AT91_PIN(1, 0, 0) // SPI 0 Input
#define AT91_SPI_MOSI       AT91_PIN(1, 0, 1) // SPI 0 Output
#define AT91_SPI_SPCK       AT91_PIN(1, 0, 2) // SPI 0 Clock
#define AT91_SPI_NPCS0      AT91_PIN(1, 0, 3) // SPI 0 Chip select 0.
#define AT91_USART_TXD1     AT91_PIN(1, 0, 4) // Serial port #1 TxD
#define AT91_USART_RXD1     AT91_PIN(1, 0, 5) // Serial port #1 RxD
#define AT91_USART_TXD2     AT91_PIN(1, 0, 6) // Serial port #2 TxD
#define AT91_USART_RXD2     AT91_PIN(1, 0, 7) // Serial port #2 RxD
#define AT91_USART_TXD3     AT91_PIN(1, 0, 8) // Serial port #3 TxD
#define AT91_USART_RXD3     AT91_PIN(1, 0, 9) // Serial port #3 RxD
#define AT91_TWI1_TWD       AT91_PIN(1, 0, 10) // Two Wire 1 Data
#define AT91_TWI1_TWCK      AT91_PIN(1, 0, 11) // Two Wire 1 Clock
#define AT91_DBG_DRXD       AT91_PIN(1, 0, 30) // Debug UART Receive
#define AT91_DBG_DTXD       AT91_PIN(1, 0, 31) // Debug UART Transmit
#define AT91_SPI1_MISO      AT91_PIN(1, 0, 14) // SPI 1 Input
#define AT91_SPI1_MOSI      AT91_PIN(1, 0, 15) // SPI 1 Output
#define AT91_SPI1_SPCK      AT91_PIN(1, 0, 16) // SPI 1 Clock
#define AT91_SPI1_NPCS0     AT91_PIN(1, 0, 17) // SPI 1 Chip select 0.
#define AT91_USART_TXD0     AT91_PIN(1, 0, 19) // Serial port #0 TxD
#define AT91_USART_RXD0     AT91_PIN(1, 0, 18) // Serial port #0 RxD
#define AT91_ISI_D0         AT91_PIN(1, 0, 20) // Image Sensor Interface Data 0
#define AT91_ISI_D1         AT91_PIN(1, 0, 21) // Image Sensor Interface Data 1
#define AT91_ISI_D2         AT91_PIN(1, 0, 22) // Image Sensor Interface Data 2
#define AT91_ISI_D3         AT91_PIN(1, 0, 23) // Image Sensor Interface Data 3
#define AT91_ISI_D4         AT91_PIN(1, 0, 24) // Image Sensor Interface Data 4
#define AT91_ISI_D5         AT91_PIN(1, 0, 25) // Image Sensor Interface Data 5
#define AT91_ISI_D6         AT91_PIN(1, 0, 26) // Image Sensor Interface Data 6
#define AT91_ISI_D7         AT91_PIN(1, 0, 27) // Image Sensor Interface Data 7
#define AT91_ISI_PCLK       AT91_PIN(1, 0, 28) // Image Sensor Interface Pixel Clock
#define AT91_ISI_VSYNC      AT91_PIN(1, 0, 29) // Image Sensor Interface Vertical Sync
#define AT91_ISI_HSYNC      AT91_PIN(1, 0, 30) // Image Sensor Interface Horizontal Sync
#define AT91_ISI_MCLK       AT91_PIN(1, 0, 31) // Image Sensor Interface Master Clock

// PIO Controller B Peripheral B
#define AT91_ISI_D8         AT91_PIN(1, 1, 8)  // Image Sensor Interface Data 8
#define AT91_ISI_D9         AT91_PIN(1, 1, 9)  // Image Sensor Interface Data 9
#define AT91_ISI_D10        AT91_PIN(1, 1, 10) // Image Sensor Interface Data 10
#define AT91_ISI_D11        AT91_PIN(1, 1, 11) // Image Sensor Interface Data 11
#define AT91_USART_CTS0     AT91_PIN(1, 1, 15) // Serial port #0 Clear To Send
#define AT91_USART_SCK0     AT91_PIN(1, 1, 16) // Serial port #0 clock
#define AT91_USART_RTS0     AT91_PIN(1, 1, 17) // Serial port #0 Ready To Send
#define AT91_SPI_NPCS1      AT91_PIN(1, 1, 18) // SPI 0 Chip select 1.
#define AT91_SPI_NPCS2      AT91_PIN(1, 1, 19) // SPI 0 Chip select 2.
#define AT91_PCK_PCK1       AT91_PIN(1, 1, 31) // Programmable Clock Output 1

//*****************************************************************************
// CONTROL C
// PIO Controller C Peripheral A
#define AT91_NANDALE        AT91_PIN(2, 0, 4)  //NAND Flash
#define AT91_NANDCLE        AT91_PIN(2, 0, 5)  //NAND Flash
#define AT91_NCS2           AT91_PIN(2, 0, 13) //Chip select #2
#define AT91_NCS3           AT91_PIN(2, 0, 14) //Chip select #3
#define AT91_NCS4           AT91_PIN(2, 0, 10) //Chip select #4
#define AT91_NCS5           AT91_PIN(2, 0, 11) //Chip select #5

//*****************************************************************************
// CONTROL D
// PIO Controller D Peripheral A
#define AT91_AC97RX         AT91_PIN(3, 0, 6)  // AC97 RX
#define AT91_AC97TX         AT91_PIN(3, 0, 7)  // AC97 TX
#define AT91_AC97FS         AT91_PIN(3, 0, 8)  // AC97 FS
#define AT91_AC97CK         AT91_PIN(3, 0, 9)  // AC97 CK
#define AT91_SPI1_NPCS2     AT91_PIN(3, 0, 18) // SPI 1 Chip select 2.
#define AT91_SPI1_NPCS3     AT91_PIN(3, 0, 19) // SPI 1 Chip select 3.
#define AT91_SPI_NPCS1X     AT91_PIN(3, 0, 24) // SPI 0 Chip select 1 (again).
#define AT91_SPI_NPCS2X     AT91_PIN(3, 0, 25) // SPI 0 Chip select 2 (again).

// PIO Controller D Peripheral B
#define AT91_INT_IRQ        AT91_PIN(3, 1, 18) // IRQ
#define AT91_INT_FIQ        AT91_PIN(3, 1, 19) // FIQ
#define AT91_SPI_NPCS3      AT91_PIN(3, 1, 27) // SPI 0 Chip select 3.
#define AT91_SPI1_NPCS1     AT91_PIN(3, 1, 28) // SPI 1 Chip select 1.

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

#endif //CYGONCE_HAL_PLF_IO_SAMA5D3_H

