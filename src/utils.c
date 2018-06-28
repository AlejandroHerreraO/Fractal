/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:11:47 by aherrera          #+#    #+#             */
/*   Updated: 2018/06/26 10:46:03 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftl.h"

int		check(char *s, t_mlx *mlx)
{
	if (!s)
		return (0);
	if (!ft_strcmp(s, "mandelbrot"))
		mlx->fract = mbrot;
	else if (!ft_strcmp(s, "julia"))
		mlx->fract = julia;
	else if (!ft_strcmp(s, "bship"))
		mlx->fract = bship;
	else if (!ft_strcmp(s, "extra1"))
		mlx->fract = cust1;
	else if (!ft_strcmp(s, "extra2"))
		mlx->fract = cust2;
	else
		return (0);
	return (1);

}

t_th	thr_make(t_mlx *mlx, int i)
{
	t_th	new_t;

	new_t.t_id = i;
	new_t.mlx = mlx;
	return (new_t);
}

void	zoom(t_mlx *mlx, int n)
{
	if (n == 1)
	{
		mlx->off_x -= (mlx->mou_x * EP) / mlx->scale;
		mlx->off_y -= (mlx->mou_y * EP) / mlx->scale;
		mlx->scale /= 2;
	}
	else
	{
		mlx->scale += mlx->scale;
		mlx->off_x += mlx->mou_x * EP / mlx->scale;
		mlx->off_y += mlx->mou_y * EP / mlx->scale;
	}
}

void	colorize(t_mlx *mlx, int n)
{
	if (n == 0)
		mlx->mode_c--;
	else
		mlx->mode_c++;
	if (mlx->mode_c < 0)
		mlx->mode_c = COLORS;
	if (mlx->mode_c > COLORS)
		mlx->mode_c = 0;
}
