/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 04:05:42 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/30 04:05:45 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__draw_bg(char *img_addr, int *indx_s, int col_1, int col_2)
{
	char				*pixel;
	int					a;
	int					b;
	float				c_p[2];

	a = indx_s[5];
	c_p[0] = indx_s[5];
	c_p[1] = (c_p[0] * indx_s[2]) + (indx_s[5]);
	while (a < indx_s[5] * (indx_s[2] - 2))
	{
		b = 0;
		while (b < indx_s[5] - (indx_s[4] / 8))
		{
			pixel = img_addr + a + b;
			*(int *)pixel = get_next_color(c_p, a + b, col_1, col_2);
			b += indx_s[4] / 8;
		}
		a += indx_s[5];
	}
}
