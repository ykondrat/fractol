/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:30:29 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/17 17:40:41 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_jul_default(t_fract **jul, t_wi *wi)
{
	(*jul)->cre = -0.7;
	(*jul)->cim = 0.27015;
	(*jul)->maxiter = wi->width / 2 - 100;
	(*jul)->zoom = 1;
	(*jul)->mz = 0.0025;
	(*jul)->movex = 0;
	(*jul)->movey = 0;
}

static int	fractol_color_jul(t_fract **jul, t_wi *wi)
{
	int		i;

	i = 0;
	while (i < (*jul)->maxiter)
	{
		(*jul)->oldre = (*jul)->newre;
		(*jul)->oldim = (*jul)->newim;
		(*jul)->newre = (*jul)->oldre * (*jul)->oldre -
			(*jul)->oldim * (*jul)->oldim + (*jul)->cre;
		(*jul)->newim = 2 * (*jul)->oldre * (*jul)->oldim + (*jul)->cim;
		if (((*jul)->newre * (*jul)->newre + (*jul)->newim * (*jul)->newim) > 4)
			break ;
		i++;
	}
	i = fractol_get_color(i, wi);
	return (i);
}

static void	fractol_set_jul(t_wi *wi)
{
	mlx_put_image_to_window(wi->mlx, wi->win, wi->img, 0, 0);
	mlx_destroy_image(wi->mlx, wi->img);
	fractol_pustr(wi);
	farctol_put_on(wi);
	mlx_hook(wi->win, 6, 0, fractol_mouse_jul, wi);
	mlx_mouse_hook(wi->win, fractol_zoom_jul, wi);
	mlx_hook(wi->win, 2, 3, &fractol_key_jul, &wi);
	mlx_loop(wi->mlx);
}

void		fractol_draw_julia(t_fract *jul, t_wi *wi)
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
			jul->newre = 1.5 * (x - (wi->width - 200) / 2) /
				(0.5 * jul->zoom * (wi->width - 200)) + jul->movex;
			jul->newim = (y - wi->height / 2) /
				(0.5 * jul->zoom * wi->height) + jul->movey;
			fractol_pixel_put(x, y, fractol_color_jul(&jul, wi), wi);
			x++;
		}
		y++;
	}
	fractol_set_jul(wi);
}

void		fractol_julia(char *fract_name)
{
	t_wi	*wi;
	t_fract	*jul;

	if (!(jul = (t_fract*)malloc(sizeof(t_fract))))
		fractol_memmory_error();
	wi = fractol_create_wi(fract_name);
	fractol_jul_default(&jul, wi);
	wi->fract = jul;
	fractol_set_color(wi);
	fractol_draw_julia(jul, wi);
}
