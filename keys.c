/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:12:08 by ssoraka           #+#    #+#             */
/*   Updated: 2019/10/27 18:12:08 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

#define CAM_SHIFT 20
#define CAM_SCALE 1.2
#define CAM_ROTATE 90
#define PERSP_SPEED 4
#define MIN_RADIUS 500
#define MAX_RADIUS 20000
#define MIN_SCALE 0.01
#define MAX_SCALE 1000.0

int		ft_csale_picture(t_param *param, int button)
{
	double coeff;
	t_dpoint new_mouse;

	if (button == MIDDLE_FORW_BUTTON)
		coeff = CAM_SCALE;
	else if (button == MIDDLE_BACK_BUTTON && param->len > MIN_SCALE)
		coeff = 1.0 / CAM_SCALE;
	else
		return (FALSE);
	new_mouse.x = (param->mouse.x - param->center.x);
	new_mouse.y = (param->mouse.y - param->center.y);

	param->center.x += (new_mouse.x - new_mouse.x * coeff);
	param->center.y += (new_mouse.y - new_mouse.y * coeff);
	param->len *= coeff;
	return (TRUE);
}

int		ft_press_key(int key, t_param *param)
{
	printf("key %d\n", key);
	if (key == KEY_ESC)
		param->exit = TRUE;
	else if (key == KEY_DOWN)
		param->style++;
	else if (key == KEY_UP)
		param->style--;
	else if (key == KEY_LEFT)
		param->fract++;
	else if (key == KEY_RIGHT)
		param->fract--;
	else if (key == KEY_PLUS)
		param->iter += 4;
	else if (key == KEY_MINUS && param->iter > 4)
		param->iter -= 4;
	else
		return (FAIL);
	if (param->style >= STYLE_COUNT)
		param->style = STYLE_ONE;
	if (param->style < STYLE_ONE)
		param->style = STYLE_COUNT - 1;
	if (param->fract >= FRACT_COUNT)
		param->fract = MAND;
	if (param->fract < MAND)
		param->fract = FRACT_COUNT - 1;
	return (SUCCESS);
}

int		ft_deal_key(int key, void *parametrs)
{
	t_param *param;
	t_all *all;

	all = (t_all *)parametrs;
	param = &all->vis->param;
	if (param->exit)
		return (SUCCESS);
	if (ft_press_key(key, param) == SUCCESS)
		ft_my_function(all);
	return (SUCCESS);
}
