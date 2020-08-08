/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:28:19 by ssoraka           #+#    #+#             */
/*   Updated: 2019/10/27 18:28:20 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fdf.h"

void	ft_clear_image(t_pict *pic)
{
	ft_memset8((void *)pic->index, DEFAULT_INDEX, pic->count_byte);
	ft_memset8((void *)pic->addr, BACKGROUND_COLOR, pic->count_byte);
	ft_memset8((void *)pic->z_buffer, MIN_INTEGER, pic->count_byte);
}