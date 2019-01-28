#ifndef _AXI_QUAD_SPI_H_INCLUDED
#define _AXI_QUAD_SPI_H_INCLUDED

/** @file axi_quad_spi.h
    SPI controller convenience functions
*/

struct axi_qspi_data;

/** @brief Initialize a SPI controller.
    @param base_addr Base address of the peripheral
    @return a pointer to an axi_qspi_data struct */
struct axi_qspi_data* axi_qspi_get(unsigned long base_addr);

/** @brief De-initialize SPI controller.
    @param inst a pointer to an axi_qspi_data struct */
void axi_qspi_free(struct axi_qspi_data* inst);

/** @brief Send one or more bytes.
    @param inst a pointer to an axi_qspi_data struct
    @param buf a pointer to an array containing bytes to be sent
    @param size number of bytes to be sent */
void axi_qspi_send_buffer(struct axi_qspi_data* inst,
                          unsigned char* buf,
                          unsigned int size);

/** @brief Send a single byte.
    @param inst a pointer to an axi_qspi_data struct
    @param data the byte to be sent */
void axi_qspi_send_byte(struct axi_qspi_data* inst,
                        unsigned char data);

/** @brief Reset SPI controller.
    @param inst a pointer to an axi_qspi_data struct */
void axi_qspi_reset(struct axi_qspi_data* inst);

/** @brief Simultaneously send and receive one or more bytes.
    @param inst a pointer to an axi_qspi_data struct
    @param txBuf pointer to an array of bytes to be sent
    @param txSize amount of bytes to send/receive
    @param rxBuf a pointer to an array to store received bytes
    @return number of bytes sent/received or a negative value in case of error */
int axi_qspi_send_receive_buffer(struct axi_qspi_data* inst,
                                 unsigned char* txBuf,
                                 unsigned int txSize,
                                 unsigned char* rxBuf);

/** @brief Simultaneously send and receive one byte.
    @param inst a pointer to an axi_qspi_data struct
    @param data the byte to send
    @param recv pointer to location where to store received byte
    @return number of bytes sent/received or a negative value in case of error */
int axi_qspi_send_receive_byte(struct axi_qspi_data* inst,
                               unsigned char data,
                               unsigned char* recv);

#endif
