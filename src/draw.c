/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:11:22 by aherrera          #+#    #+#             */
/*   Updated: 2018/06/26 10:26:52 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftl.h"
#include "colors.h"

static int		get_c(int x, int y, t_mlx *mlx)
{
	int		color;
	float	n_x;
	float	n_y;
	t_com	c;
	t_com	z;

	n_x = ((double)x / mlx->scale);
	n_y = ((double)y / mlx->scale);
	z.r = n_x * EP - 2 + mlx->off_x;
	z.i = n_y * EP - 2 + mlx->off_y;
	if (mlx->fract == julia)
		c = com_new(mlx->mou_x * EP - 2, mlx->mou_y * EP - 2);
	else
		c = z;
	color = mlx->fract(z, c, mlx->i);
	if (color == -1)
		return (0);
	color++;
	color = color * g_colors[mlx->mode_c][0] +
	color * g_colors[mlx->mode_c][1] * 256 +
	color * g_colors[mlx->mode_c][2] * 256 * 256;
	return (color);
}

static void		draw_inst(t_mlx *mlx)
{
	int		i;
	char	*word;

	i = 0;
	while (i < 190)
	{
		if (i < 145)
			mlx_pixel_put(mlx->mlx, mlx->win, 25, 25 + i, 0x666633);
		mlx_pixel_put(mlx->mlx, mlx->win, 25 + i, 25, 0x666633);
		if (i < 145)
			mlx_pixel_put(mlx->mlx, mlx->win, 215, 25 + i, 0x666633);
		mlx_pixel_put(mlx->mlx, mlx->win, 25 + i, 170, 0x666633);
		i++;
	}
	word = ft_itoa(mlx->i);
	mlx_string_put(mlx->mlx, mlx->win, 32, 25, 0x215277, "Arrows: move");
	mlx_string_put(mlx->mlx, mlx->win, 32, 55, 0x215277, word);
	mlx_string_put(mlx->mlx, mlx->win, 32, 70, 0x215277, "");
	mlx_string_put(mlx->mlx, mlx->win, 32, 85, 0x215277, "-,+ to zoom");
	mlx_string_put(mlx->mlx, mlx->win, 32, 100, 0x215277, "Space: toggle move");
	mlx_string_put(mlx->mlx, mlx->win, 32, 115, 0x215277, "Q, E: toggle color");
	mlx_string_put(mlx->mlx, mlx->win, 32, 130, 0x215277, "C, V: iterations");
	ft_strdel(&word);
}

void			*draw_thread(void *arg)
{
	int		x;
	int		y;
	t_img	*f;
	t_mlx	*mlx;
	int		id;

	mlx = (t_mlx *)((t_th *)arg)->mlx;
	f = mlx->f;
	y = 0;
	id = ((t_th *)arg)->t_id;
	while (y < WIN_H)
	{
		x = id;
		while (x < WIN_W)
		{
			*(int *)&f->add[(x * f->bpp / 8) + (y * f->line_size)] =
			get_c(x, y, mlx);
			x += THREADS;
		}
		y++;
	}
	return (NULL);
}

void			draw_fract(t_mlx *mlx)
{
	int			i;
	pthread_t	t[THREADS];
	t_th		thread[THREADS];

	i = 0;
	while (i < THREADS)
	{
		thread[i].mlx = mlx;
		thread[i].t_id = i;
		pthread_create(&t[i], NULL, draw_thread, &thread[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(t[i], NULL);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->f->img, 0, 0);
	draw_inst(mlx);
}
