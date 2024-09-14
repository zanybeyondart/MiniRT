/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_alias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:19:29 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/13 16:57:12 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	store_render(int update, int x, int y, int color)
{
	static int	image[WIDTH][HEIGHT];

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	if (update == 1)
	{
		image[x][y] = color;
		return (image[x][y]);
	}
	if (image[x][y])
		return (image[x][y]);
	return (0);
}

int	*set_pixel_box(int x, int y)
{
	int	*box;

	box = ft_smart_malloc(sizeof(int) * 17);
	box[0] = store_render(0, x, y, 0);
	box[1] = store_render(0, x - 1, y, 0);
	box[2] = store_render(0, x + 1, y, 0);
	box[3] = store_render(0, x, y - 1, 0);
	box[4] = store_render(0, x, y + 1, 0);
	box[5] = store_render(0, x - 1, y - 1, 0);
	box[6] = store_render(0, x + 1, y - 1, 0);
	box[7] = store_render(0, x - 1, y + 1, 0);
	box[8] = store_render(0, x + 1, y + 1, 0);
	box[9] = store_render(0, x - 2, y, 0);
	box[10] = store_render(0, x + 2, y, 0);
	box[11] = store_render(0, x, y - 2, 0);
	box[12] = store_render(0, x, y + 2, 0);
	box[13] = store_render(0, x - 2, y - 2, 0);
	box[14] = store_render(0, x + 2, y - 2, 0);
	box[15] = store_render(0, x - 2, y + 2, 0);
	box[16] = store_render(0, x + 2, y + 2, 0);
	return (box);
}

int	set_average(int *pixels)
{
	int	average[4];

	average[0] = avg_color(pixels[1], pixels[2], pixels[3], pixels[4]);
	average[1] = avg_color(pixels[5], pixels[6], pixels[7], pixels[8]);
	average[2] = avg_color(pixels[9], pixels[10], pixels[11], pixels[12]);
	average[3] = avg_color(pixels[13], pixels[14], pixels[15], pixels[16]);
	return (avg_color(average[0], average[1], average[2], average[3]));
}

void	modify_pixel(t_vars *vars, int x, int y)
{
	int	*pixels;
	int	average;
	int	delta;
	int	factor;
	int	color;

	pixels = set_pixel_box(x, y);
	average = set_average(pixels);
	delta = math_colors(pixels[0], average, 1);
	if (delta > THRESHOLD)
	{
		factor = min(1.0, delta / THRESHOLD);
		color = math_colors(create_trgb(((pixels[0] >> 24) & 0xFF),
					((pixels[0] >> 16) & 0xFF) * (1 - factor),
					((pixels[0] >> 8) & 0xFF) * (1 - factor),
					(pixels[0] & 0xFF) * (1 - factor)),
				create_trgb(((average >> 24) & 0xFF),
					((average >> 16) & 0xFF) * (factor),
					((average >> 8) & 0xFF) * (factor),
					(average & 0xFF) * (factor)), 0);
	}
	else
		color = pixels[0];
	mlx_pixel_put(vars->mlx, vars->win, x, y, color);
	free(pixels);
}

void	anti_alias(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(vars->mlx, vars->win);
	while (i < vars->size[0] && vars->update == 0)
	{
		j = 0;
		while (j < vars->size[1] && vars->update == 0)
		{
			modify_pixel(vars, i, j);
			j++;
		}
		i++;
	}
}
