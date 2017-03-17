/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:35:04 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/22 17:28:48 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractol_error_ac(int ac)
{
	if (ac != 2)
	{
		ft_putendl("\x1b[31;01musage: ./fractol [name_of_fractal]");
		write(1, "\n", 1);
		ft_putstr("\x1b[33;01m#############################################");
		ft_putendl("\x1b[33;01m######################################");
		write(1, "\n", 1);
		ft_putendl("\x1b[32;01mName of valid fractal:");
		ft_putendl("\x1b[32;01m\t\t\t[julia]");
		ft_putendl("\x1b[32;01m\t\t\t[mandelbrot]");
		ft_putendl("\x1b[32;01m\t\t\t[sierpinski]");
		ft_putendl("\x1b[32;01m\t\t\t[burningship]");
		write(1, "\n", 1);
		ft_putstr("\x1b[0;01m#############################################");
		ft_putendl("\x1b[0;01m######################################");
		write(1, "\n", 1);
		ft_putendl("\x1b[31;07;05m\t\t\tTry it again with valid fractal.");
		exit(0);
	}
}

void		fractol_error_name(int ac, char **av)
{
	if (ft_strcmp("julia", av[ac - 1]) != 0
			&& ft_strcmp("mandelbrot", av[ac - 1]) != 0
			&& ft_strcmp("sierpinski", av[ac - 1])
			&& ft_strcmp("burningship", av[ac - 1]))
	{
		ft_putendl("\x1b[33;01mName of valid fractal:");
		ft_putendl("\x1b[32;01m\t\t\t[julia]");
		ft_putendl("\x1b[32;01m\t\t\t[mandelbrot]");
		ft_putendl("\x1b[32;01m\t\t\t[sierpinski]");
		ft_putendl("\x1b[32;01m\t\t\t[burningship]");
		exit(0);
	}
}

void		fractol_memmory_error(void)
{
	ft_putendl("\x1b[31;01mMemmory error!!!");
	exit(0);
}
