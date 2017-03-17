/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_get_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:22:06 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/09 17:02:11 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_set_color(t_wi *wi)
{
	t_clr	*color;

	if (!(color = (t_clr*)malloc(sizeof(t_clr))))
		fractol_memmory_error();
	color->a = 0;
	color->r = 2;
	color->g = 4;
	color->b = 0;
	wi->color = color;
}

int		fractol_get_color(int i, t_wi *wi)
{
	int		color;

	color = wi->color->a << 24 | wi->color->r << 16 |
		wi->color->g << 8 | wi->color->b << 0;
	i = i * color;
	return (i);
}
