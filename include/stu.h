/*
 * E89 Pedagogical & Technical Lab
 * project:     stu
 * created on:  2023-01-30 - 09:32 +0100
 * 1st author:  dylan.le - dylan.le
 * description: include
 */

#ifndef STU_H_

#define STU_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void put_pixel(t_bunny_pixelarray *pxa,
                t_bunny_position *pos,
                unsigned int color);

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);

#endif /*STU_H_*/
