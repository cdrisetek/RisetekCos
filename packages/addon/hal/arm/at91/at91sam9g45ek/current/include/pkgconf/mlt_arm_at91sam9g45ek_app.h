// eCos memory layout - Wed Apr 11 13:49:55 2001

// This is a generated file - do not edit

#ifndef __ASSEMBLER__
#include <cyg/infra/cyg_type.h>
#include <stddef.h>
#endif

// Boot region can be ROM, EBI_NCS0, or SRAM depending on BMS and REMAP.
#define CYGMEM_REGION_boot          (0x0)
#define CYGMEM_REGION_boot_SIZE     (0x00100000)
#define CYGMEM_REGION_boot_ATTR     (CYGMEM_REGION_ATTR_R | CYGMEM_REGION_ATTR_W)

// Internal ROM
#define CYGMEM_REGION_irom          (0x00400000)
#define CYGMEM_REGION_irom_SIZE     (0x10000)
#define CYGMEM_REGION_irom_ATTR     (CYGMEM_REGION_ATTR_R)

// Internal SRAM
#define CYGMEM_REGION_sram0         (0x00300000)
#define CYGMEM_REGION_sram0_SIZE    (0x10000)
#define CYGMEM_REGION_sram0_ATTR    (CYGMEM_REGION_ATTR_R | CYGMEM_REGION_ATTR_W)

// 128MB SDRAM
#define CYGMEM_REGION_sdram         (0x70000000)
#define CYGMEM_REGION_sdram_SIZE    (0x08000000)
#define CYGMEM_REGION_sdram_ATTR    (CYGMEM_REGION_ATTR_R | CYGMEM_REGION_ATTR_W)

// Map region names to eCos names.
#define CYGMEM_REGION_ram       CYGMEM_REGION_sdram
#define CYGMEM_REGION_ram_SIZE  CYGMEM_REGION_sdram_SIZE
#define CYGMEM_REGION_ram_ATTR  CYGMEM_REGION_sdram_ATTR

#ifndef __ASSEMBLER__
extern char CYG_LABEL_NAME (__heap1) [];
#endif
#define CYGMEM_SECTION_heap1 (CYG_LABEL_NAME (__heap1))
#define CYGMEM_SECTION_heap1_SIZE (CYGMEM_REGION_ram + CYGMEM_REGION_ram_SIZE - (size_t) CYG_LABEL_NAME (__heap1))

