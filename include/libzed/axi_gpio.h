#ifndef _AXI_GPIO_H_INCLUDED
#define _AXI_GPIO_H_INCLUDED

struct axi_gpio_data;

// Initialize a GPIO controller
struct axi_gpio_data* axigpio_get(unsigned long gpio_base_addr,
                                  unsigned char has_gpio2);

// De-initialize GPIO controller
void axigpio_free(struct axi_gpio_data* gpio_controller);

// Set a group of GPIOs direction to outputs
int axigpio_group_output(struct axi_gpio_data* gpio_controller,
                         unsigned int group_mask,
                         unsigned char channel_num);
// Set a group of GPIOs direction to inputs
int axigpio_group_input(struct axi_gpio_data* gpio_controller,
                        unsigned int group_mask,
                        unsigned char channel_num);
// Set a group of GPIOs values to HIGH
int axigpio_group_set(struct axi_gpio_data* gpio_controller,
                      unsigned int group_mask,
                      unsigned char channel_num);
// Set a group of GPIOs values to LOW
int axigpio_group_clear(struct axi_gpio_data* gpio_controller,
                        unsigned int group_mask,
                        unsigned char channel_num);
// Set a single GPIO direction to output
int axigpio_single_output(struct axi_gpio_data* gpio_controller,
                          unsigned int gpio_num,
                          unsigned char channel_num);
// Set a single GPIO direction to input
int axigpio_single_input(struct axi_gpio_data* gpio_controller,
                         unsigned int gpio_num,
                         unsigned char channel_num);
// Set a single GPIO value to HIGH
int axigpio_single_set(struct axi_gpio_data* gpio_controller,
                       unsigned int gpio_num,
                       unsigned char channel_num);
// Set a single GPIO value to LOW
int axigpio_single_clear(struct axi_gpio_data* gpio_controller,
                         unsigned int gpio_num,
                         unsigned char channel_num);
// Get the value of the entire register for a channel
int axigpio_channel_get(struct axi_gpio_data* gpio_controller,
                        unsigned char channel_num);
// Set the value of the entire register for a channel
int axigpio_channel_set(struct axi_gpio_data* gpio_controller,
                        unsigned int value,
                        unsigned char channel_num);
// Get the value of a single GPIO
int axigpio_single_get(struct axi_gpio_data* gpio_controller,
                       unsigned int gpio_num,
                       unsigned char channel_num);

#endif
