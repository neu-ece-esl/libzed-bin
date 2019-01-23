#ifndef _AXI_UARTLITE_H_INCLUDED
#define _AXI_UARTLITE_H_INCLUDED

struct axi_uartlite_data;

struct axi_uartlite_data* axiuartlite_get(unsigned long uart_base);
void axiuartlite_free(struct axi_uartlite_data* inst);
int axiuartlite_rxfifo_full(struct axi_uartlite_data* inst);
int axiuartlite_rxfifo_empty(struct axi_uartlite_data* inst);
int axiuartlite_txfifo_full(struct axi_uartlite_data* inst);
int axiuartlite_txfifo_empty(struct axi_uartlite_data* inst);
int axiuartlite_send_bytes(struct axi_uartlite_data* inst,
                           unsigned char* buf,
                           unsigned int size,
                           unsigned char block);
int axiuartlite_send_byte(struct axi_uartlite_data* inst,
                          unsigned char byte);
int axiuartlite_recv_byte(struct axi_uartlite_data* inst,
                          unsigned char* byte);
int axiuartlite_recv_bytes(struct axi_uartlite_data* inst,
                           unsigned char* buf,
                           unsigned int size,
                           unsigned char block);
void axiuartlite_set_max_wait(struct axi_uartlite_data* inst,
                              unsigned int maxWait);


#endif
