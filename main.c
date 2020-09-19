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

#include "./includes/ft_fractol.h"

t_prog	g_compile[PROGRAMS_COUNT + 1] =
{
	{"kernel.cl", "draw", 2, {IMAGE, PARAM}},
	{"", "", 0, {0, 0}}
};

/*
** возможно, это нужно тут
** mlx_do_sync(all->vis->mlx);
*/

void	ft_my_function(t_all *all)
{
	ft_write_buffers(all->cl, PARAM, TRUE);
	ft_run_kernels(all->cl);
	ft_read_buffers(all->cl, IMAGE, TRUE);
	mlx_put_image_to_window(
			all->vis->mlx, all->vis->win, all->vis->pic.img, 0, 0);
}

void	ft_init_buffers(t_buff *buff, void *image, int count, int size)
{
	buff->arr = image;
	buff->count = count;
	buff->g_work_size = &buff->count;
	buff->buff_used = count * size;
}

int		ft_init_all(t_all *all)
{
	ft_bzero((void *)all, sizeof(t_all));
	if (!(all->vis = ft_create_mlx(CONST_WIDTH, CONST_HEINTH, "fractol")))
		return (FAIL);
	if (!(all->cl = ft_init_open_cl(CL_DEVICE_TYPE_GPU)))
		return (FAIL);
	ft_init_buffers(&(all->cl->buff[IMAGE]), all->vis->pic.addr,
				all->vis->pic.count_byte / sizeof(int), sizeof(int));
	ft_init_buffers(&(all->cl->buff[PARAM]), &all->vis->param,
				1, sizeof(t_param));
	if (!ft_create_all_buffers(all->cl))
		return (FAIL);
	if (!ft_read_and_build_programs(all->cl, g_compile))
		return (FAIL);
	if (!ft_set_kernel_arg(all->cl, g_compile))
		return (FAIL);
	return (SUCCESS);
}

void	ft_exit(t_all *all, char *error_message)
{
	if (all->vis)
		ft_destroy_mlx(&all->vis);
	if (all->cl)
		ft_free_open_cl(&all->cl);
	if (error_message)
	{
		ft_putendl_fd(error_message, 2);
		exit(1);
	}
	exit(0);
}

int		main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2 || ft_atoi(argv[1]) >= FRACT_COUNT
	|| ft_atoi(argv[1]) < MAND || ft_strlen(argv[1]) > 2)
		return (ft_print_usage());
	if (ft_init_all(&all) == FAIL)
		ft_exit(&all, MSG_ERROR1);
	all.vis->param.fract = ft_atoi(argv[1]);
	ft_my_function(&all);
	ft_init_hooks(&all);
	mlx_loop(all.vis->mlx);
	ft_exit(&all, NULL);
	return (0);
}
