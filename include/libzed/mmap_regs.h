#ifndef _MMAP_REGS_H_INCLUDED_
#define _MMAP_REGS_H_INCLUDED_

/** @file mmap_regs.h
    Memory mapping helper functions
*/

/** @brief Read a peripheral register.
    @param mapped_region Pointer to start of a previously mapped region
    @param reg_offset Offset for the register to be read
    @return Register value */
unsigned int read_reg(char* mapped_region, unsigned int reg_offset);

/** @brief Write a peripheral register.
    @param mapped_region Pointer to start of a previously mapped region
    @param reg_offset Offset for the register to be written
    @param value Value to be written */
void write_reg(char* mapped_region, unsigned int reg_offset, unsigned int value);

/** @brief Map peripheral registers to a pointer.
    @param base_addr Base address to be mapped
    @param region_size Size of the region to be mapped
    @return Pointer to start of mapped region */
char* map_region(unsigned long base_addr, unsigned int region_size);

/** @brief Unmap peripheral registers.
    @param mapped_region Pointer to start of a previously mapped region
    @param region_size Size of the mapped region */
void unmap_region(char* mapped_region, unsigned int region_size);

/** @brief Clear bits in a register.
    @param mapped_region Pointer to start of a previously mapped region
    @param reg_offset Offset of the register to be modified
    @param mask Bitmask to be cleared in the register */
void clear_reg_mask(char* mapped_region, unsigned int reg_offset,
                    unsigned int mask);

/** @brief Set bits in a register.
    @param mapped_region Pointer to start of a previously mapped region
    @param reg_offset Offset of the register to be modified
    @param mask Bitmask to be set in the register */
void set_reg_mask(char* mapped_region, unsigned int reg_offset,
                  unsigned int mask);

#endif
