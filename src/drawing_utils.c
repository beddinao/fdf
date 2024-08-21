/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:45:29 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/30 04:06:47 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_x(char *img_addr, int *indx_s, float *start, float *end)
{
	float				x;
	float				y;
	float				x_p[2];
	float				y_p[2];
	char				*pixel;

	setup_ranges(start, end, x_p, y_p);
	x = x_p[0];
	while (x <= x_p[1])
	{
		get_nextline_pixel(x_p, y_p, &x, &y);
		pixel = get_mlx_img_pixel(img_addr, indx_s, x - 1, y);
		if (!pixel)
			break ;
		*(int *)pixel = get_next_color(x_p, x - 1,
				(int)start[3], (int)end[3]);
	}
}

void	draw_line_y(char *img_addr, int *indx_s, float *start, float *end)
{
	float				x;
	float				y;
	float				x_p[2];
	float				y_p[2];
	char				*pixel;

	setup_ranges(start, end, x_p, y_p);
	y = y_p[0];
	while (y <= y_p[1])
	{
		get_nextline_pixel(y_p, x_p, &y, &x);
		pixel = get_mlx_img_pixel(img_addr, indx_s, x, y - 1);
		if (!pixel)
			break ;
		*(int *)pixel = get_next_color(y_p, y - 1,
				(int)start[3], (int)end[3]);
	}
}

char	*get_mlx_img_pixel(char *img_addr, int *indx_s, int x, int y)
{
	char				*pixel;

	pixel = img_addr + (y * indx_s[5]) + (x * (indx_s[4] / 8));
	if (pixel > img_addr + (indx_s[5]
			* (indx_s[2] - 10)) + (int)(indx_s[5] * 0.99)
			|| pixel < img_addr)
		pixel = NULL;
	return (pixel);
}

int	calculate_distance(float *start, float *end)
{
	float					_d[2];

	_d[0] = end[0] - start[0];
	_d[1] = end[1] - start[1];
	if (_d[1] > _d[0])
		return (1);
	return (0);
}

void	setup_ranges(float *start, float *end, float *x_p, float *y_p)
{
	x_p[0] = start[0];
	x_p[1] = end[0];
	y_p[0] = start[1];
	y_p[1] = end[1];
}
