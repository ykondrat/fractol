/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_create_wi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:31:00 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/22 17:28:33 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_wi	*fractol_create_wi(char *title)
{
	t_wi	*wi;

	if (!(wi = (t_wi*)malloc(sizeof(t_wi))))
		fractol_memmory_error();
	if (!(wi->title = ft_strjoin("fractol-", title)))
		return (NULL);
	wi->mlx = mlx_init();
	wi->width = 1200;
	wi->height = 600;
	wi->win = mlx_new_window(wi->mlx, wi->width, wi->height, wi->title);
	return (wi);
}
