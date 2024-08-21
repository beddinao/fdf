/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_task_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:58:25 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/29 01:09:28 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_integers(char hex_char)
{
	int					c;

	c = 0;
	if (is_digit(hex_char))
		c = hex_char - 48;
	else if (hex_char == 'a' || hex_char == 'A')
		c = 10;
	else if (hex_char == 'b' || hex_char == 'B')
		c = 11;
	else if (hex_char == 'c' || hex_char == 'C')
		c = 12;
	else if (hex_char == 'd' || hex_char == 'D')
		c = 13;
	else if (hex_char == 'e' || hex_char == 'E')
		c = 14;
	else if (hex_char == 'f' || hex_char == 'F')
		c = 15;
	return (c);
}

int	get_hex_integer(char *str, int size, float **res)
{
	int						a;
	int						b;

	a = 0;
	**res = 0;
	while (str && str[a] && a < size)
	{
		b = size - a - 1;
		**res += hex_integers(str[b]) * ft_power(16, a);
		a += 1;
	}
	return (a);
}

void	sub_int(char *c, int *i, float *dest, int neg)
{
	while (c[*i] && is_digit(c[*i]))
	{
		*dest = (*dest * 10) + (c[*i] - 48);
		*i += 1;
	}
	*dest *= neg;
}

void	get_neg(char c, int *neg, int *i)
{
	*neg = 1;
	if (c == '-')
	{
		*neg = -1;
		*i += 1;
	}
}

int	*make_darray(int a, int b)
{
	int					*arr;

	arr = malloc(2 * sizeof(int));
	if (!arr)
		return (0);
	arr[0] = a;
	arr[1] = b;
	return (arr);
}
