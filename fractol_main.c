/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:29:14 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/06 14:14:44 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_choice_fractal(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp("julia", av[i]) == 0)
			fractol_julia(av[i]);
		if (ft_strcmp("mandelbrot", av[i]) == 0)
			fractol_mandelbrot(av[i]);
		if (ft_strcmp("sierpinski", av[i]) == 0)
			fractol_sierpinski(av[i]);
		if (ft_strcmp("burningship", av[i]) == 0)
			fractol_burningship(av[i]);
		i++;
	}
}

int			main(int ac, char **av)
{
	fractol_error_ac(ac);
	fractol_error_name(ac, av);
	fractol_choice_fractal(ac, av);
	return (0);
}
