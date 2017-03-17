/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key_sie.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:30:00 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/22 17:32:05 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_color_sie(int keycode, t_wi *wi)
{
	if (keycode == 0)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->fract->color -= 3000;
		fractol_draw_sierpinski(wi->fract, wi, 0, 0);
	}
	if (keycode == 15)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->fract->color -= 3000;
		fractol_draw_sierpinski(wi->fract, wi, 0, 0);
	}
	if (keycode == 5)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->fract->color += 3000;
		fractol_draw_sierpinski(wi->fract, wi, 0, 0);
	}
	if (keycode == 11)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->fract->color += 3000;
		fractol_draw_sierpinski(wi->fract, wi, 0, 0);
	}
}

static void	fractol_move_sie(int keycode, t_wi *wi)
{
	if (keycode == 123)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->fract->movex -= 2;
		fractol_draw_sierpinski(wi->fract, wi, 0, 0);
	}
	if (keycode == 124)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->fract->movex += 2;
		fractol_draw_sierpinski(wi->fract, wi, 0, 0);
	}
}

static void	fractol_change(int keycode, t_wi *wi)
{
	if (keycode == 19)
		wi->fract->cre = 2;
	if (keycode == 20)
		wi->fract->cre = 3;
	if (keycode == 21)
		wi->fract->cre = 4;
	if (keycode == 23)
		wi->fract->cre = 5;
	mlx_clear_window(wi->mlx, wi->win);
	fractol_draw_sierpinski(wi->fract, wi, 0, 0);
}

int			fractol_key_sie(int keycode, t_wi **wi)
{
	if (keycode == 53)
	{
		ft_putendl("\x1b[32;01m\tThanks for watching, enjoy graphics on C :)");
		exit(0);
	}
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		fractol_move_sie(keycode, *wi);
	if (keycode == 0 || keycode == 15 || keycode == 5 || keycode == 11)
		fractol_color_sie(keycode, *wi);
	if (keycode == 19 || keycode == 20 || keycode == 21 || keycode == 23)
		fractol_change(keycode, *wi);
	return (0);
}
