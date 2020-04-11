#include "debug.h"
#include "main.h"

#define SPEED 1

int	key_hook(int key, db_request *request)
{
	struct timespec tms;
	struct timespec tms2;
	if (clock_gettime (CLOCK_REALTIME, &tms))
		fprintf(stderr, "time fail");

	if (key==0xFF1B)
		exit(0);
	if (key == 65362)
	{
		fprintf(stderr, "UP\n");
		request->sprite->pos_y -= SPEED;
		db_test_redraw(request->mlx, request->win, request->sprite, 0, -SPEED);
	}
	if (key == 65364)
	{
		request->sprite->pos_y += SPEED;
		fprintf(stderr, "DOWN\n");
		db_test_redraw(request->mlx, request->win, request->sprite, 0, +SPEED);
	}
	if (key == 65361)
	{
		fprintf(stderr, "LEFT\n");
		request->sprite->pos_x -= SPEED;
		db_test_redraw(request->mlx, request->win, request->sprite, -SPEED, 0);
	}
	if (key == 65363)
	{
		fprintf(stderr, "RIGHT\n");
		request->sprite->pos_x += SPEED;
		db_test_redraw(request->mlx, request->win, request->sprite, +SPEED, 0);
	}
	if (clock_gettime (CLOCK_REALTIME, &tms2))
		fprintf(stderr, "time fail 2");
	fprintf(stderr, "frame time = %lums\n", (tms2.tv_nsec - tms.tv_nsec)/1000);
}

// int	mouse_hook(int button,int x,int y, void *p)
// {
//   printf("Mouse in Win2, button %d at %dx%d.\n",button,x,y);
// }

int	mouse_move_hook(int x,int y, db_request *request)
{
	struct timespec tms;
	struct timespec tms2;
	if (clock_gettime (CLOCK_REALTIME, &tms))
		fprintf(stderr, "time fail");
	request->sprite->pos_x = x;
	request->sprite->pos_y = y;
	db_test_redraw(request->mlx, request->win, request->sprite, 
	request->sprite->pos_x, request->sprite->pos_y);
	mlx_flush_event(request->mlx);
	if (clock_gettime (CLOCK_REALTIME, &tms2))
		fprintf(stderr, "time fail 2");
	fprintf(stderr, "frame time = %lums\n", (tms2.tv_nsec - tms.tv_nsec)/1000);

}


#define SIZE_X 241
#define SIZE_Y 30

#define MAP_SCALE_X 1000
#define MAP_SCALE_Y 1000

#define TITLE "cesi est un titre"

#define TEST 1

int main()
{
	struct timespec tms;
	db_headings *headings;
	t_xvar *mlx;
	void *win;
	t_sprite *background;
	t_sprite *player;
	int key2 = 13;

	db_request request;

	int i;

	i = 0;

	if (TEST == 1)
	{
		db_mk_headings(&headings, SIZE_X);
		while (i < headings->az_hdg_count)
		{
			printf("hdg :%d mask :%d value:%f\n", i, headings->az_hdg[i]->test, headings->az_hdg[i]->offs_mult);
			i++;
		}
		printf("headings_count : %d\n", headings->az_hdg_count);
	}


	if (TEST == 0)
	{
	PIXEL red = get_color_32(0, 145, 15, 15);
	PIXEL green = get_color_32(0, 15, 145, 15);
	PIXEL blue = get_color_32(0, 15, 15, 145);
	PIXEL grey = get_color_32(200, 200, 200, 200);


	if (!(mk_win(&mlx, &win, SIZE_X, SIZE_Y, TITLE)))
		return 0;
	mlx->do_flush = 0;
	if (!(db_mk_sprite(mlx, &background, SIZE_X, SIZE_Y, 0, 0, grey)))
		return 0;
	if (!(db_mk_sprite(mlx, &player, 10, 10, 0, 0, grey)))
		return 0;
	draw_sprite(mlx,win, background);
	flush(mlx);
	request.mlx = mlx;
	request.win = win;
	request.sprite = background;
	mlx_key_hook(win,key_hook, &request);
	mlx_hook(win, MotionNotify, PointerMotionMask, mouse_move_hook, &request);
	mlx_loop(mlx);
	sleep(2);
	}
}






// int main()
// {
//     void *mlx;
//     void *window;
//     fprintf(stderr, "mlx_init\n");

//     if (!(mlx = mlx_init()))
//     {
//         fprintf(stderr, "mlx_init fail\n");
//         return (0);
//     }
//     fprintf(stderr, "mlx_new_window\n");
//     if (!(window = mlx_new_window(mlx, SIZE_X, SIZE_Y, "test_window")))
//     {
//         fprintf(stderr, "mlx_new_window fail\n");
//         return (0);
//     }
//     mlx_string_put(mlx, window, 40, 40, BLUE, "cesi est un string");
//     sleep(4);
//     fill_screen(mlx, window, SIZE_X, SIZE_Y, BLUE);
//     fill_screen(mlx, window, SIZE_X, SIZE_Y, 0);
//     mlx_clear_window(mlx, window);
//     mlx_key_hook(window,key_hook,0);
//     mlx_loop(mlx);
// }
