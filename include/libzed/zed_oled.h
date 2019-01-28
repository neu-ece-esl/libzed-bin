#ifndef _ZED_OLED_H_INCLUDED
#define _ZED_OLED_H_INCLUDED

/** @file zed_oled.h
    Functions for controlling the OLED on the ZedBoard
*/

/** OLED width in pixels */
#define ZED_OLED_W 128

/** OLED height in pixels */
#define ZED_OLED_H 32

struct zedoled_data;

/** @brief Initialize the OLED driver.
    @return a pointer to a zedoled_data struct */
struct zedoled_data* zedoled_get(void);

/** @brief Initialize or re-initialize the OLED hardware controller
    @param inst a pointer to a zedoled_data struct
    @return 0 in case of success or a negative value in case of error */
int zedoled_initialize(struct zedoled_data* inst);

/** @brief De-initialize the OLED driver.
    @param inst a pointer to a zedoled_data struct */
void zedoled_free(struct zedoled_data* inst);

/** @brief Turn all pixels ON.
    @param inst a pointer to a zedoled_data struct */
void zedoled_all_on(struct zedoled_data* inst);

/** @brief Turn all pixels OFF.
    @param inst a pointer to a zedoled_data struct */
void zedoled_all_off(struct zedoled_data* inst);

/** @brief Set OLED to normal mode.
    @param inst a pointer to a zedoled_data struct */
void zedoled_normal(struct zedoled_data* inst);

/** @brief Set OLED to inverse mode.
    @param inst a pointer to a zedoled_data struct */
void zedoled_inverse(struct zedoled_data* inst);

/** @brief Fill (set all pixels to the on state) in the pixel buffer.
    @param inst a pointer to a zedoled_data struct */
void zedoled_fill(struct zedoled_data* inst);

/** @brief Clear (set all pixels to the off state) in the pixel buffer.
    @param inst a pointer to a zedoled_data struct */
void zedoled_clear(struct zedoled_data* inst);

/** @brief Update OLED.
    Draws the pixel buffer to the OLED display.
    @param inst a pointer to a zedoled_data struct */
void zedoled_update(struct zedoled_data* inst);

/** @brief Set a pixel's state in the pixel buffer.
    Call zedoled_update after all modifications are done.
    @param inst a pointer to a zedoled_data struct
    @param x the pixel's x coordinate
    @param y the pixel's y coordinate
    @param state the pixel state (on/off) */
void zedoled_set_pixel(struct zedoled_data* inst,
                       unsigned int x,
                       unsigned int y,
                       unsigned char state);


#endif
