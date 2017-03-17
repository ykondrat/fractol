/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_pixel_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:01:34 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/17 16:10:07 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_pixel_put(int x, int y, int color, t_wi *wi)
{
	int		*tmp;

	wi->data = mlx_get_data_addr(wi->img, &wi->bpp, &wi->size, &wi->endian);
	tmp = (int*)&wi->data[(x * (wi->bpp / 8)) + (y * wi->size)];
	*tmp = color;
}
