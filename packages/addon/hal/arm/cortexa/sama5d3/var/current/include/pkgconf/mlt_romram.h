#ifndef __ASSEMBLER__
#include <cyg/infra/cyg_type.h>
#include <stddef.h>
#endif
#include <cyg/hal/plf_io_sama5d3.h>

#define CYGMEM_REGION_ram (SDRAM_PHYS_BASE)
#define CYGMEM_REGION_ram_SIZE (SDRAM_SIZE_8M)
#define CYGMEM_REGION_ram_ATTR (CYGMEM_REGION_ATTR_R | CYGMEM_REGION_ATTR_W)
#ifndef __ASSEMBLER__
extern char CYG_LABEL_NAME (__heap1) [];
#endif

#define CYGMEM_SECTION_heap1 (CYG_LABEL_NAME (__heap1))
#define CYGMEM_SECTION_heap1_SIZE ( SDRAM_SIZE_8M )
