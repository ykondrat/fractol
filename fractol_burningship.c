/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_burningship.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:00:30 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/22 17:28:26 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_bs_default(t_fract **bs, t_wi *wi)
{
	(*bs)->zoom = 1;
	(*bs)->movex = -0.5;
	(*bs)->movey = -0.3;
	(*bs)->mz = 0.0025;
	(*bs)->maxiter = (wi->width - 200) / 2;
}

static int	fractol_color_bs(t_fract **bs, t_wi *wi)
{
	int		i;

	i = 0;
	while (i < (*bs)->maxiter)
	{
		(*bs)->oldre = (*bs)->newre;
		(*bs)->oldim = (*bs)->newim;
		(*bs)->newre = (*bs)->oldre * (*bs)->oldre -
			(*bs)->oldim * (*bs)->oldim + (*bs)->cre;
		(*bs)->newim = 2 * fabs((*bs)->oldre * (*bs)->oldim) + (*bs)->cim;
		if (((*bs)->newre * (*bs)->newre + (*bs)->newim * (*bs)->newim) > 4)
			break ;
		i++;
	}
	i = fractol_get_color(i, wi);
	return (i);
}

static void	fractol_set_burningship(t_wi *wi)
{
	mlx_put_image_to_window(wi->mlx, wi->win, wi->img, 0, 0);
	mlx_destroy_image(wi->mlx, wi->img);
	fractol_pustr(wi);
	farctol_put_on(wi);
	mlx_mouse_hook(wi->win, fractol_zoom_bs, wi);
	mlx_hook(wi->win, 2, 3, &fractol_key_bs, &wi);
	mlx_loop(wi->mlx);
}

void		fractol_draw_bs(t_fract *bs, t_wi *wi)
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
			bs->cre = 1.5 * (x - (wi->width - 200) / 2) /
				(0.5 * bs->zoom * (wi->width - 200)) + bs->movex;
			bs->cim = (y - wi->height / 2) /
				(0.5 * bs->zoom * wi->height) + bs->movey;
			fractol_zero_old_new(&bs);
			fractol_pixel_put(x, y, fractol_color_bs(&bs, wi), wi);
			x++;
		}
		y++;
	}
	fractol_set_burningship(wi);
}

void		fractol_burningship(char *fract_name)
{
	t_wi	*wi;
	t_fract	*bs;

	if (!(bs = (t_fract*)malloc(sizeof(t_fract))))
		fractol_memmory_error();
	wi = fractol_create_wi(fract_name);
	fractol_bs_default(&bs, wi);
	wi->fract = bs;
	fractol_set_color(wi);
	fractol_draw_bs(bs, wi);
}
