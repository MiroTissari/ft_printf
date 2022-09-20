/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:47:58 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/20 17:10:05 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_modifiers(char *str, int i, t_check *data)
{
	if (str[i] == 'l')
	{
		if (str[i + 1] == 'l')
		{
			data->ll = 1;
		}
		data->l = 1;
	}
	if (str[i] == 'h')
	{
		if (str[i + 1] == 'h')
		{
			data->hh = 1;
		}
		data->h = 1;
	}
	if (str[i] == 'L')
		data->cap_l = 1;
}

int	set_width_and_precision(char *str, int i, t_check *data)
{
	int		len;
	char	temp[11];

	len = 0;
	while (str[i + len] >= 48 && str[i + len] <= 57)
		len++;
	/*if (len > 10)
		error_handling("directive output of 2147483648 bytes exceeds ‘INT_MAX’")*/
	if (data->width == 0 && data->period == 0)
	{
		len = 0;
		while (str[i] >= 48 && str[i] <= 57)
			temp[len++] = str[i++];
		if (str[i] != '.')
			i--;
		temp[len] = '\0';
		data->width = ft_atoi(temp);
	}
	else if (data->precision == 0 && data->period == 1)
	{
		len = 0;
		while (str[i] >= 48 && str[i] <= 57)
			temp[len++] = str[i++];
		i--;
		temp[len] = '\0';
		data->precision = ft_atoi(temp);
	}
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

int	verify_flags(char *s, int i)
{
	int	num;

	num = 0;
	while (s[num] != '%' && s[num] != 'a' && s[num] != 'A' && s[num] != 'g'
		&& s[num] != 'G' && s[num] != 'e' && s[num] != 'E' && s[num] != 'f'
		&& s[num] != 'F' && s[num] != 'n' && s[num] != 'p' && s[num] != 'c'
		&& s[num] != 's' && s[num] != 'd' && s[num] != 'i' && s[num] != 'o'
		&& s[num] != 'u' && s[num] != 'x' && s[num] != 'X')
	{
		if (s[num] != ' ' && s[num] != '0' && s[num] != '#' && s[num] != '-'
			&& s[num] != '+' && s[num] != '.' && s[num] != '*' && s[num] != 'l'
			&& s[num] != 'h' && s[num] != 'L' && s[num] != 'j' && s[num] != 't'
			&& s[num] != 'z')
		{
			if (s[num] <= 48 && s[num] >= 57)
			{
				write(1, "error", 6);
				exit (0);
			}
		}
		num++;
	}
	return (i + num);
}
