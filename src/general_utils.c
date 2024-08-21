/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:55:21 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/29 00:55:22 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_power(int nb, int power)
{
	if (!power)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

void	swap(int *a, int *b)
{
	int			t;

	t = *a;
	*a = *b;
	*b = t;
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

float	***free_multible(float ***arr, int *indx_s)
{
	int				a;
	int				b;

	a = 0;
	while (a < indx_s[0])
	{
		b = 0;
		while (b < indx_s[1])
		{
			free(arr[a][b]);
			b += 1;
		}
		free(arr[a]);
		a += 1;
	}
	free(arr);
	return (NULL);
}

int	sizeof_str(char *str, char end, int con)
{
	int				i;

	i = 0;
	while (str[i] != '\0'
		&& str[i] != '\n'
		&& str[i] != end)
		i += 1;
	if (con)
		free(str);
	return (i);
}
