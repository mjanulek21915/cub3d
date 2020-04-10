#ifndef __MAIN_H__
# define __MAIN_H__

#include	"mlx.h"
#include	"mlx_int.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>

typedef unsigned PIXEL;

typedef struct	s_sprite
{
	int pos_x;
	int pos_y;
    int size_x;
    int size_y;
    void *img;
    void *ptr;
}				t_sprite;


// int	key_hook(int key);
PIXEL get_color_32(int a, int r, int g, int b);
void fill_image_32(char *buff, PIXEL color, int size);
void draw_scene_32(char *buff, char *src, int len);
int mk_win(t_xvar **mlx, void **win, int size_x, int size_y, char *title);
int mk_img(void *mlx, void **img, void **ptr, int size_x, int size_y);
void draw_sprite(void *mlx, void* win, t_sprite *sprite);
void flush(t_xvar *mlx);


#endif