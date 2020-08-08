/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:23:42 by ssoraka           #+#    #+#             */
/*   Updated: 2019/03/07 16:22:42 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fdf.h"

# define NEW 0
# define OLD 1
# define HEIGHT CONST_HEINTH
# define WIDTH CONST_WIDTH

void	ft_test(int id, int *data, t_param *param) {


	double	re[2];
	double	im[2];
	double	c_re;
	double	c_im;
	int     i;
	int     x;
	int     y;

	i = 0;
	x = id % WIDTH;
	y = id / HEIGHT;

	double m_x = param->center.x;
	double m_y = param->center.y;
	double zoom = param->len;
	double dx = 0.0;
	double dy = 0.0;
	int iter = param->iter;

	c_re = (x - m_x) / zoom + dx;
	c_im = (y - m_y) * CONST_HW / zoom + dy;
	re[NEW] = c_re;
	im[NEW] = c_im;
	while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
	{
		re[OLD] = re[NEW];
		im[OLD] = im[NEW];
		im[NEW] = 2 * im[OLD] * re[OLD] + c_im;
		re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + c_re;
	}

	if (i < iter)
		data[id] = 0xFFFFFF;
	else
		data[id] = 0;
}

void	ft_my_function(t_all *all)
{
	int id;

	id = 0;
	while (id < CONST_HEINTH * CONST_WIDTH)
	{
		ft_test(id, all->vis->pic.addr, &all->vis->param);
		id++;
	}
	mlx_put_image_to_window(all->vis->mlx, all->vis->win, all->vis->pic.img, 0, 0);
}













int		ft_init_all(t_all *all)
{
	ft_bzero((void *)all, sizeof(t_all));
	if (!(all->vis = ft_create_mlx(CONST_WIDTH, CONST_HEINTH, "fractol")))
		return (FAIL);
	return (SUCCESS);
}

void	ft_exit(t_all *all, char *error_message)
{
	if (all->vis)
		ft_destroy_mlx(&all->vis);
	if (error_message)
	{
		ft_putendl_fd(error_message, 2);
		exit(1);
	}
	exit(0);
}

int		ft_print_usage(void)
{
	ft_putendl("usage:");
	ft_putendl("./fractol");
	return (0);
}

int		main(int argc, char **argv)
{
	t_all	all;
	int		status;

	if (argc != 2)
		return (ft_print_usage());
	if (ft_init_all(&all) == FAIL)
		ft_exit(&all, MSG_ERROR1);
//	all.vis->param.centr = ft_arr_get(all.points, 0);
	ft_init_hooks(&all);
	mlx_loop(all.vis->mlx);
	ft_exit(&all, NULL);
	return (0);
}