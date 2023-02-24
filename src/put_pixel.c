/*
 * E89 Pedagogical & Technical Lab
 * project:     pixel
 * created on:  2023-01-12 - 10:58 +0100
 * 1st author:  dylan.le - dylan.le
 * description: put
 */

#include <lapin.h>
#include "stu.h"
void put_pixel(t_bunny_pixelarray *pxa,
               t_bunny_position *pos,
               unsigned int color)
{
    int i = 0;
    int width = pxa->clipable.clip_width;
    int height = pxa->clipable.clip_height;
    int px = width * height;
    unsigned int* tmp = (unsigned int* )pxa-> pixels;
    i = (width * pos-> y) + pos->x;
    if (i >= 0 &&  i < px)
        {
            tmp[i] = color;
        }
    i += 1;
}
