/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 14:49:42 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/06 14:15:28 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_man_default(t_fract **man, t_wi *wi)
{
	(*man)->zoom = 1;
	(*man)->movex = -0.5;
	(*man)->movey = 0;
	(*man)->mz = 0.0025;
	(*man)->maxiter = (wi->width - 200) / 2;
}

static int	fractol_color_man(t_fract **man, t_wi *wi)
{
	int		i;

	i = 0;
	while (i < (*man)->maxiter)
	{
		(*man)->oldre = (*man)->newre;
		(*man)->oldim = (*man)->newim;
		(*man)->newre = (*man)->oldre * (*man)->oldre -
			(*man)->oldim * (*man)->oldim + (*man)->cre;
		(*man)->newim = 2 * (*man)->oldre * (*man)->oldim + (*man)->cim;
		if (((*man)->newre * (*man)->newre + (*man)->newim * (*man)->newim) > 4)
			break ;
		i++;
	}
	i = fractol_get_color(i, wi);
	return (i);
}

static void	fractol_set_mandelbrot(t_wi *wi)
{
	mlx_put_image_to_window(wi->mlx, wi->win, wi->img, 0, 0);
	mlx_destroy_image(wi->mlx, wi->img);
	fractol_pustr(wi);
	farctol_put_on(wi);
	mlx_mouse_hook(wi->win, fractol_zoom_man, wi);
	mlx_hook(wi->win, 2, 3, &fractol_key_man, &wi);
	mlx_loop(wi->mlx);
}

void		fractol_draw_mandelbrot(t_fract *man, t_wi *wi)
{
	int		x;
	int		y;

	y = 0;
	wi->img = mlx_new_image(wi->mlx, wi->width - 200, wi->height);
	while (y < wi->height)
	{
		x = 0;
		while (x < wi->width - 200)
		{
			man->cre = 1.5 * (x - (wi->width - 200) / 2) /
				(0.5 * man->zoom * (wi->width - 200)) + man->movex;
			man->cim = (y - wi->height / 2) /
				(0.5 * man->zoom * wi->height) + man->movey;
			fractol_zero_old_new(&man);
			fractol_pixel_put(x, y, fractol_color_man(&man, wi), wi);
			x++;
		}
		y++;
	}
	fractol_set_mandelbrot(wi);
}

void		fractol_mandelbrot(char *fract_name)
{
	t_wi	*wi;
	t_fract	*man;

	if (!(man = (t_fract*)malloc(sizeof(t_fract))))
		fractol_memmory_error();
	wi = fractol_create_wi(fract_name);
	fractol_man_default(&man, wi);
	wi->fract = man;
	fractol_set_color(wi);
	fractol_draw_mandelbrot(man, wi);
}
