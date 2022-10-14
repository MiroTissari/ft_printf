/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:48:22 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 15:31:38 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*int_flag_check(t_check *data, char	*str, int len)
{
	if (data->negative == 1 && str[0] == '0' && str[1] && data->precision < len)
		str[0] = '-';
	else if (data->negative == 1 && !ft_strchr(str, '-'))
		str = ft_strjoin_free("-", str, 0, 2);
	if (data->plus == 1 && data->negative == 0 && data->format != 'u')
	{
		if (str[0] == '0' && str[1] && data->precision < len)
			str[0] = '+';
		else
			str = ft_strjoin_free("+", str, 0, 2);
		data->plus = 0;
	}
	else if (data->space == 1 && data->negative == 0 && data->format != 'u')
	{
		if (str[0] == '0' && str[1] && data->precision < len)
			str[0] = ' ';
		else
			str = ft_strjoin_free(" ", str, 0, 2);
		data->space = 0;
	}
	return (str);
}

void	handle_uint_zero(t_check *data, char *str)
{
	char	*save;
	int		len;

	if (data->dot == 1 && data->precision == 0)
	{
		save = ft_strdup("");
		data->zero = 0;
	}
	else
		save = oux_precision(data, str, ft_strlen(str), data->format);
	if (data->zero == 0)
		save = int_flag_check(data, save, ft_strlen(save));
	len = ft_strlen(save);
	free (str);
	if (data->width > len)
		str = parcer(data, save, len);
	else
		str = ft_strdup(save);
	free (save);
	str = int_flag_check(data, str, ft_strlen(str));
	print_str(data, str);
	free (str);
}

void	handle_uint(t_check *data, char *str)
{
	int		len;
	char	*save;

	save = oux_precision(data, str, ft_strlen(str), data->format);
	free (str);
	if (data->zero == 0)
		save = int_flag_check(data, save, ft_strlen(save));
	len = ft_strlen(save);
	if (data->width > len)
		str = parcer(data, save, len);
	else
		str = ft_strdup(save);
	free (save);
	str = int_flag_check(data, str, ft_strlen(str));
	print_str(data, str);
	free (str);
}

void	handle_int_zero(t_check *data, char *str)
{
	char	*save;
	int		len;

	if (data->dot == 1 && data->precision == 0)
	{
		save = ft_strdup("");
		data->zero = 0;
	}
	else
		save = di_precision(data, str, ft_strlen(str));
	if (data->zero == 0)
		save = int_flag_check(data, save, ft_strlen(save));
	len = ft_strlen(save);
	free (str);
	if (data->width > len)
		str = parcer(data, save, len);
	else
		str = ft_strdup(save);
	free (save);
	str = int_flag_check(data, str, ft_strlen(str));
	print_str(data, str);
	free (str);
}

void	handle_int(t_check *data, char *str)
{
	int		len;
	char	*save;

	if (data->dot == 1)
		data->zero = 0;
	save = di_precision(data, str, ft_strlen(str));
	free (str);
	if (data->zero == 0)
		save = int_flag_check(data, save, ft_strlen(save));
	len = ft_strlen(save);
	if (data->width > len)
		str = parcer(data, save, len);
	else
		str = ft_strdup(save);
	free (save);
	str = int_flag_check(data, str, ft_strlen(str));
	print_str(data, str);
	free (str);
}
