#include "main.h"

void draw_sprite(void *mlx, void* win, t_sprite *sprite)
{
    mlx_put_image_to_window(mlx, win, sprite->img, sprite->pos_x, sprite->pos_y);
}