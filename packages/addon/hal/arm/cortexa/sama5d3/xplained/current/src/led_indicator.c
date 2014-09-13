#include <pkgconf/system.h>
#include <pkgconf/dev_indicator.h>
#include <cyg/cli/cli.h>
#include <cyg/dev/indicator.h>
#include <cyg/hal/hal_diag.h>
#include <mpd/mpd.h>
#include <stdlib.h>
//#define DEBUG diag_printf
#define DEBUG(fmt, ...)
/*
 * LED的板级设备支持
 */
cyg_handle_t modem_indicator_handle = 0;
cyg_handle_t csq_handle = 0;


static void modem_indicator_onoff(int onoff) {
	if( onoff )
		board_set_leds(1,1);
	else
		board_set_leds(1,0);
}

static void csq1_indicator_onoff(int onoff) {
	if( onoff )
		board_set_leds(2,1);
	else
		board_set_leds(2,0);
}

static void csq_callback(void *context) {
	struct modem_control *mc = (struct modem_control *)context;
	char *csq = getModemTypedInfo(mc, MODEM_SIGNAL);
	int value = atoi(csq);

	if( value > 31 ) {
		SetIndicator(csq_handle, INDICATOR_CSQ_OFF);
	} if( value > 25 ) {
		SetIndicator(csq_handle, INDICATOR_CSQ_FFF);
	} else if (value > 15 ) {
		SetIndicator(csq_handle, INDICATOR_CSQ_FF);
	} else {
		SetIndicator(csq_handle, INDICATOR_CSQ_F);
	}
}

static void prepare_callback(void *context) {
	DEBUG("indicat prepare\r\n");
	SetIndicator(modem_indicator_handle, INDICATOR_PREPARE);
}

static void idle_callback(void *context) {
	DEBUG("indicat available\r\n");
	SetIndicator(modem_indicator_handle, INDICATOR_AVAILABLE);
}

static void connecting_callback(void *context) {
	DEBUG("indicat connecting\r\n");
	SetIndicator(modem_indicator_handle, INDICATOR_CONNECTING);
}
/*
static void connected_callback(void *context) {
	SetIndicator(modem_indicator_handle, INDICATOR_CONNECTED);
}
*/
static void iface_up_callback(void *context) {
	SetIndicator(modem_indicator_handle, INDICATOR_ALWAYS_LIGHT);
}

static void iface_down_callback(void *context) {
	SetIndicator(modem_indicator_handle, INDICATOR_NORMAL);
}

static int led_indcator_commands_register(struct cli_def *cli)
{
	// modem 拨号状态指示灯
	modem_indicator_handle = CreateLedIndicator(modem_indicator_onoff);

	// 信号强度指示灯，初始为全OFF
	csq_handle = CreateLedIndicator(csq1_indicator_onoff);

	SetIndicator(csq_handle, INDICATOR_CSQ_OFF);

	RegisteIndicatorCallback(INDICATOR_MODEM_CSQ, csq_callback);
	RegisteIndicatorCallback(INDICATOR_MODEM_PREPARE, prepare_callback);
	RegisteIndicatorCallback(INDICATOR_MODEM_AVAILABLE, idle_callback);
	RegisteIndicatorCallback(INDICATOR_MODEM_CONNECTING, connecting_callback);
//	RegisteIndicatorCallback(INDICATOR_MODEM_CONNECTED, connected_callback);

	RegisteIndicatorCallback(INDICATOR_INTERFACE_UP, iface_up_callback);
	RegisteIndicatorCallback(INDICATOR_INTERFACE_DOWN, iface_down_callback);

	return 0;
}
CLI_COMMANDS_REGISTER(led_indcator_commands,led_indcator_commands_register);

