/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:01:54 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/11 15:23:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_ui(t_active_layers *menu)
{

}

t_ui	*load_ui(t_vars *vars)
{
	t_ui	*ui;

	ui = ft_smart_malloc(sizeof(t_ui));
	ui->overlay.img = mlx_xpm_file_to_image(vars->mlx,
			"./Mandatory/src/ui/images/overlay.xpm",
			&ui->overlay.w, &ui->overlay.h);
	ui->active = 1;
	return (ui);
}
