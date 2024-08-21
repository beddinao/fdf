/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:46:57 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/30 05:42:07 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	cancel_d(float ***points, int *indx_s)
{
	free_multible(points, indx_s);
	exit(1);
}

int	__onit(t_ptrs *__ptrs)
{
	(void)__ptrs;
	exit(0);
}

int	escape_handle(int key_code, t_ptrs *__ptrs)
{
	if (key_code == 53)
		__onit(__ptrs);
	return (0);
}

int	main(int argc, char **argv)
{
	t_ptrs				*__ptrs;
	float				***points;
	char				*img_addr;
	int					indx_s[8];

	if (argc != 2) {
		printf("usage ./fdf /path/to/fdf_file\n");
		exit(1);
	}
	points = setup_indx_s(argv[1], indx_s);
	if (!points)
		exit(1);
	__ptrs = malloc(sizeof(t_ptrs *));
	img_addr = __init(__ptrs, indx_s);
	if (!img_addr)
		cancel_d(points, indx_s);
	__draw_bg(img_addr, indx_s, 0x161616, 0x000000);
	__draw(points, img_addr, indx_s);
	mlx_put_image_to_window(__ptrs->mlx_ptr,
		__ptrs->mlx_win, __ptrs->mlx_img, 0, 0);
	mlx_hook(__ptrs->mlx_win, 17, 0, __onit, __ptrs);
	mlx_hook(__ptrs->mlx_win, 2, 0, escape_handle, __ptrs);
	mlx_loop(__ptrs->mlx_ptr);
}
