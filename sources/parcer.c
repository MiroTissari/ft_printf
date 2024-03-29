/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:48:30 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 15:31:28 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pointer_parcer(t_check *data, char *str, int len)
{
	char	c;
	char	*new;
	int		i;

	i = 0;
	c = ' ';
	if (data->zero == 1)
		c = '0';
	new = ft_strnew(data->width);
	new = ft_memset(new, c, data->width);
	if (data->minus == 0 && data->width > len)
	{
		while (new[data->width - len--] != '\0')
			new[data->width - 1 - len] = str[i++];
	}
	else
	{
		len = 2;
		while (str[i] != '\0')
			new[len++] = str[i++];
	}
	return (new);
}

char	*hex_parcer(t_check *data, char *str, int len)
{
	char	c;
	char	*new;
	int		i;

	i = 0;
	c = ' ';
	if (data->zero == 1)
		c = '0';
	new = ft_strnew(data->width);
	new = ft_memset(new, c, data->width);
	if (data->minus == 0 && data->width > len)
	{
		while (new[data->width - len--] != '\0')
			new[data->width - 1 - len] = str[i++];
	}
	else
	{
		new = hash_hex(data, new, len);
		len = 0;
		if (new[1] == 'x' || new[1] == 'X')
			len = 2;
		while (str[i] != '\0')
			new[len++] = str[i++];
	}
	return (new);
}

char	*parcer(t_check *data, char *str, int len)
{
	char	c;
	char	*new;
	int		i;

	i = 0;
	c = ' ';
	if (data->zero == 1 && data->format != 'c' && data->format != 's')
		c = '0';
	new = ft_strnew(data->width);
	new = ft_memset(new, c, data->width);
	if (data->minus == 0 && data->width > len)
	{
		while (new[data->width - len--] != '\0')
			new[data->width - 1 - len] = str[i++];
	}
	else
	{
		len = 0;
		while (str[i])
			new[len++] = str[i++];
	}
	if (data->format == 'd' || data->format == 'i' || data->format == 'u')
			new = int_flag_check(data, new, ft_strlen(new));
	return (new);
}
