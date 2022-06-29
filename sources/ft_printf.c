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

#include "../includes/ft_printf.h"

void	set_values(t_stuff *data)
{
	data->flag_nb = 0;
	data->hash = 0;
	data->minus = 0;
	data->plus = 0;
	data->space = 0;
	data->zero = 0;
	data->index_add = 0;
}

int	verify_flags(char *s, t_stuff *data)
{
	int	num;

	num = 0;
	while (s[num] == ' ' || s[num] == '0' || s[num] == '#' || s[num] == '-'
		|| s[num] == '+' || s[num] == '.' || s[num] == '*' || s[num] == 'l'
		|| s[num] == 'h' || s[num] == 'L' || s[num] == 'j' || s[num] == 't'
		|| s[num] == 'z' || (s[num] >= 48 && s[num] <= 57))
		num++;
	if (num != 0)
	{
		data->flag_nb = num;
		return (1);
	}
	return (0);
}

int	check_flags(char *str, t_stuff *data, int i)
{
	if (!verify_flags(&str[i], data))
		return (i);
	if (str[i] == ' ' || str[i] == '0' || str[i] == '#' || str[i] == '-'
		|| str[i] == '+')
		set_flags(str[i], data);
	else if (str[i] >= 48 && str[i] <= 57)
		set_width(str[i], data);
	else if (str[i] == '.' || str[i] == '*')
		set_precision(str[i], data);
		
	check_flags(str, data, i + 1);
}

int	ft_printf(const char *str, ...)
{
	t_stuff	data;
	va_list	argp;
	int		i;

	va_start(argp, str);
	data.ret_val = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			set_values(&data);
			i = check_flags(str, &data, i + 1);
			format_identifier(&str[i], argp, &data);
			i += data.index_add;
		}
		else
			data.ret_val += write(1, str[i], 1);
		i++;
	}
	va_end(argp);
	return (data.ret_val);
}
