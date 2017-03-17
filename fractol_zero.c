/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:17:53 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/22 17:37:25 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_zero_old_new(t_fract **fract)
{
	(*fract)->oldre = 0;
	(*fract)->oldim = 0;
	(*fract)->newre = 0;
	(*fract)->newim = 0;
}
