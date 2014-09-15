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

	// ����ȷ�� ���Ϊ �͡�
	HAL_WRITE_UINT32( AT91C_PIOB_CODR , CONTROL_OUT_IO_B);
	// ��ȷ����Щ�˿��� IO �ڡ�
	HAL_WRITE_UINT32( AT91C_PIOB_PER , CONTROL_OUT_IO_B);
	// ȷ���������
	HAL_WRITE_UINT32( AT91C_PIOB_OER , CONTROL_OUT_IO_B);

	// A PORT ����ȷ�� ���Ϊ �͡�
	HAL_WRITE_UINT32( AT91C_PIOA_CODR , CONTROL_OUT_IO_A);
	// ��ȷ����Щ�˿��� IO �ڡ�
	HAL_WRITE_UINT32( AT91C_PIOA_PER , CONTROL_OUT_IO_A);
	// ȷ���������
	HAL_WRITE_UINT32( AT91C_PIOA_OER , CONTROL_OUT_IO_A);

	// FIX for KSZ8995
	ksz8995_fix();

	// ��1600�еľ�����������������λ��Э��������by ycwang.
	ASSERT_nRESET_PHY;
	// �ر� USB DEVICE�豸��Դ
	ASSERT_nRESET_PWR;
	// ����ģ�鸴λ
	ASSERT_nRESET_GPRS;

	hal_delay_us(10000);
	DEASSERT_nRESET_PHY;
	// 20131209�����û������ӳ٣�PHY ID���ܻ��޷���ȷ��ȡ����������RW1020 V3Ӳ���ϳ��֡�
	// 20140613��PHY ID��ȷ��ȡ��Ҫ������ӳ��ȶ������ֲ���˵KSZ8041NL��Ҫ10ms����������RW1600V3Ӳ���ϳ��֡�
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
