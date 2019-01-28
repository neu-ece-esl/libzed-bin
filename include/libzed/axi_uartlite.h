#ifndef _AXI_UARTLITE_H_INCLUDED
#define _AXI_UARTLITE_H_INCLUDED

/** @file axi_uartlite.h
    UART Convenience functions
*/

struct axi_uartlite_data;

/** @brief Initialize UART.
    @param uart_base UART base address
    @return a pointer to an axi_uartlite_data struct */
struct axi_uartlite_data* axiuartlite_get(unsigned long uart_base);

/** @brief De-initialize UART.
    @param inst a pointer to an axi_uartlite_data struct */
void axiuartlite_free(struct axi_uartlite_data* inst);

/** @brief Checks if the RX FIFO is full.
    @param inst a pointer to an axi_uartlite_data struct
    @return 1 if the FIFO is full, 0 if not full or a negative value in case of error */
int axiuartlite_rxfifo_full(struct axi_uartlite_data* inst);

/** @brief Checks if the RX FIFO is empty.
    @param inst a pointer to an axi_uartlite_data struct
    @return 1 if the FIFO is empty, 0 if not empty or a negative value in case of error */
int axiuartlite_rxfifo_empty(struct axi_uartlite_data* inst);

/** @brief Checks if the TX FIFO is full.
    @param inst a pointer to an axi_uartlite_data struct
    @return 1 if the FIFO is full, 0 if not full or a negative value in case of error */
int axiuartlite_txfifo_full(struct axi_uartlite_data* inst);

/** @brief Checks if the TX FIFO is full.
    @param inst a pointer to an axi_uartlite_data struct
    @return 1 if the FIFO is empty, 0 if not empty or a negative value in case of error */
int axiuartlite_txfifo_empty(struct axi_uartlite_data* inst);

/** @brief Send one or more bytes.
    This function tries to send a number of bytes. There are two modes for sending data:
    blocking and non-blocking.
    In the non-blocking mode, the function will attempt to send the data at once. If the
    UART's TX FIFO becomes full while sending, the transmission is aborted and the number of
    successfully sent bytes is returned.
    In the blocking mode, the function blocks until all the data gets sent successfully, except if
    a timeout of 100k cycles (by default) is exceeded, in which case the transmission is aborted.
    @param inst a pointer to an axi_uartlite_data struct
    @param buf a pointer to a array of bytes to be sent
    @param size the buffer's size (amount of bytes being sent)
    @param block whether to block until all bytes are sent or not
    @return a negative value in case of failure, or the number of bytes successfully sent
*/
int axiuartlite_send_bytes(struct axi_uartlite_data* inst,
                           unsigned char* buf,
                           unsigned int size,
                           unsigned char block);

/** @brief Send a single byte.
    Tries to send a single byte. If the TX FIFO is full, this will result in an error.
    @param inst a pointer to an axi_uartlite_data struct
    @param byte the byte to be sent
    @return 0 in case of success, a negative value otherwise
*/
int axiuartlite_send_byte(struct axi_uartlite_data* inst,
                          unsigned char byte);

/** @brief Receive a single byte.
    Tries to receive a single byte. If the RX FIFO is empty, this will result in an error.
    @param inst a pointer to an axi_uartlite_data struct
    @param byte a pointer to a destination in which to save the received byte
    @return 0 in case of success, a negative value otherwise. */
int axiuartlite_recv_byte(struct axi_uartlite_data* inst,
                          unsigned char* byte);

/** @brief Receive one or more bytes.
    This function will try to receive a number of bytes. If the blocking mode is used,
    it will try to wait until the specified number of bytes is successfully received, unless
    a maximum timeout of 100k cycles (by default) is reached. If not using the blocking mode, the function
    will abort the reception of bytes in case the RX FIFO becomes empty and will return the number
    of bytes that were successfully received.
    @param inst a pointer to an axi_uartlite_data struct
    @param buf a pointer to an array to receive the bytes
    @param size the number of bytes to receive
    @param block use blocking mode or not
    @return the number of bytes successfully received or a negative value in case of an error */
int axiuartlite_recv_bytes(struct axi_uartlite_data* inst,
                           unsigned char* buf,
                           unsigned int size,
                           unsigned char block);

/** @brief Modify the max wait in cycles.
    @param inst a pointer to an axi_uartlite_data struct
    @param maxWait the number of cycles to set as maximum wait timeout */
void axiuartlite_set_max_wait(struct axi_uartlite_data* inst,
                              unsigned int maxWait);


#endif
