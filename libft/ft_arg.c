/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:40:20 by bbach             #+#    #+#             */
/*   Updated: 2023/04/28 18:06:34 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_stp
{
	int		d;
	char	*s;
}		t_stp;

const char	*ft_arg1(va_list arg, const char *format, t_struct *sc)
{
	t_stp	h;

	if (*format == 'd' || *format == 'i')
	{
		h.d = va_arg(arg, int);
		ft_putnbr(h.d);
		sc->len += ft_intlen(h.d, *format);
	}
	else if (*format == 's')
	{
		h.s = va_arg(arg, char *);
		if (!h.s)
		{
			write(1, "(null)", 6);
			sc->len += 6;
		}
		else
		{
			ft_putstr(h.s);
			sc->len += ft_strlen3(h.s);
		}
	}
	else
		return (0);
	return (++format);
}

const char	*ft_arg2(va_list arg, const char *format, t_struct *sc)
{
	unsigned char	c;
	void			*p;

	if (*format == 'c')
	{
		c = va_arg(arg, int);
		ft_putchar(c);
		sc->len += 1;
	}
	else if (*format == 'p')
	{
		p = va_arg(arg, void *);
		ft_printadress((unsigned long int) p);
		if (p == 0)
			sc->len += ft_unsignedlonglen
				((unsigned long int)p, *format) + 3;
		sc->len += ft_unsignedlonglen((unsigned long int)p, *format) + 2;
	}
	else
		return (0);
	format++;
	return (format);
}

const char	*ft_arg3(va_list arg, const char *format, t_struct *sc)
{
	unsigned int	u;

	if (*format == 'u')
	{
		u = va_arg(arg, unsigned int);
		ft_putnbru(u);
		sc->len += ft_unsignedlen(u, *format);
	}
	else if (*format == '%')
	{
		ft_putchar('%');
		sc->len += 1;
	}
	else
		return (0);
	format++;
	return (format);
}

const char	*ft_arg4(va_list arg, const char *format, t_struct *sc)
{
	unsigned int	x;
	unsigned int	y;

	if (*format == 'x')
	{
		x = va_arg(arg, unsigned int);
		ft_printhexalow(x);
		sc->len += ft_unsignedlen(x, *format);
	}
	else if (*format == 'X')
	{
		y = va_arg(arg, unsigned int);
		ft_printhexaup(y);
		sc->len += ft_unsignedlen(y, *format);
	}
	else
		return (0);
	format++;
	return (format);
}
