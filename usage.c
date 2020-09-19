/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:49:41 by ssoraka           #+#    #+#             */
/*   Updated: 2020/02/16 15:49:42 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

int		ft_print_usage(void)
{
	ft_putendl("usage:");
	ft_putendl("./fractol [fractal num]");
	ft_putendl("\tMandelbrot set:\t\t0");
	ft_putendl("\tJulia:\t\t\t1");
	ft_putendl("\tMy_1:\t\t\t2");
	ft_putendl("\tMy_2:\t\t\t3");
	ft_putendl("\tBurning ship:\t\t4");
	ft_putendl("\tCeltic Mandelbrot:\t5");
	ft_putendl("\tCeltic Mandelbar:\t6");
	ft_putendl("\tCeltic Perpendicular:\t7");
	ft_putendl("\tSpider:\t\t\t8");
	ft_putendl("=================================");
	ft_putendl("\"+\"/\"-\" - increase/decrease depth");
	ft_putendl("LEFT MOUSE - change constant for Julia");
	ft_putendl("UP,DOWN - change colors");
	ft_putendl("LEFT,RIGHT - change fractal");
	return (0);
}
