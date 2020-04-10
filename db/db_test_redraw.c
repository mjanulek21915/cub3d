#include "debug.h"

void db_test_redraw(void *mlx, void *win, t_sprite *sprite, int pos_x, int pos_y)
{
    mlx_clear_window(mlx, win);
    draw_sprite(mlx,win, sprite);
    flush(mlx);
}