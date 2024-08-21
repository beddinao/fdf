/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:15:32 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/30 03:47:04 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_color(char	*line, int *i, float *num)
{
	*num = -1;
	if (line[*i] == ',')
	{
		*i += 1;
		if (line[*i] == '0')
			*i += 1;
		if (line[*i] == 'x')
			*i += 1;
		*i += get_hex_integer(line + *i, sizeof_str(line + *i, ' ', 0),
				&num);
	}
}

void	get_line_cordinates(char *line, float ***points, int *indx_s, int a)
{
	int						i;
	int						b;
	int						c;

	b = 0;
	i = 0;
	points[a][b][2] = 0;
	while (line[i] && b < indx_s[1] && line[i] != '\n')
	{
		get_neg(line[i], &c, &i);
		if (is_digit(line[i]))
		{
			sub_int(line, &i, &points[a][b][2], c);
			adapt_to_map(points, a, b, indx_s);
			put_color(line, &i, &points[a][b][3]);
			b += 1;
			if (b < indx_s[1] && a < indx_s[0])
				points[a][b][2] = 0;
		}
		i += 1;
	}
}

int	put_cordinates(char *file, float ***points, int *indx_s)
{
	char				*tmp_buffer;
	int					fd;
	int					a;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	a = 0;
	while (a < indx_s[0])
	{
		tmp_buffer = get_next_line(fd);
		if (!tmp_buffer)
			break ;
		get_line_cordinates(tmp_buffer, points, indx_s, a);
		free(tmp_buffer);
		a += 1;
	}
	close(fd);
	return (1);
}
