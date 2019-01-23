#ifndef _AXI_QUAD_SPI_H_INCLUDED
#define _AXI_QUAD_SPI_H_INCLUDED

struct axi_qspi_data;

struct axi_qspi_data* axi_qspi_get(unsigned long base_addr);
void axi_qspi_free(struct axi_qspi_data* inst);
void axi_qspi_send_buffer(struct axi_qspi_data* inst,
                          unsigned char* buf,
                          unsigned int size);
void axi_qspi_send_byte(struct axi_qspi_data* inst,
                        unsigned char data);
void axi_qspi_reset(struct axi_qspi_data* inst);
int axi_qspi_send_receive_buffer(struct axi_qspi_data* inst,
                                 unsigned char* txBuf,
                                 unsigned int txSize,
                                 unsigned char* rxBuf);
int axi_qspi_send_receive_byte(struct axi_qspi_data* inst,
                               unsigned char data,
                               unsigned char* recv);

#endif
