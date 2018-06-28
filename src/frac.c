/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:11:50 by aherrera          #+#    #+#             */
/*   Updated: 2018/06/26 10:24:35 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftl.h"

int		julia(t_com z, t_com c, int it)
{
	int	i;

	i = 0;
	while (i < it)
	{
		if (z.r * z.r + z.i * z.i >= 4)
			return (i);
		z = com_sum(com_mul(z, z), c);
		i++;
	}
	return (-1);
}

int		mbrot(t_com z, t_com c, int it)
{
	int	i;

	i = 0;
	while (i < it)
	{
		if (z.r * z.r + z.i * z.i >= 4)
			return (i);
		z = com_sum(com_mul(z, z), c);
		i++;
	}
	return (-1);
}

int		bship(t_com z, t_com c, int it)
{
	int	i;

	i = 0;
	while (i < it)
	{
		if (z.r * z.r + z.i * z.i >= 4)
			return (i);
		z = com_new(z.r * z.r + z.i * z.i, 0);
		z = com_sum(z, c);
		i++;
	}
	return (-1);
}

int		cust1(t_com z, t_com c, int it)
{
	int i;

	i = 0;
	while (i < it)
	{
		if (z.r * z.r + z.i * z.i >= 4)
			return (i);
		z = com_sum(com_mul(com_mul(z, z), com_new(2, 2)),
		com_mul(c, com_new(2, 0)));
		i++;
	}
	return (-1);
}

int		cust2(t_com z, t_com c, int it)
{
	int i;

	i = 0;
	while (i < it)
	{
		if (z.r * z.r + z.i * z.i >= 4)
			return (i);
		z = com_sum(com_div(com_mul(z, z), com_new(2, 0)), com_mul(c, z));
		i++;
	}
	return (-1);
}
