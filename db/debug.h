#ifndef __DEBUG_H__
#define __DEBUG_H__

#define mapsize 1000

#include "main.h"

typedef struct	s_cell
{
	int is_plane;
	db_plane *plane;
}				db_cell;

typedef struct	s_map
{
	db_cell **x_cell;
	db_cell **y_cell;

}				db_map;


typedef struct  s_redraw
{
	void *mlx;
    void *win;
    t_sprite *sprite;
}				db_request;


int db_mk_sprite(void *mlx, t_sprite **sprite, int size_x, int size_y, int pos_x, int pos_y, PIXEL color);
void db_test_redraw(void *mlx, void *win, t_sprite *sprite, int delta_x, int delta_y);
int db_mk_headings(db_headings **headings, int size_x);

#endif