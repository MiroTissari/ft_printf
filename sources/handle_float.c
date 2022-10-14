/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:48:16 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 15:31:41 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*float_flag_check(t_check *data, char *str, int len)
{
	if (data->hash == 1 && !ft_strchr(str, '.'))
		str = ft_strjoin_free(str, ".", 0, 1);
	if (data->plus == 1 && data->negative == 0)
	{
		if (str[0] == '0' && str[1] && data->precision + 2 < len)
			str[0] = '+';
		else
			str = ft_strjoin_free("+", str, 0, 2);
		data->plus = 0;
	}
	else if (data->space == 1 && data->negative == 0)
	{
		if (str[0] == '0' && str[1] && data->precision + 2 < len)
			str[0] = ' ';
		else
			str = ft_strjoin_free(" ", str, 0, 2);
		data->space = 0;
	}
	else if (data->negative == 1 && data->zero == 1)
		str[0] = '-';
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
		str = ft_ftoa(num, data->precision, data->negative, data);
	return (str);
}

long double	bankers_round(int prec, long double num)
{
	long double	round;
	long double	ret;

	round = 0.5;
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

	if (data->negative == 1)
		num = -num;
	temp = num * double_power(10, prec);
	if (temp - (long long)temp == 0.5)
	{
		if ((long long)temp % 2 != 1 || data->cap_l == 1)
			num = temp / double_power(10, prec);
		else
			num = bankers_round(prec, num);
	}
	else
			num = bankers_round(prec, num);
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
		str = ft_ftoa(num, data->precision, data->negative, data);
	}
	if (data->width >= (int)ft_strlen(str))
		save = parcer(data, str, ft_strlen(str));
	else
		save = ft_strdup(str);
	free (str);
	str = float_flag_check(data, save, ft_strlen(save));
	print_str(data, str);
	free (str);
}
