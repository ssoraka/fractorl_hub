/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:28:19 by ssoraka           #+#    #+#             */
/*   Updated: 2019/10/27 18:28:20 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

int		ft_mouse_press(int button, int x, int y, void *parameters)
{
	t_all	*all;
	t_param	*param;

	all = (t_all *)parameters;
	param = &all->vis->param;
	if (param->exit || !ft_mouse_on_window(x, y))
		return (0);
	if (button == LEFT_BUTTON && param->fract == JUL)
		param->is_const_change = !param->is_const_change;
	if (ft_csale_picture(param, button))
		ft_my_function(all);
	return (0);
}

int		ft_mouse_move(int x, int y, void *parameters)
{
	t_all	*all;
	t_param	*param;

	all = (t_all *)parameters;
	param = &all->vis->param;
	if (param->exit)
		ft_exit(all, NULL);
	if (!ft_mouse_get_new_pos(x, y, param))
		return (0);
	if (param->is_const_change)
		ft_my_function(all);
	return (0);
}

void	ft_init_hooks(t_all *all)
{
	void *win;

	win = all->vis->win;
	mlx_hook(win, KEY_PRESS, KEY_PRESS_MASK, ft_deal_key, (void *)all);
	mlx_hook(win, MOTION_NOTIFY, POINTER_MOTION_MASK, ft_mouse_move,
			(void *)all);
	mlx_hook(win, BUTTON_PRESS, BUTTON_PRESS_MASK, ft_mouse_press,
			(void *)all);
}
