/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_jul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:41:32 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/22 17:44:23 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_plus_jul(double x0, double y0, t_wi *wi)
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

static void	fractol_minus_jul(double x0, double y0, t_wi *wi)
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

int			fractol_zoom_jul(int but, int x, int y, t_wi *wi)
{
	double		x0;
	double		y0;

	if (x >= wi->width || y >= wi->height || x <= 0 || y <= 0)
		return (1);
	x0 = (x - 500) * wi->fract->mz;
	y0 = (y - 300) * wi->fract->mz;
	if (but == 5)
		fractol_plus_jul(x0, y0, wi);
	if (but == 4)
		fractol_minus_jul(x0, y0, wi);
	mlx_clear_window(wi->mlx, wi->win);
	fractol_draw_julia(wi->fract, wi);
	return (0);
}

int			fractol_mouse_jul(int x, int y, t_wi *wi)
{
	if (x >= wi->width || y >= wi->height || x <= 0 || y <= 0)
		return (1);
	if ((x >= wi->width / 2 && y <= wi->height / 2) ||
			(x <= wi->width / 2 && y >= wi->height / 2))
	{
		wi->fract->cre -= 0.01;
		wi->fract->cim -= 0.00010;
	}
	else
	{
		wi->fract->cre += 0.01;
		wi->fract->cim += 0.00010;
	}
	mlx_clear_window(wi->mlx, wi->win);
	fractol_draw_julia(wi->fract, wi);
	return (0);
}
