/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:51:06 by ssoraka           #+#    #+#             */
/*   Updated: 2019/10/27 17:51:07 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

void		ft_normilize_vektor(t_dpoint *vek)
{
	double summ;

	summ = ft_vektr_len(vek);
	vek->x = vek->x / summ;
	vek->y = vek->y / summ;
	vek->z = vek->z / summ;
}

void		ft_create_xyz(t_oxyz *oxyz)
{
	ft_fill_dpoint(&(oxyz->ox), 0.0, 1.0, 0.0);
	ft_fill_dpoint(&(oxyz->oy), 1.0, 0.0, 0.0);
	ft_fill_dpoint(&(oxyz->oz), 0.0, 0.0, 1.0);
}

void		ft_get_perp_vekt_from_two(t_dpoint *answ, t_dpoint *a, t_dpoint *b)
{
	ft_fill_dpoint(answ,
					a->z * b->x - a->x * b->z,
					a->y * b->z - a->z * b->y,
					a->x * b->y - a->y * b->x);
	ft_normilize_vektor(answ);
}

t_dpoint	ft_ret_norm(t_dpoint *a, t_dpoint *b, t_dpoint *c)
{
	t_dpoint n;
	t_dpoint ba;
	t_dpoint bc;

	ft_fill_dpoint(&ba, a->y - b->y, a->x - b->x, a->z - b->z);
	ft_fill_dpoint(&bc, c->y - b->y, c->x - b->x, c->z - b->z);
	ft_fill_dpoint(&n,
					ba.z * bc.x - ba.x * bc.z,
					ba.y * bc.z - ba.z * bc.y,
					ba.x * bc.y - ba.y * bc.x);
	return (n);
}
