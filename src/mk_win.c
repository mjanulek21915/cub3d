#include "main.h"

int mk_win(t_xvar **mlx, void **win, int size_x, int size_y, char *title)
{
    if (!(*mlx = mlx_init()))
    {
        fprintf(stderr, "mlx_init fail\n");
        return (0);
    }
    if (!(*win = mlx_new_window(*mlx, size_x, size_y, title)))
    {
        fprintf(stderr, "mlx_new_window fail\n");
        return (0);
    }

}