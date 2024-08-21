/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 05:43:33 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/30 05:43:36 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_char_acc(char ch, int *b, int *res, int c)
{
	if (*b)
	{
		*res += 1;
		*b = 0;
	}
	if (ch && !c && (!is_digit(ch) && ch != '-'))
		return (0);
	return (1);
}

int	adapt_points(int *indx_s, int *points_count)
{
	if (indx_s[1] < 0)
		indx_s[1] = *points_count;
	else if (indx_s[1] != *points_count)
	{
		*points_count = -1;
		return (0);
	}
	return (1);
}
