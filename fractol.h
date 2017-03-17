/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:04:29 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/09 11:16:49 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_fract
{
	double		cre;
	double		cim;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		zoom;
	double		mz;
	double		movex;
	double		movey;
	int			color;
	int			maxiter;
}				t_fract;

typedef struct	s_clr
{
	int			a;
	int			r;
	int			g;
	int			b;
}				t_clr;

typedef struct	s_wi
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		*title;
	void		*img;
	char		*data;
	int			bpp;
	int			size;
	int			endian;
	t_clr		*color;
	t_fract		*fract;
}				t_wi;
void			fractol_error_ac(int ac);
void			fractol_error_name(int ac, char **av);
void			fractol_memmory_error(void);
void			fractol_julia(char *fract_name);
void			fractol_draw_julia(t_fract *jul, t_wi *wi);
void			fractol_mandelbrot(char *fract_name);
void			fractol_draw_mandelbrot(t_fract *man, t_wi *wi);
void			fractol_sierpinski(char *fract_name);
void			fractol_draw_sierpinski(t_fract *sie, t_wi *wi, int x, int y);
void			fractol_burningship(char *fract_name);
void			fractol_draw_bs(t_fract *bs, t_wi *wi);
t_wi			*fractol_create_wi(char *title);
void			fractol_zero_old_new(t_fract **fract);
int				fractol_key_jul(int keycode, t_wi **wi);
int				fractol_key_man(int keycode, t_wi **wi);
int				fractol_key_bs(int keycode, t_wi **wi);
int				fractol_key_sie(int keycode, t_wi **wi);
void			fractol_pixel_put(int x, int y, int color, t_wi *wi);
void			fractol_set_color(t_wi *wi);
int				fractol_get_color(int i, t_wi *wi);
void			fractol_pustr(t_wi *wi);
int				fractol_mouse_jul(int x, int y, t_wi *wi);
int				fractol_zoom_man(int but, int x, int y, t_wi *wi);
int				fractol_zoom_jul(int but, int x, int y, t_wi *wi);
int				fractol_zoom_bs(int but, int x, int y, t_wi *wi);
void			farctol_put_on(t_wi *wi);
void			fractol_sie_put(t_wi *wi);

#endif
