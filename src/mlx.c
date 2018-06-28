/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:11:44 by aherrera          #+#    #+#             */
/*   Updated: 2018/06/25 19:21:59 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftl.h"

static t_img		*create_img(t_mlx *mlx)
{
	t_img	*f;

	f = (t_img *)malloc(sizeof(t_img));
	f->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	f->bpp = 0;
	f->line_size = 0;
	f->endian = 0;
	f->add = mlx_get_data_addr(f->img, &f->bpp, &f->line_size, &f->endian);
	return (f);
}

void				dst_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->f->img);
	exit(0);
}

void				reset_mlx(t_mlx *mlx)
{
	mlx->scale = 1;
	mlx->off_x = 0;
	mlx->off_y = 0;
	mlx->mou_x = 0;
	mlx->mou_y = 0;
	mlx->mode = 0;
	mlx->mode_c = 0;
	mlx->i = 128;
}

t_mlx				*create_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "FdF");
	mlx->scale = 1;
	mlx->off_x = 0;
	mlx->off_y = 0;
	mlx->mou_x = 0;
	mlx->mou_y = 0;
	mlx->mode = 0;
	mlx->mode_c = 0;
	mlx->i = 128;
	mlx->f = create_img(mlx);
	return (mlx);
}
