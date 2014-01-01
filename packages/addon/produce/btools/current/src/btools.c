#include <pkgconf/system.h>
#include <pkgconf/btools.h>
#include <cyg/infra/diag.h>
#include <stdlib.h>

#define	DEFAULT_IP_ADDRESS	"10.0.0.10"


int main( int argc, char *argv[] ) {
	diag_printf("Yes, Tools running\r\n");
	return 0;
}
