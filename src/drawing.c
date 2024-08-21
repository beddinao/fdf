/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:28:45 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/30 04:05:34 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/// // / preparing for the bresenham algorithm

void	calc_line(char *img_addr, int *indx_s, float *start, float *end)
{
	if (calculate_distance(start, end))
		draw_line_y(img_addr, indx_s, start, end);
	else
		draw_line_x(img_addr, indx_s, start, end);
}

void	__draw_lines(float ***points, char *img_addr, int *indx_s)
{
	int					a;
	int					b;

	a = 0;
	while (a < indx_s[0])
	{
		b = 0;
		while (b < indx_s[1] - 1)
		{
			calc_line(img_addr, indx_s, points[a][b], points[a][b + 1]);
			b += 1;
		}
		a += 1;
	}
	a = 0;
	while (a < indx_s[0] - 1)
	{
		b = 0;
		while (b < indx_s[1])
		{
			calc_line(img_addr, indx_s, points[a][b], points[a + 1][b]);
			b += 1;
		}
		a += 1;
	}
}

int	__draw_points(float ***points, char *img_addr, int *indx_s)
{
	int					a;
	int					b;
	char				*pixel;

	a = 0;
	while (a < indx_s[0])
	{
		b = 0;
		while (b < indx_s[1])
		{
			if (points[a][b][3] < 0)
				points[a][b][3] = 0xffffff;
			pixel = get_mlx_img_pixel(img_addr, indx_s,
					points[a][b][0], points[a][b][1]);
			if (!pixel)
				return (0);
			*(int *)pixel = (int)points[a][b][3];
			b += 1;
		}
		a += 1;
	}
	return (1);
}

void	__draw(float ***points, char *img_addr, int *indx_s)
{
	int								e;

	__projection(points, indx_s, 20);
	e = __draw_points(points, img_addr, indx_s);
	if (e)
		__draw_lines(points, img_addr, indx_s);
	free_multible(points, indx_s);
	if (!e)
		exit(1);
}
