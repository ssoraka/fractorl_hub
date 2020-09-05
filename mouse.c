/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:28:19 by ssoraka           #+#    #+#             */
/*   Updated: 2019/10/27 18:28:20 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

int		ft_mouse_on_window(int x, int y)
{
	if (x < 0 || y < 0 || x >= CONST_WIDTH || y >= CONST_HEINTH)
		return (FALSE);
	return (TRUE);
}

int		ft_mouse_get_new_pos(int x, int y, t_param *param)
{
	if (!ft_mouse_on_window(x, y))
		return (FALSE);
	param->mouse.x = x;
	param->mouse.y = y;
	if (param->is_const_change)
	{
		param->jul.x = ((double)x - (double)CONST_WIDTH / 2) * 0.002;
		param->jul.y = ((double)y - (double)CONST_WIDTH / 2) * 0.002;
	}
	if (param->fract != JUL)
	{
		param->jul.x = 0;
		param->jul.y = 0;
	}
	return (TRUE);
}
