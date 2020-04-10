#include "main.h"

int mk_img(void *mlx, void **img, void **ptr, int size_x, int size_y)
{
    int bpp;
    int line_size;
    int endianness;

    if (!(*img = mlx_new_image(mlx, size_x, size_y)))
    {
        fprintf(stderr, "mlx_new_image fail\n");
        return (0);
    }
    if (!(*ptr = mlx_get_data_addr(*img, &bpp, &line_size, &endianness)))
    {
        fprintf(stderr, "mlx_new_image fail\n");
        return (0);
    }
    return 1;
}