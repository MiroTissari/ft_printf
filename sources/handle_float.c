/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:48:16 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/15 17:41:28 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	float_round(t_flags *data, int prec, long double num)
{
	long double	round;

	round = 0.5;
	if (num < 0)
	{
		round *= -1;
		data->negative = 1;
	}
	while (prec > 0)
	{
		round /= 10.0;
		prec--;
	}
	return (round);
}

long double	float_precision(t_flags *data, int prec, long double num)
{
	num += float_round(data, prec, num);
	while (num > 1)
		num /= 10;
	return (num);//vain compilee varten
}

void	handle_float(t_flags *data, long double num)
{
	long double	flo;

	flo = float_precision(data, data->precision, num);
}
