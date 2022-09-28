/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:48:16 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/20 13:33:52 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*float_flag_check(t_check *data, char *str)
{
	if (data->hash == 1 && !ft_strchr(str, '.'))
		str = ft_strjoin_free(str, ".", 0, 1);
	if (data->plus == 1)
		str = ft_strjoin_free("+", str, 0, 2);
	else if (data->space == 1)
		str = ft_strjoin_free(" ", str, 0, 2);
	return (str);
}

char	*float_nan_inf(long double num, t_check *data)
{
	char	*str;

	if (num == (1.0 / 0.0))
		str = ft_strdup("inf");
	else if (num == -(1.0 / 0.0))
		str = ft_strdup("-inf");
	else if (num != num)
	{
		if (data->negative == 1)
			str = ft_strdup("-nan");
		else
			str = ft_strdup("nan");
	}
	else
		str = ft_ftoa(num, data->precision, data->negative);
	return (str);
}

long double	bankers_round(t_check *data, int prec, long double num)
{
	long double	round;
	long double	ret;

	round = 0.5;
	if (data->negative == 1)
		num = -num;
	while (prec > 0)
	{
		round /= 10;
		prec--;
	}
	ret = num + round;
	return (ret);
}

long double	float_round(t_check *data, int prec, long double num)
{
	long double	temp;
	long double	temp2;

	if (data->negative == 1)
		num = -num;
	temp = num * double_power(10, prec);
	temp2 = (temp - (long long)temp) * 10;
	if (temp - (long long)temp == 0.5 || (temp2 < 5.0 && temp2 > 4.9))
	{
		if ((long long)temp % 2 != 1 || data->cap_l == 1 || temp2 < 5)
			num = temp / double_power(10, prec);
		else
			num = bankers_round(data, prec, num);
	}
	else
			num = bankers_round(data, prec, num);
	return (num);
}

void	handle_float(t_check *data, long double num)
{
	char		*str;
	char		*save;

	if (num == 1.0 / 0.0 || num == -1.0 / 0.0 || num != num)
		str = float_nan_inf(num, data);
	else
	{
		num = float_round(data, data->precision, num);
		str = ft_ftoa(num, data->precision, data->negative);
	}
	if (data->width >= (int)ft_strlen(str))
		save = parcer(data, str, ft_strlen(str));
	else
		save = ft_strdup(str);
	free (str);
	str = float_flag_check(data, save);
	print_str(data, str);
	free (str);
}
