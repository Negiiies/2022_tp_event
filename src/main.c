/*
 * E89 Pedagogical & Technical Lab
 * project:     learning liblapin
 * created on:  2022-09-29 - 14:39 +0200
 * 1st author:  Élise C. Philippe - eriizu
 * description: events on a window
 */

#include <lapin.h>
#include "stu.h"
struct display {
    t_bunny_window *ds_win;
    t_bunny_pixelarray *ds_px;
    t_bunny_position pos;
};

void blit_at_origin(struct display *ds)
{
    t_bunny_position pos;

    pos.x = 0;
    pos.y = 0;
    bunny_blit(&ds->ds_win->buffer, &ds->ds_px->clipable, &pos);
    bunny_display(ds->ds_win);
}

t_bunny_response my_key_event_response(t_bunny_event_state state,
                           t_bunny_keysym keycode,
                           void *data)
{
    struct display *ds;

    ds = data;
    if (state == GO_UP)
        return (GO_ON);
    if (keycode == BKS_ESCAPE)
        return (EXIT_ON_SUCCESS);
    else if (keycode == BKS_Z)
        ds->pos.y -= 1;
    //printf("this is the Z key");
    else if (keycode == BKS_S)
        ds->pos.y += 1;
    //printf("this is the S key");
    else if (keycode == BKS_Q)
        ds->pos.x -= 1;
    //printf("this is the Q key");
    else if (keycode == BKS_D)
        ds->pos.x += 1;
    //printf("this is the D key");
    printf("keycode: %d\n", keycode);
    clear_pixelarray(ds->ds_px, BLACK);
    put_pixel(ds->ds_px, &ds->pos, WHITE);
    //((int *) ds->ds_px->pixels)[400 * 200 + keycode] = WHITE;
    blit_at_origin(ds);
    return (GO_ON);
}

int main(void)
{
    struct display display;

    display.pos.x = 400;
    display.pos.y = 400;
    display.ds_win = bunny_start(800, 800, false, "fl: tp event");
    display.ds_px = bunny_new_pixelarray(800, 800);
    blit_at_origin(&display);
    clear_pixelarray(display.ds_px, BLACK);
    bunny_set_key_response(my_key_event_response);
    bunny_loop(display.ds_win, 30, &display);
    bunny_stop(display.ds_win);
    return (0);
}
