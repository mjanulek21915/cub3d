#include "debug.h"

int db_mk_headings(db_headings **headings, int size_x)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int j_step = 1;
	int j_step_step = 0;

	if (!(*headings = malloc(sizeof(db_headings))) || 
	!((*headings)->heading = malloc(sizeof(db_mask *) * (size_x * 4))) || 
	!((*headings)->mask = malloc(sizeof(db_mask) * ((size_x / 2) + (size_x % 2)))))
		return 0;

	(*headings)->masks_count = (size_x / 2) + (size_x % 2);
	(*headings)->headings_count = size_x * 4;

	if (size_x % 2 == 1)
	{
		j_step_step = 1;
	}
	while (i < (*headings)->headings_count)
	{
		if (j == (*headings)->masks_count)
		{
			j_step = -1;
			j = j - j_step_step;
		}
		if (j == -1)
		{
			j_step = 1;
			j = j + 1;
		}
		if (k == size_x)
		{
			k = 0;
			j = 0;
			j_step = 1;
		}
		(*headings)->heading[i] = &((*headings)->mask[j]);
		(*headings)->heading[i]->test = j;
		k++;
		j = j + j_step;
		i++;
	}

	i = 0;
	while (i < (*headings)->masks_count)
	{
		(*headings)->mask[i].offs_mult = (double)i / (*headings)->masks_count;
		i++;
	}
}