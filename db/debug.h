#ifndef __DEBUG_H__
#define __DEBUG_H__

#define mapsize 1000

#include "main.h"

typedef struct	s_planes
{
	int count;
	db_plane *list;
}				db_planes;

typedef struct	s_plane
{
	double interval;
	double origin;
	void *img;
}				db_plane;


typedef struct	s_mask
{
	int test;
	double dist_mult;
	double offs_mult;
}				db_mask;

typedef struct	s_headings
{
	int masks_count;
	int headings_count;
	db_mask **heading;
	db_mask *mask;
}				db_headings;


typedef struct  s_redraw
{
	void *mlx;
    void *win;
    t_sprite *sprite;
}				db_request;

typedef struct	s_cell
{
	int is_plane;
	db_plane *plane;
}				db_cell;



int db_mk_sprite(void *mlx, t_sprite **sprite, int size_x, int size_y, int pos_x, int pos_y, PIXEL color);
void db_test_redraw(void *mlx, void *win, t_sprite *sprite, int delta_x, int delta_y);
int db_mk_headings(db_headings **headings, int size_x);

#endif