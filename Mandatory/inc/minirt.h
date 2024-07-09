/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:03:29 by user              #+#    #+#             */
/*   Updated: 2024/07/09 12:14:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# ifdef __linux__
    # include "../../MLX/minilibx_linux/mlx.h"
# else
    # include "../../MLX/minilibx_ogl/mlx.h"
# endif

