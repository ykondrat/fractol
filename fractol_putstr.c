/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_putstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:17:42 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/06 15:44:58 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	farctol_put_on(t_wi *wi)
{
	mlx_string_put(wi->mlx, wi->win, wi->width - 199, 37, 0x00EE00,
			"Mouse to change");
	mlx_string_put(wi->mlx, wi->win, wi->width - 199, 54, 0x00EE00,
			"Scroll to zoom");
	mlx_string_put(wi->mlx, wi->win, wi->width - 199, 71, 0x00EE00,
			"Arrows to move");
	mlx_string_put(wi->mlx, wi->win, wi->width - 199, 88, 0x00EE00,
			"ARGB to color it");
}

void	fractol_sie_put(t_wi *wi)
{
	mlx_string_put(wi->mlx, wi->win, wi->width - 199, 37, 0x00EE00,
			"Num to change");
	mlx_string_put(wi->mlx, wi->win, wi->width - 199, 54, 0x00EE00,
			"No zoom ;(");
	mlx_string_put(wi->mlx, wi->win, wi->width - 199, 71, 0x00EE00,
			"Arrows to move");
	mlx_string_put(wi->mlx, wi->win, wi->width - 199, 88, 0x00EE00,
			"ARGB to color it");
}

void	fractol_pustr(t_wi *wi)
{
	int		x;
	int		y;
	void	*img;

	img = mlx_xpm_file_to_image(wi->mlx, "unit.xpm", &x, &y);
	mlx_put_image_to_window(wi->mlx, wi->win, img,
			wi->width - x, wi->height - y);
	mlx_destroy_image(wi->mlx, img);
	mlx_string_put(wi->mlx, wi->win, wi->width - 160, 3, 0xFFBE00,
			"UNIT Factory");
	mlx_string_put(wi->mlx, wi->win, wi->width - 199, 20, 0x00EE00,
			"Fract`ol");
	mlx_string_put(wi->mlx, wi->win, wi->width - 199, 105, 0xFF4200,
			"To exit press ESC!");
}
