#ifndef _ZED_OLED_H_INCLUDED
#define _ZED_OLED_H_INCLUDED

#define ZED_OLED_W 128
#define ZED_OLED_H 32

struct zedoled_data;

struct zedoled_data* zedoled_get(void);
int zedoled_initialize(struct zedoled_data* inst);
void zedoled_free(struct zedoled_data* inst);
void zedoled_all_on(struct zedoled_data* inst);
void zedoled_all_off(struct zedoled_data* inst);
void zedoled_normal(struct zedoled_data* inst);
void zedoled_inverse(struct zedoled_data* inst);
void zedoled_fill(struct zedoled_data* inst);
void zedoled_clear(struct zedoled_data* inst);
void zedoled_update(struct zedoled_data* inst);
void zedoled_set_pixel(struct zedoled_data* inst,
                       unsigned int x,
                       unsigned int y,
                       unsigned char state);


#endif
