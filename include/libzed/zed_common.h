#ifndef _ZED_H_COMMON_INCLUDE
#define _ZED_H_COMMON_INCLUDE

/** @file zed_common.h
    Common constants */

/** @defgroup PERIPHERAL_ADDRESSES FPGA Peripheral Base Addresses
    @{
*/

/** PMOD GPIO controller base address */
#define PMOD_GPIO_ADDR 0x411F0000
/** LED GPIO controller base address */
#define LED_GPIO_ADDR  0x41200000
/** Switches GPIO controller base address */
#define SW_GPIO_ADDR   0x41210000
/** Buttons GPIO controller base address */
#define BTN_GPIO_ADDR  0x41220000
/** OLED SPI controller base address */
#define OLED_SPI_ADDR  0x41230000
/** TIMER 0 base address */
#define TIMER0_ADDR    0x41240000
/** TIMER 1 base address */
#define TIMER1_ADDR    0x41250000
/** Multiplexer 0 (aximux0) base address */
#define MUX0_ADDR      0x41260000
/** Multiplexer 1 (aximux1) base address */
#define MUX1_ADDR      0x41270000
/** TIMER 2 base address */
#define TIMER2_ADDR    0x41280000
/** TIMER 3 base address */
#define TIMER3_ADDR    0x41290000
/** UART base address */
#define UART0_ADDR     0x412A0000

/** @} */

#endif
