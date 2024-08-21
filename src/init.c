/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:55:39 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/30 05:48:56 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 
 indx_s[0]	=	y points count
 indx_s[1]	=	x points count
 indx_s[2]	= 	window height
 indx_s[3]	=	window width
 indx_s[4]	=	bits_per_pixel
 indx_s[5]	=	line_size
 indx_s[6]	=	endian type

*/

static	void	cancel_d(t_ptrs *__ptrs, int con_1, int con_2)
{
	if (con_1)
		mlx_destroy_window(__ptrs->mlx_ptr, __ptrs->mlx_win);
	if (con_2)
		free(__ptrs->mlx_ptr);
	free(__ptrs);
	exit (1);
}

char	*__init(t_ptrs *__ptrs, int *indx_s)
{
	if (!__ptrs)
		return (NULL);
	__ptrs->mlx_ptr = mlx_init();
	if (!__ptrs->mlx_ptr)
		cancel_d(__ptrs, 0, 0);
	__ptrs->mlx_win = mlx_new_window(__ptrs->mlx_ptr,
			indx_s[3], indx_s[2], "FDF->wireframe module");
	if (!__ptrs->mlx_win)
		cancel_d(__ptrs, 0, 1);
	__ptrs->mlx_img = mlx_new_image(__ptrs->mlx_ptr, indx_s[3], indx_s[2]);
	if (!__ptrs->mlx_img)
		cancel_d(__ptrs, 1, 1);
	return (mlx_get_data_addr(__ptrs->mlx_img,
			&indx_s[4], &indx_s[5], &indx_s[6]));
}
