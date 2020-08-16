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
	t_vektr	*active;

	all = (t_all *)parameters;
	param = &all->vis->param;
	if (param->exit || !ft_mouse_on_window(x, y))
		return (0);
	if (ft_csale_picture(param, button))
		ft_my_function(all);
	//тут надо бы вставить вызов кернела

	return (0);
}

int		ft_mouse_release(int button, int x, int y, void *parameters)
{
	t_all	*all;
	t_param	*param;

	all = (t_all *)parameters;
	param = &all->vis->param;
	if (param->exit || !ft_mouse_on_window(x, y))
		return (0);
//	if (button == MIDDLE_BUTTON)
//		param->right_button_press = FALSE;
//	else if (button == LEFT_BUTTON)
//		param->left_button_press = FALSE;
	return (0);
}

int		ft_mouse_move(int x, int y, void *parameters)
{
	t_all	*all;
	t_param	*param;
	t_vis *vis;

	all = (t_all *)parameters;
	vis = all->vis;
	param = &all->vis->param;
	if (param->exit)
		ft_exit(all, NULL);
	if (!ft_mouse_get_new_pos(x, y, param))
		return (0);
//	if (ft_is_cam_moved(param))
//		param->is_points_change = TRUE;
//	mlx_do_sync(all->vis->mlx);
	return (0);
}



void	ft_init_hooks(t_all *all)
{
	void *param;
	void *win;

	param = (void *)&all->vis->param;
	win = all->vis->win;
	mlx_hook(win, KEY_PRESS, KEY_PRESS_MASK, ft_deal_key, param);
	mlx_hook(win, MOTION_NOTIFY, POINTER_MOTION_MASK, ft_mouse_move,
			(void *)all);
	mlx_hook(win, BUTTON_PRESS, BUTTON_PRESS_MASK, ft_mouse_press,
			(void *)all);
	mlx_hook(win, BUTTON_RELEASE, BUTTON_RELEASE_MASK, ft_mouse_release,
			(void *)all);
}
