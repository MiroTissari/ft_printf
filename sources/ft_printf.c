/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:55:14 by mtissari          #+#    #+#             */
/*   Updated: 2022/06/29 20:19:02 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_values(t_stuff *data)
{
	data->flag_nb = 0;
	data->hash = 0;
	data->minus = 0;
	data->plus = 0;
	data->space = 0;
	data->zero = 0;
	data->index_add = 0;
	data->period = 0;
	data->l = 0;
	data->ll = 0;
	data->h = 0;
	data->hh = 0;
	data->L = 0;
	data->width = 0;
	data->precision = 0;
	data->format = 0;
}

int	check_flags(char *str, t_stuff *data, int i)
{
	int	nb;

	nb = verify_flags(&str[i], i);
	while (str[i] == ' ' || str[i] == '0' || str[i] == '#' || str[i] == '-'
		|| str[i] == '+')
	{
		set_flags(str[i], data);
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57) || str[i] == '.')
	{
		i = set_width_and_precision(str, i, data);
		if (str[i] == '.')
			data->period = 1;
		i++;
	}
	while (str[i] == 'l' || str[i] == 'h' || str[i] == 'L')
	{
		i += set_modifiers(str, i, data);
		i++;
	}
	return (nb);
}

void	format_identifier(const char *str, va_list argp, t_stuff *data)
{
	int	i;

	i = 0;
	data->format = str[i];
	if (str[i] == '%')
		handle_char(data, '%');
	else if (str[i] == 'c')
		handle_char(data, va_arg(argp, int));
	else if (str[i] == 's')
		handle_string(data, va_arg(argp, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		modify_di(data, argp);
	else if (str[i] == 'o' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
		modify_oux(data, argp, str[i]);
/*	else if (str[i] == 'f')
		modify_float(data, argp);*/
	else if (str[i] == 'p')
		handle_pointer(data, argp);
/*	else
		perror("format identifier not found or supported");*/
	//data->index_add++;
}

int	ft_printf(const char *str, ...)
{
	t_stuff	data;
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
			i = check_flags(save, &data, i + 1);
			format_identifier(&save[i], argp, &data);
		}
		else
			data.ret_val += write(1, &save[i], 1);
		i++;
	}
	va_end(argp);
	free (save);
	return (data.ret_val);
}
