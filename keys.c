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

#include "./includes/ft_fdf.h"

#define CAM_SHIFT 20
#define CAM_SCALE 1.1
#define CAM_ROTATE 90
#define PERSP_SPEED 4
#define MIN_RADIUS 500
#define MAX_RADIUS 20000
#define MIN_SCALE 0.01
#define MAX_SCALE 1000.0

int		ft_persp_and_csale(t_param *param, int key)
{
	if (key == KEY_PLUS)
		param->len *= CAM_SCALE;
	else if (key == KEY_MINUS && param->len > MIN_SCALE)
		param->len /= CAM_SCALE;
	else
		return (FALSE);
	return (TRUE);
}

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
	new_mouse.x = (param->mouse.x - CONST_WIDTH / 2) * coeff + CONST_WIDTH / 2;
	new_mouse.y = (param->mouse.y - CONST_HEINTH / 2) * coeff + CONST_HEINTH / 2;
	param->center.x += param->mouse.x - new_mouse.x;
	param->center.y += param->mouse.y - new_mouse.y;
	param->len *= coeff;
	return (TRUE);
}

int		ft_deal_key(int key, void *parametrs)
{
	t_param *param;

	param = (t_param *)parametrs;
	if (key == KEY_ESC)
		param->exit = TRUE;
	else
		return (FAIL);
	param->is_points_change = TRUE;
	return (SUCCESS);
}
