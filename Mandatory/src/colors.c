/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:12:33 by user              #+#    #+#             */
/*   Updated: 2024/07/22 01:15:58 by zvakil           ###   ########.fr       */
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
	return (t << 24 | r << 16 | g << 8 | b);
}

int	math_colors(int color1, int color2, int asmd)
{
	if (asmd == 0)
		return (create_trgb(((color1 >> 24) & 0xFF) + ((color2 >> 24) & 0xFF),
				((color1 >> 16) & 0xFF) + ((color2 >> 16) & 0xFF),
				((color1 >> 8) & 0xFF) + ((color2 >> 8) & 0xFF),
				(color1 & 0xFF) + (color2 & 0xFF)));
	else if (asmd == 1)
		return (create_trgb(((color1 >> 24) & 0xFF) - ((color2 >> 24) & 0xFF),
				((color1 >> 16) & 0xFF) - ((color2 >> 16) & 0xFF),
				((color1 >> 8) & 0xFF) - ((color2 >> 8) & 0xFF),
				(color1 & 0xFF) - (color2 & 0xFF)));
	else if (asmd == 2)
		return (create_trgb(((color1 >> 24) & 0xFF) - ((color2 >> 24) & 0xFF),
				((color1 >> 16) & 0xFF) - ((color2 >> 16) & 0xFF),
				((color1 >> 8) & 0xFF) - ((color2 >> 8) & 0xFF),
				(color1 & 0xFF) - (color2 & 0xFF)));
	return (1);
}

int	avg_color(int color1, int color2, int color3, int color4)
{
	return (create_trgb((((color1 >> 24) & 0xFF) + ((color2 >> 24) & 0xFF)
				+ ((color3 >> 24) & 0xFF) + ((color4 >> 24) & 0xFF)) / 4,
			(((color1 >> 16) & 0xFF) + ((color2 >> 16) & 0xFF)
				+ ((color3 >> 16) & 0xFF) + ((color4 >> 16) & 0xFF)) / 4,
			(((color1 >> 8) & 0xFF) + ((color2 >> 8) & 0xFF)
				+ ((color3 >> 8) & 0xFF) + ((color4 >> 8) & 0xFF)) / 4,
			((color1 & 0xFF) + (color2 & 0xFF)
				+ (color3 & 0xFF) + (color4 & 0xFF)) / 4));
}

int	avg_color_2(int color1, int color2)
{
	return (create_trgb((((color1 >> 24) & 0xFF) + ((color2 >> 24) & 0xFF)) / 2,
			(((color1 >> 16) & 0xFF) + ((color2 >> 16) & 0xFF)) / 2,
			(((color1 >> 8) & 0xFF) + ((color2 >> 8) & 0xFF)) / 2,
			((color1 & 0xFF) + (color2 & 0xFF) / 2)));
}