//==========================================================================
//
//      misc.c
//
//==========================================================================

#include <pkgconf/hal.h>
#include <pkgconf/system.h>
#include CYGBLD_HAL_PLATFORM_H
#include <cyg/hal/platform_cfg.h>
#include <cyg/infra/cyg_type.h>         // base types
#include <cyg/infra/cyg_trac.h>         // tracing macros
#include <cyg/infra/cyg_ass.h>          // assertion macros
#include <cyg/hal/hal_io.h>             // IO macros
#include <cyg/hal/hal_arch.h>           // Register state info
#include <cyg/hal/hal_diag.h>
#include <cyg/hal/hal_intr.h>           // Interrupt names
#include <cyg/infra/diag.h>             // diag_printf
#include <string.h>                     // memset

//----------------------------------------------------------------------------
// Platform specific initialization
// This routine sets the default GPIO condition
void board_port_init(void) {
#if 0
	init_uart0_pio();
	init_uart2_pio();

	// 首先确定 输出为 低。
	HAL_WRITE_UINT32( AT91C_PIOB_CODR , CONTROL_OUT_IO_B);
	// 再确定这些端口是 IO 口。
	HAL_WRITE_UINT32( AT91C_PIOB_PER , CONTROL_OUT_IO_B);
	// 确定是输出。
	HAL_WRITE_UINT32( AT91C_PIOB_OER , CONTROL_OUT_IO_B);

	// A PORT 首先确定 输出为 低。
	HAL_WRITE_UINT32( AT91C_PIOA_CODR , CONTROL_OUT_IO_A);
	// 再确定这些端口是 IO 口。
	HAL_WRITE_UINT32( AT91C_PIOA_PER , CONTROL_OUT_IO_A);
	// 确定是输出。
	HAL_WRITE_UINT32( AT91C_PIOA_OER , CONTROL_OUT_IO_A);

	// FIX for KSZ8995
	ksz8995_fix();

	// 在1600中的经验表明，不做这个复位，协调能力变差。by ycwang.
	ASSERT_nRESET_PHY;
	// 关闭 USB DEVICE设备电源
	ASSERT_nRESET_PWR;
	// 拉底模块复位
	ASSERT_nRESET_GPRS;

	hal_delay_us(10000);
	DEASSERT_nRESET_PHY;
	// 20131209，如果没有这个延迟，PHY ID可能会无法正确读取。该现象在RW1020 V3硬件上出现。
	// 20140613，PHY ID正确读取需要更大的延迟稳定器，手册上说KSZ8041NL需要10ms。该现象在RW1600V3硬件上出现。
	hal_delay_us(100000);

	LED_P0_OFF;
	LED_P1_OFF;
	LED_P2_OFF;
#endif
}
void board_set_leds(int val, int onoff) {
}
//-----------------------------------------------------------------------------
// End of misc.c
