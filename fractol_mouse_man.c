/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_man.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:50:38 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/22 17:35:39 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_plus_man(double x0, double y0, t_wi *wi)
{
	wi->fract->zoom += 1;
	wi->fract->movex += x0;
	wi->fract->movey += y0;
	wi->fract->mz /= 2;
	if (wi->fract->mz < 0.0001)
		wi->fract->mz = 0.0001;
	if (wi->fract->zoom <= 0)
	{
		wi->fract->zoom = 1;
		wi->fract->movex = 0;
		wi->fract->movey = 0;
	}
}

static void	fractol_minus_man(double x0, double y0, t_wi *wi)
{
	wi->fract->zoom -= 1;
	wi->fract->movex += x0;
	wi->fract->movey += y0;
	wi->fract->mz /= 2;
	if (wi->fract->mz < 0.0001)
		wi->fract->mz = 0.0001;
	if (wi->fract->zoom <= 0)
	{
		wi->fract->zoom = 1;
		wi->fract->movex = 0;
		wi->fract->movey = 0;
	}
}

int			fractol_zoom_man(int but, int x, int y, t_wi *wi)
{
	double		x0;
	double		y0;

	if (x >= wi->width || y >= wi->height || x <= 0 || y <= 0)
		return (1);
	x0 = (x - 500) * wi->fract->mz;
	y0 = (y - 300) * wi->fract->mz;
	if (but == 5)
		fractol_plus_man(x0, y0, wi);
	if (but == 4)
		fractol_minus_man(x0, y0, wi);
	mlx_clear_window(wi->mlx, wi->win);
	fractol_draw_mandelbrot(wi->fract, wi);
	return (0);
}
