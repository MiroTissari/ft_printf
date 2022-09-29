/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:47:58 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/29 22:35:44 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_modifiers(char *str, int i, t_check *data)
{
	if (str[i] == 'l')
	{
		if (str[i + 1] == 'l')
			data->ll = 1;
		else
			data->l = 1;
	}
	else if (str[i] == 'h')
	{
		if (str[i + 1] == 'h')
			data->hh = 1;
		else
			data->h = 1;
	}
	else if (str[i] == 'L')
		data->cap_l = 1;
	while (str[i] == 'l' || str[i] == 'h' || str[i] == 'L')
		i++;
	return (i);
}

void	temp_free(t_check *data)
{
	free (data->temp_width);
	free (data->temp_prec);
}

int	set_width_and_precision(char *str, int i, t_check *data)
{
	int	j;

	j = 0;
	data->temp_width = ft_strnew(100);
	data->temp_prec = ft_strnew(100);
	if (data->width == 0 && data->dot == 0)
	{
		while (str[i] >= 48 && str[i] <= 57)
			data->temp_width[j++] = str[i++];
		if (str[i] == '.')
		{
			data->dot = 1;
			i++;
		}
		data->width = ft_atoi(data->temp_width);
	}
	if (data->precision == 0 && data->dot == 1)
	{
		j = 0;
		while (str[i] >= 48 && str[i] <= 57)
			data->temp_prec[j++] = str[i++];
		data->precision = ft_atoi(data->temp_prec);
	}
	temp_free(data);
	return (i);
}

void	set_flags(char flag, t_check *data)
{
	if (flag == ' ' && data->plus == 0)
		data->space = 1;
	else if (flag == '0' && data->minus == 0)
		data->zero = 1;
	else if (flag == '-')
	{
		data->minus = 1;
		data->zero = 0;
	}
	else if (flag == '+')
	{
		data->plus = 1;
		data->space = 0;
	}
	else if (flag == '#')
		data->hash = 1;
}

int	verify_flags(char *s)
{
	int	num;

	num = 0;
	while (s[num] == ' ' || s[num] == '0' || s[num] == '#' || s[num] == '-'
		|| s[num] == '+')
		num++;
	while ((s[num] >= 48 && s[num] <= 57))
		num++;
	if (s[num] == '.')
	{
		num++;
		while ((s[num] >= 48 && s[num] <= 57))
			num++;
	}
	while (s[num] == 'l' || s[num] == 'h' || s[num] == 'L')
		num++;
	if (s[num] != '%' && s[num] != 'f' && s[num] != 'p' && s[num] != 'c'
		&& s[num] != 's' && s[num] != 'd' && s[num] != 'i' && s[num] != 'o'
		&& s[num] != 'u' && s[num] != 'x' && s[num] != 'X')
		return (num);
	return (-1);
}
