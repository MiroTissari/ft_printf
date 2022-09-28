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

void	length_check(char *str, int i)
{
	int		len;

	len = 0;
	while (str[i + len] >= 48 && str[i + len] <= 57)
		len++;
	if (len > 10)
	{
		write(1, "width/precision too big", 24);
		exit (1);
	}
}

int	set_width_and_precision(char *str, int i, t_check *data)
{
	int		j;
	char	width[11];
	char	prec[11];

	length_check(str, i);
	j = 0;
	if (data->width == 0 && data->dot == 0)
	{
		while (str[i] >= 48 && str[i] <= 57)
			width[j++] = str[i++];
		if (str[i] == '.')
		{
			data->dot = 1;
			i++;
		}
		data->width = ft_atoi(width);
	}
	if (data->precision == 0 && data->dot == 1)
	{
		j = 0;
		while (str[i] >= 48 && str[i] <= 57)
			prec[j++] = str[i++];
		data->precision = ft_atoi(prec);
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
/*
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
*/
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
	return (0);
}
