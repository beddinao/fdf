/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:50:28 by beddinao          #+#    #+#             */
/*   Updated: 2024/08/21 08:42:56 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include "mlx.h"

typedef struct ptrs
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
}	t_ptrs;

int				is_digit(char c);
int				ft_power(int nb, int power);
int				*make_darray(int a, int b);
int				adapt_points(int *indx_s, int *points_count);
int				check_char_acc(char ch, int *b, int *res, int c);
int				get_next_color(float *m_arr, float m,
					int start_color, int end_color);
int				put_cordinates(char *file, float ***points, int *indx_s);
int				calculate_distance(float *start, float *end);
int				get_hex_integer(char *str, int size, float **res);
int				sizeof_str(char *str, char end, int con);
int				calculate_distance(float *start, float *end);

char			*__init(t_ptrs *mlx_ptrs, int *indx_s);
char			*get_mlx_img_pixel(char *img_addr, int *indx_s, int x, int y);

float			***free_multible(float ***arr, int *indx_s);
float			***setup_indx_s(char *file, int *indx_s);
float			***allocate_arr(int *indx_s);
float			__calc_new_range(int old_value, int *old_range, int *new_range);

void			get_points_range(float ***points, int *indx_s,
					float *x, float *y);
void			get_nextline_pixel(float *m_arr, float *f_arr,
					float *m, float *f);
void			setup_ranges(float *start, float *end, float *x_p, float *y_p);
void			__draw_bg(char *img_addr, int *indx_s, int col_1, int col_2);
void			adapt_to_map(float ***points, int a, int b, int *indx_s);
void			draw_line_x(char *img_addr, int *indx_s,
					float *start, float *end);
void			draw_line_y(char *img_addr, int *indx_s,
					float *start, float *end);
void			__draw(float ***points, char *img_addr,
					int *indx_s);
void			sub_int(char *c, int *i, float *dest, int neg);
void			__projection(float ***points, int *indx_s, int margin);
void			get_neg(char c, int *neg, int *i);
void			swap(int *a, int *b);

#endif
