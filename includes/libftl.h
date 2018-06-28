/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:18:07 by aherrera          #+#    #+#             */
/*   Updated: 2018/06/26 11:09:20 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTL_H
# define LIBFTL_H
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <pthread.h>
# include <math.h>
# define WIN_H 1200
# define WIN_W 1200
# define BUFF_SIZE 2048
# define EP 0.0033333333
# define PI 3.14159265359
# define THREADS 12
# define COLORS 8

typedef struct			s_img
{
	char				*add;
	void				*img;
	int					bpp;
	int					line_size;
	int					endian;
}						t_img;

typedef struct			s_com
{
	double				r;
	double				i;
}						t_com;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	unsigned long long	scale;
	double long			off_x;
	double long			off_y;
	int					mou_x;
	int					mou_y;
	int					mode;
	int					i;
	int					mode_c;
	int					(*fract)(t_com, t_com, int);
	t_img				*f;
}						t_mlx;

typedef struct			s_th
{
	int					t_id;
	t_mlx				*mlx;
}						t_th;

t_mlx					*create_mlx(void);
void					reset_mlx(t_mlx *mlx);
void					dst_mlx(t_mlx *mlx);
void					extra_key(int key, t_mlx *mlx);
t_com					com_new(float r, float i);
t_com					com_sum(t_com a, t_com b);
t_com					com_mul(t_com a, t_com b);
t_com					com_div(t_com a, t_com b);
float					com_dis(t_com a);
void					draw_fract(t_mlx *mlx);
void					zoom(t_mlx *mlx, int n);
int						mbrot(t_com z, t_com c, int it);
int						bship(t_com z, t_com c, int it);
int						julia(t_com z, t_com c, int it);
int						cust1(t_com z, t_com c, int it);
int						cust2(t_com z, t_com c, int it);
int						check(char *s, t_mlx *mlx);
t_th					thr_make(t_mlx *mlx, int i);
void					colorize(t_mlx *mlx, int n);

#endif
