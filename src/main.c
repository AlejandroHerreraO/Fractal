/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:11:30 by aherrera          #+#    #+#             */
/*   Updated: 2018/06/26 11:09:17 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftl.h"

static void		move(t_mlx *mlx, int dir, int scale)
{
	if (dir == 1)
		mlx->off_x -= 0.25 / scale;
	else if (dir == 2)
		mlx->off_x += 0.25 / scale;
	else if (dir == 3)
		mlx->off_y += 0.25 / scale;
	else if (dir == 4)
		mlx->off_y -= 0.25 / scale;
}

static int		hook_keyb(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	ft_putnbr(key);
	if (key == 49)
		mlx->mode = (mlx->mode == 0 ? 1 : 0);
	if (key >= 123 && key <= 126)
		move(mlx, key - 122, mlx->scale);
	if (key == 12 || key == 14)
		colorize(mlx, key - 12);
	if (key == 53)
		dst_mlx(mlx);
	if (key == 69)
		zoom(mlx, 0);
	if (key == 78 && mlx->scale > 1)
		zoom(mlx, 1);
	if (key == 8 && mlx->i > 1)
		mlx->i /= 2;
	if (key == 9)
		mlx->i *= 2;
	if (key == 15)
		reset_mlx(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_fract(mlx);
	return (0);
}

static int		hook_mous(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	(void)x;
	(void)y;
	mlx = (t_mlx *)param;
	if (button == 5 || button == 6)
		zoom(mlx, 0);
	else if ((button == 4 || button == 7) && mlx->scale > 1)
		zoom(mlx, 1);
	if (button == 1)
		mlx->mode = (mlx->mode == 0 ? 1 : 0);
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_fract(mlx);
	return (0);
}

static int		hook_motn(int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx->mou_x = x;
	mlx->mou_y = y;
	if (mlx->mode == 1)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		draw_fract(mlx);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = create_mlx();
	if (ac != 2 || !check(av[1], mlx))
	{
		ft_putendl("usage: fractol [julia|mandelbrot|other]");
		dst_mlx(mlx);
		free(mlx);
		return (-1);
	}
	draw_fract(mlx);
	mlx_hook(mlx->win, 6, 0, hook_motn, (void *)mlx);
	mlx_key_hook(mlx->win, hook_keyb, (void *)mlx);
	mlx_mouse_hook(mlx->win, hook_mous, (void *)mlx);
	mlx_loop(mlx->mlx);
	free(mlx);
	return (0);
}
