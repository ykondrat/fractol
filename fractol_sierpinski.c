/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sierpinski.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:26:31 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/23 15:19:48 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_sie_default(t_fract **sie, t_wi *wi)
{
	(*sie)->cre = 4;
	(*sie)->cim = 0;
	(*sie)->newre = 0;
	(*sie)->newim = 0;
	(*sie)->oldre = 0;
	(*sie)->oldim = 0;
	(*sie)->zoom = 1;
	(*sie)->movex = 0;
	(*sie)->movey = 0;
	(*sie)->color = ft_atoi_base("00EE00", 16);
	(*sie)->maxiter = wi->width * wi->height;
}

static void	fractol_set_sierpinski(t_wi *wi)
{
	mlx_put_image_to_window(wi->mlx, wi->win, wi->img, 0, 0);
	fractol_pustr(wi);
	fractol_sie_put(wi);
	mlx_destroy_image(wi->mlx, wi->img);
	mlx_hook(wi->win, 2, 3, &fractol_key_sie, &wi);
	mlx_loop(wi->mlx);
}

void		fractol_draw_sierpinski(t_fract *sie, t_wi *wi, int x, int y)
{
	wi->img = mlx_new_image(wi->mlx, wi->width - 200, wi->height);
	while (y < wi->height)
	{
		x = 0;
		while (x < wi->width - 200)
		{
			if (!((x / (int)pow(sie->cre, 0)) % (int)sie->cre == 1 &&
						(y / (int)pow(sie->cre, 0)) % (int)sie->cre == 1) &&
					!((x / (int)pow(sie->cre, 1)) % (int)sie->cre == 1 &&
						(y / (int)pow(sie->cre, 1)) % (int)sie->cre == 1) &&
					!((x / (int)pow(sie->cre, 2)) % (int)sie->cre == 1 &&
						(y / (int)pow(sie->cre, 2)) % (int)sie->cre == 1) &&
					!((x / (int)pow(sie->cre, 3)) % (int)sie->cre == 1 &&
						(y / (int)pow(sie->cre, 3)) % (int)sie->cre == 1) &&
					!((x / (int)pow(sie->cre, 4)) % (int)sie->cre == 1 &&
						(y / (int)pow(sie->cre, 4)) % (int)sie->cre == 1))
				fractol_pixel_put(x + sie->movex, y + sie->movey,
						sie->color, wi);
			x++;
		}
		y++;
	}
	fractol_set_sierpinski(wi);
}

void		fractol_sierpinski(char *fract_name)
{
	t_wi	*wi;
	t_fract	*sie;

	if (!(sie = (t_fract*)malloc(sizeof(t_fract))))
		fractol_memmory_error();
	wi = fractol_create_wi(fract_name);
	fractol_sie_default(&sie, wi);
	wi->fract = sie;
	fractol_draw_sierpinski(sie, wi, 0, 0);
}
