/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:51:54 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/20 15:51:56 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_decimal(long double dec, int precision)
{
	int			pr_cpy;
	long long	i;
	long long	temp;
	char		*new;

	pr_cpy = precision;
	while (precision--)
		dec *= 10;
	i = (long long)dec;
	dec *= 10;
	temp = (long long)dec;
	if ((temp + 1) / 10 > i)
		i = i + 1;
	if (i == 0)
	{
		new = ft_strnew(pr_cpy);
		new = ft_memset(new, '0', pr_cpy);
	}
	else
		new = ft_itoa_base(i, DEC);
	new = ft_strjoin_free(".", new, 0, 2);
	return (new);
}

char	*ft_ftoa(long double num, int precision, int neg)
{
	char		*new;
	long long	integer;
	long double	dec;

	integer = (long long)num;
	dec = num - (long double)integer;
	new = ft_itoa_base(integer, DEC);
	if (precision)
		new = ft_strjoin_free(new, get_decimal(dec, precision), 0, 0);
	if (neg == 1)
		new = ft_strjoin_free("-", new, 0, 2);
	return (new);
}
/*
char	*ft_ftoa(long double d, int precision)
{
	char		*number;

	if (d == (1.0 / 0.0))
		return (ft_strdup("inf"));
	else if (d == -(1.0 / 0.0))
		return (ft_strdup("-inf"));
	else if (!(d == d))
		return (ft_strdup("nan"));
	else if (precision < 0)
		return (ft_strdup("0"));
	if (d == (9223372036854775807 * 1.0))
	{
		if (precision == 0)
			return (ft_strdup("9223372036854775808"));
		number = ft_strdup("9223372036854775808.");
		while (precision-- > 0)
			number = ft_free_function("ft_strjoin", number, "0", 1);
	}
	else
	{
		number = get_int(d, precision + 1);
		number = ft_roundup_number(number);
	}
	return (number);
}
*/