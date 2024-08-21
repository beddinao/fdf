/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 04:08:10 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/30 04:08:13 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	__calc_new_range(int old_value, int *old_range, int *new_range)
{
	float					res;

	if (old_value == old_range[0])
		res = new_range[0];
	else
	{
		res = (((old_value - old_range[0])
					* (new_range[1] - new_range[0]))
				/ (old_range[1] - old_range[0]))
			+ new_range[0];
	}
	free(old_range);
	free(new_range);
	return (res);
}

void	get_points_range(float ***points, int *indx_s, float *x, float *y)
{
	int							a;
	int							b;

	a = 0;
	x[0] = points[0][0][0];
	x[1] = points[0][1][0];
	y[0] = points[0][0][1];
	y[1] = points[1][0][1];
	while (a < indx_s[0])
	{
		b = 0;
		while (b < indx_s[1])
		{
			if (points[a][b][0] < x[0])
				x[0] = points[a][b][0];
			else if (points[a][b][0] > x[1])
				x[1] = points[a][b][0];
			if (points[a][b][1] < y[0])
				y[0] = points[a][b][1];
			else if (points[a][b][1] > y[1])
				y[1] = points[a][b][1];
			b += 1;
		}
		a += 1;
	}
}
