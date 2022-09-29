/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:51:54 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/29 21:46:45 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_decimal(long double dec, int precision)
{
	int					i;
	char				*new;
	//unsigned long long	temp;

	i = 0;
	new = ft_strnew(precision);
//	temp = (unsigned long long)(dec * double_power(10, precision));
//	if ()
	while (precision--)
	{
		dec *= 10;
		new[i++] = (long long)dec + '0';
		dec -= (long long)dec;
	}
	new = ft_strjoin_free(".", new, 0, 2);
	return (new);
}

char	*ft_ftoa(long double num, int precision, int neg, t_check *data)
{
	char		*new;
	long long	integer;
	long double	dec;

	integer = (long long)num;
	dec = num - (long double)integer;
	new = ft_itoa_base(integer, DEC);
	if (precision)
		new = ft_strjoin_free(new, get_decimal(dec, precision), 0, 0);
	if ((neg == 1 && data->zero == 0) || (data->negative == 1
			&& (int)ft_strlen(new) + 1 >= data->width))
		new = ft_strjoin_free("-", new, 0, 2);
	return (new);
}
