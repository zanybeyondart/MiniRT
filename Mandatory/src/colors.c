/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:12:33 by user              #+#    #+#             */
/*   Updated: 2024/07/17 16:43:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	create_trgb(int t, int r, int g, int b)
{
	if (t < 0)
		t = 0;
	else if (t > 255)
		t = 255;
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return	(t << 24 | r << 16 | g << 8 | b);
}

int add_colors(int color1, int color2, int addsub)
{
	if (addsub == 0)
		return create_trgb(((color1 >> 24) & 0xFF) + ((color2 >> 24) & 0xFF),
		((color1 >> 16) & 0xFF) + ((color2 >> 16) & 0xFF),
		((color1 >> 8) & 0xFF) + ((color2 >> 8) & 0xFF),
		(color1 & 0xFF) + (color2 & 0xFF));
	else
		return create_trgb(((color1 >> 24) & 0xFF) - ((color2 >> 24) & 0xFF),
		((color1 >> 16) & 0xFF) - ((color2 >> 16) & 0xFF),
		((color1 >> 8) & 0xFF) - ((color2 >> 8) & 0xFF),
		(color1 & 0xFF) - (color2 & 0xFF));
}
