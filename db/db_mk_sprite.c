#include "main.h"

void db_mk_sprite_fill(char *buff, PIXEL color, int size)
{
    PIXEL *temp_buff;

    size = size -1;
    temp_buff = (PIXEL *) buff;
    while (size--)
    {
        *temp_buff++ = color;
    }
}

int db_mk_sprite(void *mlx, t_sprite **sprite, int size_x, int size_y, int pos_x, int pos_y, PIXEL color)
{
    if (!(*sprite = malloc(sizeof(t_sprite))))
        return (0);
    (*sprite)->pos_x = pos_x;
    (*sprite)->pos_y = pos_y;
    (*sprite)->size_x = size_x;
    (*sprite)->size_y = size_y;
    if (!(mk_img(mlx, &((*sprite)->img), &((*sprite)->ptr), size_x, size_y)))
    {
        fprintf(stderr, "db_mk_sprite mk_img_fail");
        return (0);
    }
    db_mk_sprite_fill((*sprite)->ptr, color, (size_x * size_y));
    return (1);
}
