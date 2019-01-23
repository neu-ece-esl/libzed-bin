#ifndef _MMAP_REGS_H_INCLUDED_
#define _MMAP_REGS_H_INCLUDED_


// Read a peripheral register
unsigned int read_reg(char* mapped_region, unsigned int reg_offset);

// Write a peripheral register
void write_reg(char* mapped_region, unsigned int reg_offset, unsigned int value);

// Map peripheral registers to a pointer
char* map_region(unsigned long base_addr, unsigned int region_size);

// Unmap peripheral registers
void unmap_region(char* mapped_region, unsigned int region_size);

// Clear bits in a register
void clear_reg_mask(char* mapped_region, unsigned int reg_offset,
                    unsigned int mask);

// Set bits in a register
void set_reg_mask(char* mapped_region, unsigned int reg_offset,
                  unsigned int mask);

#endif
