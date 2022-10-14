/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:48:11 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 15:38:55 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_oct(t_check *data, char *str, unsigned long long int num)
{
	char	*save;

	if (data->dot == 1)
		data->zero = 0;
	if ((num == 0 && data->dot == 1))
		save = handle_hex_zero(data);
	else
		save = oux_precision(data, str, ft_strlen(str), data->format);
	free (str);
	if (data->width > (int)ft_strlen(save))
		str = parcer(data, save, ft_strlen(save));
	else
		str = ft_strdup(save);
	if (data->hash == 1 && str[0] != '0' && save[0] != '0')
		str = ft_strjoin_free("0", str, 0, 2);
	free (save);
	print_str(data, str);
	free (str);
}

char	*hash_hex_edge(t_check *data, char *str, unsigned long long int nb)
{
	if (data->format == 'x' && nb > 0)
		str = ft_strjoin("0x", str);
	else if (data->format == 'X' && nb > 0)
		str = ft_strjoin("0X", str);
	data->hash = 0;
	return (str);
}

char	*hash_hex(t_check *data, char *str, unsigned long long int num)
{
	int	i;

	i = 0;
	if (data->hash == 1 && data->dot == 0 && num > 0 && !ft_strchr(str, 'x'))
	{
		while (str[i] == ' ')
			i++;
		if (i >= 2 && data->minus == 0)
		{
			str[i - 2] = '0';
			str[i - 1] = data->format;
		}
		else if (data->zero == 1 && str[i] == '0' && str[i + 1] == '0')
		{
			str[i] = '0';
			str[i + 1] = data->format;
		}
		else
		{
			str[0] = '0';
			str[1] = data->format;
		}
		data->hash = 0;
	}
	return (str);
}

char	*handle_hex_zero(t_check *data)
{
	char	*new;

	if (data->precision < 1)
	{
		if (data->format == 'o' && data->hash == 1)
			new = ft_strdup("0");
		else
			new = ft_strdup("");
	}
	else
	{
		new = ft_strnew(data->precision);
		new = ft_memset(new, '0', data->precision);
	}
	data->hash = 0;
	return (new);
}

void	handle_hex(t_check *data, char *str, unsigned long long int num)
{
	char	*save;

	if (data->dot == 1 || data->minus == 1)
		data->zero = 0;
	if (num == 0)
		data->hash = 0;
	if ((num == 0 && data->dot == 1))
		save = handle_hex_zero(data);
	else
		save = oux_precision(data, str, ft_strlen(str), data->format);
	free (str);
	if (data->width >= (int)ft_strlen(save))
		str = hex_parcer(data, save, ft_strlen(save));
	else if ((data->hash == 1 && ft_strlen(save) < 3) || (data->width == 0
			&& data->dot == 0 && data->hash == 1))
		str = hash_hex_edge(data, save, num);
	else
		str = ft_strdup(save);
	str = hash_hex(data, str, num);
	free (save);
	print_str(data, str);
	free (str);
}
