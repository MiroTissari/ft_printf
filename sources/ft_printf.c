/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:55:14 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/20 17:09:45 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*sources/ft_printf.c:17:12: error: array type 'char [17]' is not assignable
		data->hex = "0123456789abcdef";*/

void	set_values(t_check *data)
{
	data->flag_nb = 0;
	data->hash = 0;
	data->minus = 0;
	data->plus = 0;
	data->space = 0;
	data->zero = 0;
	data->index_add = 0;
	data->dot = 0;
	data->l = 0;
	data->ll = 0;
	data->h = 0;
	data->hh = 0;
	data->cap_l = 0;
	data->width = 0;
	data->precision = 0;
	data->format = 0;
	data->negative = 0;
}

int	false_output(char *str, t_check *data, int i, int len)
{
	while (len >= 0)
	{
		data->ret_val += write(1, &str[i++], 1);
		len--;
	}
	return (i - 1);
}

int	check_flags(char *str, t_check *data, int i, va_list *argp)
{
	int	nb;

	nb = verify_flags(&str[i]);
	if (nb != 0)
		return (false_output(str, data, i - 1, nb + 1));
	nb = i;
	while (str[i] == ' ' || str[i] == '0' || str[i] == '#' || str[i] == '-'
		|| str[i] == '+')
	{
		set_flags(str[i], data);
		i++;
	}
	if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.')
		i = set_width_and_precision(str, i, data);
	while (str[i] == 'l' || str[i] == 'h' || str[i] == 'L')
	{
		set_modifiers(str, i, data);
		i++;
	}
	if (data->l && data->cap_l)
		return (false_output(str, data, nb - 1, i - nb));
	format_identifier(&str[i], argp, data);
	return (i);
}

void	format_identifier(const char *str, va_list *argp, t_check *data)
{
	int	i;

	i = 0;
	data->format = str[i];
	if (str[i] == '%')
		handle_char(data, '%');
	else if (str[i] == 'c')
		handle_char(data, va_arg(*argp, int));
	else if (str[i] == 's')
		handle_string(data, va_arg(*argp, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		modify_di(data, argp);
	else if (str[i] == 'o' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
		modify_oux(data, argp, str[i]);
	else if (str[i] == 'f')
		modify_float(data, argp);
	else if (str[i] == 'p')
		handle_pointer(data, argp);
/*	else
		perror("format identifier not found or supported");*/
	//data->index_add++;
}

int	ft_printf(const char *str, ...)
{
	t_check	data;
	va_list	argp;
	int		i;
	char	*save;

	save = ft_strdup(str);
	va_start(argp, str);
	data.ret_val = 0;
	i = 0;
	while (save[i])
	{
		if (save[i] == '%' && save[i + 1])
		{
			set_values(&data);
			i = check_flags(save, &data, i + 1, &argp);
		}
		else
			data.ret_val += write(1, &save[i], 1);
		i++;
	}
	va_end(argp);
	free (save);
	return (data.ret_val);
}
