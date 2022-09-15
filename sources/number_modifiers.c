/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_modifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:48:25 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/15 17:37:15 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
char	*modifier_hh(t_flags *data, va_list argp)
{
	if (data->h == 1 && (data->format == 'd' || data->format == 'i'))
		return (ft_itoa_base((signed char)va_arg(argp, int), DEC, data));
	else if (data->h == 1 && data->format == 'x')
		return (uitoa_base((unsigned char)va_arg(argp, unsigned int), HeX));
	else if (data->h == 1 && data->format == 'X')
		return (uitoa_base((unsigned char)va_arg(argp, unsigned int), HEX));
	else if (data->h == 1 && data->format == 'u')
		return (uitoa_base((unsigned char)va_arg(argp, unsigned int), DEC));
	else if (data->h == 1 && data->format == 'o')
		return (uitoa_base((unsigned char)va_arg(argp, unsigned int), OCT));
	else if (data->hh == 1 && (data->format == 'd' || data->format == 'i'))
		return (ft_itoa_base((short int)va_arg(argp, int), DEC, data));
	else if (data->hh == 1 && data->format == 'x')
		return (uitoa_base((unsigned short)va_arg(argp, unsigned int), HeX));
	else if (data->hh == 1 && data->format == 'X')
		return (uitoa_base((unsigned short)va_arg(argp, unsigned int), HEX));
	else if (data->hh == 1 && data->format == 'u')
		return (uitoa_base((unsigned short)va_arg(argp, unsigned int), DEC));
	else if (data->hh == 1 && data->format == 'o')
		return (uitoa_base((unsigned short)va_arg(argp, unsigned int), OCT));
	return (0);
}

char	*modifier_ll(t_flags *data, va_list argp)
{
	if (data->l == 1 && (data->format == 'd' || data->format == 'i'))
		return (ft_itoa_base((long int)va_arg(argp, long int), DEC, data));
	else if (data->l == 1 && data->format == 'x')
		return (uitoa_base((unsigned long)va_arg(argp, unsigned long), HeX));
	else if (data->l == 1 && data->format == 'X')
		return (uitoa_base((unsigned long)va_arg(argp, unsigned long), HEX));
	else if (data->l == 1 && data->format == 'u')
		return (uitoa_base((unsigned long)va_arg(argp, unsigned long), DEC));
	else if (data->l == 1 && data->format == 'o')
		return (uitoa_base((unsigned long)va_arg(argp, unsigned long), OCT));
	else if (data->ll == 1 && (data->format == 'd' || data->format == 'i'))
		return (ft_itoa_base((long long)va_arg(argp, long long), DEC, data));
	else if (data->ll == 1 && data->format == 'x')
		return (uitoa_base((unsigned long long)va_arg(argp, unsigned long long), HeX));
	else if (data->ll == 1 && data->format == 'X')
		return (uitoa_base(va_arg(argp, unsigned long long), HEX));
	else if (data->ll == 1 && data->format == 'u')
		return (uitoa_base(va_arg(argp, unsigned long long), DEC));
	else if (data->ll == 1 && data->format == 'o')
		return (uitoa_base(va_arg(argp, unsigned long long), OCT));
	return (0);
}

char	*modifier_check(t_flags *data, va_list argp, char format)
{
	char	*new;

	if (data->l == 1 || data->ll == 1)
		new = modifier_ll(data, argp);
	else if (data->h == 1 || data->hh == 1)
		new = modifier_hh(data, argp);
	if (format == 'd' || format == 'i')
		new = ft_itoa_base(va_arg(argp, int), DEC, data);
	else if (format == 'u')
		new = uitoa_base(va_arg(argp, unsigned int), DEC);
	else if (format == 'o')
		new = uitoa_base(va_arg(argp, unsigned int), OCT);
	else if (format == 'X')
		new = uitoa_base(va_arg(argp, unsigned int), HEX);
	else if (format == 'x')
		new = uitoa_base(va_arg(argp, unsigned int), HeX);
	return (new);
}

void	handle_numbers(t_flags *data, va_list argp, char format)
{
	char	*string;

	string = modifier_check(data, argp, format);
	if (format == 'd' || format == 'i')
		handle_int(data, string);
	else if (format == 'u')
		handle_uint(data, string);
	else if (format == 'o')
		handle_oct(data, string);
	else if (format == 'X')
		handle_hex(data, string);
	else if (format == 'x')
		handle_hex(data, string);
}
*/

void	modify_float(t_flags *data, va_list argp)
{
	long double	num;

	if (data->l == 1)
		num = (double)va_arg(argp, double);
	else if (data->cap_l == 1)
		num = va_arg(argp, long double);
	else
		num = (float)va_arg(argp, double);
//	num = (long double)num;
	if (data->period == 0)
		data->precision = 6;
	handle_float(data, num);
}

void	modify_di(t_flags *data, va_list argp)
{
	long long int	num;

	if (data->h == 1)
		num = (signed char)va_arg(argp, int);
	else if (data->hh == 1)
		num = (short int)va_arg(argp, int);
	else if (data->l == 1)
		num = (long int)va_arg(argp, long int);
	else if (data->ll == 1)
		num = va_arg(argp, long long);
	else
		num = (int)va_arg(argp, int);
	handle_int(data, ft_itoa_base(num, DEC), num);
}

void	modify_oux(t_flags *data, va_list argp, char format)
{
	unsigned long long int	num;

	if (data->h == 1)
		num = (unsigned char)va_arg(argp, unsigned int);
	else if (data->hh == 1)
		num = (unsigned short)va_arg(argp, unsigned int);
	else if (data->l == 1)
		num = (unsigned long)va_arg(argp, unsigned long int);
	else if (data->ll == 1)
		num = va_arg(argp, unsigned long long int);
	else
		num = (unsigned int)va_arg(argp, unsigned int);
	if (format == 'o')
		handle_oct(data, uitoa_base(num, OCT), num);
	if (format == 'u')
		handle_uint(data, uitoa_base(num, DEC), num);
	if (format == 'X')
		handle_hex(data, uitoa_base(num, HEX), num);
	if (format == 'x')
		handle_hex(data, uitoa_base(num, HX), num);
}
