#ifndef	CYGONCE_HAL_IO_H_
#define CYGONCE_HAL_IO_H_
#define CYGHWR_HAL_SAMA5D3_USART1_RXD CYGHWR_HAL_SAMA5D3_PIN(B,28,PER_A,OPENDRAIN,NONE,NONE,NA,(0))
cyg_uint32 pin = CYGHWR_HAL_SAMA5D3_PIN(port, bit, mode, md, pupd, if, int, conf);

cyg_uint32 pin = CYGHWR_HAL_SAMA5D3_PIN_OUT(port, bit, md, pupd);

cyg_uint32 pin = CYGHWR_HAL_SAMA5D3_PIN_IN(port, bit, md, pupd, if, int);

CYGHWR_HAL_SAMA5D3_PIN_SET(pin);

CYGHWR_HAL_SAMA5D3_GPIO_OUT(pin, val);

CYGHWR_HAL_SAMA5D3_GPIO_IN(pin, val);

cyg_uint32 CYGHWR_HAL_ATMEL_CLOCK_ENABLE(pid);

CYGHWR_HAL_ATMEL_CLOCK_DISABLE(pid);
#endif // CYGONCE_HAL_IO_H_
