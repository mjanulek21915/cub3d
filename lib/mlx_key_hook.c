/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:22:06 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/26 16:22:23 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_key_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[KeyPress].hook = funct;
	win->hooks[KeyPress].param = param;
	win->hooks[KeyPress].mask = KeyPressMask;
	return (0);
}
