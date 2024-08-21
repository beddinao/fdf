/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:54:37 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/30 04:09:09 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// /// / implementation of the Bresenham's algorithm
//
void	get_nextline_pixel(float *m_arr, float *f_arr, float *m, float *f)
{
	float				t;

	t = (*m - m_arr[0]) / (m_arr[1] - m_arr[0]);
	*f = (f_arr[0] * (1. - t)) + (f_arr[1] * t);
	*m += 1;
}

void	adapt_to_map(float ***points, int a, int b, int *indx_s)
{
	int						h;
	int						w;

	indx_s[2] = (indx_s[0] * 2) + 800;
	indx_s[3] = (indx_s[1] * 2) + 1300;
	if (indx_s[3] > 2400)
		indx_s[3] = 2400;
	if (indx_s[2] > 1400)
		indx_s[2] = 1400;
	h = indx_s[2] / 5;
	w = indx_s[3] / 5;
	points[a][b][1] = __calc_new_range(a, make_darray(0, indx_s[0]),
			make_darray(h, indx_s[2] - h));
	points[a][b][0] = __calc_new_range(b, make_darray(0, indx_s[1]),
			make_darray(w, indx_s[3] - w));
}

void	adapt_to_map_again(float ***points, int *indx_s, int margin)
{
	int							a;
	int							b;
	float						x[2];
	float						y[2];

	a = 0;
	get_points_range(points, indx_s, x, y);
	while (a < indx_s[0])
	{
		b = 0;
		while (b < indx_s[1])
		{
			points[a][b][0] = __calc_new_range(points[a][b][0],
					make_darray(x[0], x[1]),
					make_darray(indx_s[3] / margin,
						indx_s[3] - (indx_s[3] / margin)));
			points[a][b][1] = __calc_new_range(points[a][b][1],
					make_darray(y[0], y[1]),
					make_darray(indx_s[2] / margin,
						indx_s[2] - (indx_s[2] / margin)));
			b += 1;
		}
		a += 1;
	}
}

void	__projection(float ***points, int *indx_s, int margin)
{
	float				x;
	float				y;
	int					a;
	int					b;

	a = 0;
	while (a < indx_s[0])
	{
		b = 0;
		while (b < indx_s[1])
		{
			points[a][b][0] += points[a][b][2];
			points[a][b][1] -= points[a][b][2];
			x = points[a][b][0];
			y = points[a][b][1];
			points[a][b][0] = ((x / 1.3) + (y * 1.2)) - (indx_s[2] / 2.5);
			points[a][b][1] = ((y - x) / 3) + (indx_s[2] / 1.5);
			points[a][b][0] += points[a][b][2];
			points[a][b][1] -= points[a][b][2];
			b += 1;
		}
		a += 1;
	}
	adapt_to_map_again(points, indx_s, margin);
}

int	get_next_color(float *m_arr, float m, int start_color, int end_color)
{
	int					colors[3][3];

	colors[0][0] = start_color >> 16;
	colors[0][1] = (start_color & 0xFFFF) >> 8;
	colors[0][2] = start_color & 0xFF;
	colors[1][0] = end_color >> 16;
	colors[1][1] = (end_color & 0xFFFF) >> 8;
	colors[1][2] = end_color & 0xFF;
	colors[2][0] = (int)__calc_new_range(m, make_darray(m_arr[0], m_arr[1]),
			make_darray(colors[0][0], colors[1][0]));
	colors[2][1] = (int)__calc_new_range(m, make_darray(m_arr[0], m_arr[1]),
			make_darray(colors[0][1], colors[1][1]));
	colors[2][2] = (int)__calc_new_range(m, make_darray(m_arr[0], m_arr[1]),
			make_darray(colors[0][2], colors[1][2]));
	return ((colors[2][0] << 16) + (colors[2][1] << 8) + colors[2][2]);
}

/*
 
	0x398848
	- 0x39 (>> 16)
	- 0x88 (& 0xFFFF) >> 8
	- 0x48 (& 0xFF)
 
*/
