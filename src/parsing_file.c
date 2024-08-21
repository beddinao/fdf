/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:57:39 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/30 05:41:44 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	***allocate_arr(int *indx_s)
{
	int					a;
	float				***points;
	int					b;

	points = malloc(indx_s[0] * sizeof(float **));
	if (!points)
		return (NULL);
	a = 0;
	while (a < indx_s[0])
	{
		points[a] = malloc(indx_s[1] * sizeof(float *));
		b = 0;
		while (b < indx_s[1])
		{
			points[a][b] = malloc(4 * sizeof(float));
			b += 1;
		}
		a += 1;
	}
	return (points);
}

int	get_char_accurance(char *buf, char del, char end)
{
	int					res;
	int					a;
	int					b;
	int					c;

	a = -1;
	b = 1;
	c = 0;
	res = 0;
	while (++a > -1 && buf[a] != '\0' && buf[a] != end)
	{
		if (buf[a] != del)
		{
			if (buf[a] == ',' && buf[++a] != del)
				c = 1;
			if (!check_char_acc(buf[a], &b, &res, c))
				return (-1);
		}
		else
		{
			b = 1;
			c = 0;
		}
	}
	return (res);
}

int	check_fdf_file(char *file, int *indx_s)
{
	int					fd;
	char				*buffer;
	int					points_count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	indx_s[1] = -1;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		points_count = get_char_accurance(buffer, ' ', '\n');
		free(buffer);
		if (points_count < 0
			|| !adapt_points(indx_s, &points_count))
			break ;
		indx_s[0] += 1;
	}
	close(fd);
	if (points_count < 0)
		return (0);
	return (1);
}

float	***setup_indx_s(char *file, int *indx_s)
{
	float			***points;

	indx_s[0] = 0;
	if (!check_fdf_file(file, indx_s))
		return (NULL);
	if (indx_s[0] < 2 || indx_s[1] < 2)
		return (NULL);
	points = allocate_arr(indx_s);
	if (!points)
		return (NULL);
	if (!put_cordinates(file, points, indx_s))
	{
		free_multible(points, indx_s);
		return (NULL);
	}
	return (points);
}
