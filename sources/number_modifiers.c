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

void	modify_float(t_flags *data, va_list *argp)
{
	long double	num;

	if (data->cap_l == 1)
		num = va_arg(*argp, long double);
	else
		num = (double)va_arg(*argp, double);
	if (data->period == 0)
		data->precision = 6;
	if (ft_is_neg(num))
		data->negative = 1;
	handle_float(data, num);
}

void	modify_di(t_flags *data, va_list *argp)
{
	long long int	num;

	if (data->h == 1)
		num = (signed char)va_arg(*argp, int);
	else if (data->hh == 1)
		num = (short int)va_arg(*argp, int);
	else if (data->l == 1)
		num = (long int)va_arg(*argp, long int);
	else if (data->ll == 1)
		num = va_arg(*argp, long long);
	else
		num = (int)va_arg(*argp, int);
	handle_int(data, ft_itoa_base(num, DEC), num);
}

void	modify_oux(t_flags *data, va_list *argp, char format)
{
	unsigned long long int	num;

	if (data->h == 1)
		num = (unsigned char)va_arg(*argp, unsigned int);
	else if (data->hh == 1)
		num = (unsigned short)va_arg(*argp, unsigned int);
	else if (data->l == 1)
		num = (unsigned long)va_arg(*argp, unsigned long int);
	else if (data->ll == 1)
		num = va_arg(*argp, unsigned long long int);
	else
		num = (unsigned int)va_arg(*argp, unsigned int);
	if (format == 'o')
		handle_oct(data, uitoa_base(num, OCT), num);
	if (format == 'u')
		handle_uint(data, uitoa_base(num, DEC), num);
	if (format == 'X')
		handle_hex(data, uitoa_base(num, HEX), num);
	if (format == 'x')
		handle_hex(data, uitoa_base(num, HX), num);
}