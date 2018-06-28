/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:11:26 by aherrera          #+#    #+#             */
/*   Updated: 2018/06/26 10:36:42 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftl.h"

t_com	com_new(float r, float i)
{
	t_com	t_n;

	t_n.r = r;
	t_n.i = i;
	return (t_n);
}

t_com	com_sum(t_com a, t_com b)
{
	t_com	c;

	c.r = a.r + b.r;
	c.i = a.i + b.i;
	return (c);
}

t_com	com_mul(t_com a, t_com b)
{
	t_com	c;

	c.r = a.r * b.r - (a.i * b.i);
	c.i = a.i * b.r + a.r * b.i;
	return (c);
}

t_com	com_div(t_com a, t_com b)
{
	t_com	c;

	c.r = b.r;
	c.i = -b.i;
	a = com_mul(a, c);
	b = com_mul(b, c);
	a.r = a.r / b.r;
	a.i = a.i / b.r;
	return (a);
}

float	com_dis(t_com a)
{
	return (sqrtf(a.r * a.r + a.i * a.i));
}
