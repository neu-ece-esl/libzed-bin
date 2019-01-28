#ifndef _AXI_GPIO_H_INCLUDED
#define _AXI_GPIO_H_INCLUDED

/** @file axi_gpio.h
  GPIO controller convenience functions
*/

struct axi_gpio_data;

/** @brief Initialize a GPIO controller
    @param gpio_base_addr GPIO Controller base address
    @param has_gpio2 Indicates whether secondary channel of controller is used
    @return a pointer to an axi_gpio_data struct */
struct axi_gpio_data* axigpio_get(unsigned long gpio_base_addr,
                                  unsigned char has_gpio2);

/** @brief De-initialize GPIO controller
    @param gpio_controller a pointer to an axi_gpio_data struct */
void axigpio_free(struct axi_gpio_data* gpio_controller);

/** @brief Set a group of GPIOs direction to outputs
    @param gpio_controller a pointer to an axi_gpio_data struct
    @param group_mask bitmask to set pins as output
    @param channel_num GPIO controller channel number
    @return 0 on success */
int axigpio_group_output(struct axi_gpio_data* gpio_controller,
                         unsigned int group_mask,
                         unsigned char channel_num);

/** @brief Set a group of GPIOs direction to inputs
    @param gpio_controller a pointer to an axi_gpio_data struct
    @param group_mask bitmask to set pins as input
    @param channel_num GPIO controller channel number
    @return 0 on success */
int axigpio_group_input(struct axi_gpio_data* gpio_controller,
                        unsigned int group_mask,
                        unsigned char channel_num);

/** @brief Set a group of GPIOs values to HIGH
    @param gpio_controller a pointer to an axi_gpio_data struct
    @param group_mask bitmask to set pins HIGH
    @param channel_num GPIO controller channel number
    @return 0 on success */
int axigpio_group_set(struct axi_gpio_data* gpio_controller,
                      unsigned int group_mask,
                      unsigned char channel_num);

/** @brief Set a group of GPIOs values to LOW
    @param gpio_controller a pointer to an axi_gpio_data struct
    @param group_mask bitmask to set pins LOW
    @param channel_num GPIO controller channel number
    @return 0 on success */
int axigpio_group_clear(struct axi_gpio_data* gpio_controller,
                        unsigned int group_mask,
                        unsigned char channel_num);

/** @brief Set a single GPIO direction to output
    @param gpio_controller a pointer to an axi_gpio_data struct
    @param gpio_num GPIO number <0..7>
    @param channel_num GPIO controller channel number
    @return on success */
int axigpio_single_output(struct axi_gpio_data* gpio_controller,
                          unsigned int gpio_num,
                          unsigned char channel_num);

/** @brief Set a single GPIO direction to input
    @param gpio_controller a pointer to an axi_gpio_data struct
    @param gpio_num GPIO number <0..7>
    @param channel_num GPIO controller channel number
    @return 0 on success */
int axigpio_single_input(struct axi_gpio_data* gpio_controller,
                         unsigned int gpio_num,
                         unsigned char channel_num);

/** @brief Set a single GPIO value to HIGH
    @param gpio_controller a pointer to an axi_gpio_data struct
    @param gpio_num GPIO number <0..7>
    @param channel_num GPIO controller channel number
    @return 0 on success */
int axigpio_single_set(struct axi_gpio_data* gpio_controller,
                       unsigned int gpio_num,
                       unsigned char channel_num);

/** @brief Set a single GPIO value to LOW
    @param gpio_controller a pointer to an axi_gpio_data struct
    @param gpio_num GPIO number <0..7>
    @param channel_num GPIO controller channel number
    @return 0 on success */
int axigpio_single_clear(struct axi_gpio_data* gpio_controller,
                         unsigned int gpio_num,
                         unsigned char channel_num);

/** @brief Get the value of the entire register for a channel
    @param gpio_controller a pointer to an axi_gpio_data struct
    @param channel_num GPIO controller channel number
    @return value of the entire register */
int axigpio_channel_get(struct axi_gpio_data* gpio_controller,
                        unsigned char channel_num);

/** @brief Set the value of the entire register for a channel
    @param gpio_controller a pointer to an axi_gpio_data struct
    @param value value to set retister to
    @param channel_num GPIO controller channel number
    @return 0 on success */
int axigpio_channel_set(struct axi_gpio_data* gpio_controller,
                        unsigned int value,
                        unsigned char channel_num);

/** @brief Get the value of a single gpio
    @param gpio_controller a pointer to an axi_gpio_data struct
    @param gpio_num GPIO number <0..7>
    @param channel_num GPIO controller channel number
    @return current value of the GPIO */
int axigpio_single_get(struct axi_gpio_data* gpio_controller,
                       unsigned int gpio_num,
                       unsigned char channel_num);

#endif
