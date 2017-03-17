/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key_bs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:28:34 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/22 17:30:56 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_color_bs(int keycode, t_wi *wi)
{
	if (keycode == 0)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->color->a += 1;
		fractol_draw_bs(wi->fract, wi);
	}
	if (keycode == 15)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->color->r += 1;
		fractol_draw_bs(wi->fract, wi);
	}
	if (keycode == 5)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->color->g += 1;
		fractol_draw_bs(wi->fract, wi);
	}
	if (keycode == 11)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->color->b += 1;
		fractol_draw_bs(wi->fract, wi);
	}
}

static void	fractol_move_bs(int keycode, t_wi *wi)
{
	if (keycode == 123)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->fract->movex += 0.02;
		fractol_draw_bs(wi->fract, wi);
	}
	if (keycode == 124)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->fract->movex -= 0.02;
		fractol_draw_bs(wi->fract, wi);
	}
	if (keycode == 125)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->fract->movey -= 0.02;
		fractol_draw_bs(wi->fract, wi);
	}
	if (keycode == 126)
	{
		mlx_clear_window(wi->mlx, wi->win);
		wi->fract->movey += 0.02;
		fractol_draw_bs(wi->fract, wi);
	}
}

int			fractol_key_bs(int keycode, t_wi **wi)
{
	if (keycode == 53)
	{
		ft_putendl("\x1b[32;01m\tThanks for watching, enjoy graphics on C :)");
		exit(0);
	}
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		fractol_move_bs(keycode, *wi);
	if (keycode == 0 || keycode == 15 || keycode == 5 || keycode == 11)
		fractol_color_bs(keycode, *wi);
	return (0);
}
