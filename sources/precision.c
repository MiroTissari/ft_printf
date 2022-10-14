/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:48:35 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 15:31:19 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*di_precision(t_check *data, char *str, int len)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (data->dot == 1)
		data->zero = 0;
	if (data->precision > len)
	{
		new = ft_strnew(data->precision);
		if (data->negative == 1 && data->zero == 0
			&& data->precision < data->width)
		{
			new[i++] = '-';
			data->precision++;
		}
		while (i < (data->precision - len))
			new[i++] = '0';
		while (i < data->precision)
			new[i++] = str[j++];
	}
	else
		new = ft_strdup(str);
	return (new);
}

char	*oux_precision(t_check *data, char *str, int len, int form)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (data->precision > len)
	{
		new = ft_strnew(data->precision);
		while (i < (data->precision - len))
			new[i++] = '0';
		while (i < data->precision)
			new[i++] = str[j++];
	}
	else
		new = ft_strdup(str);
	if (form == 'x' && data->hash == 1 && str[0] != '0' && data->dot == 1)
		new = ft_strjoin_free("0x", new, 0, 2);
	else if (form == 'X' && data->hash == 1 && str[0] != '0' && data->dot == 1)
		new = ft_strjoin_free("0X", new, 0, 2);
	else if (form == 'o' && data->hash == 1 && str[0] != '0' && new[0] != '0')
		new = ft_strjoin_free("0", new, 0, 2);
	return (new);
}

char	*string_precision(t_check *data, char *str, int len)
{
	char	*new;

	if (data->precision > len)
	{
		new = ft_strdup(str);
	}
	else if (data->dot == 1)
	{
		new = ft_strnew(data->precision);
		new = ft_strncpy(new, str, data->precision);
	}
	else
		new = ft_strdup(str);
	return (new);
}

/*
precision gives the minimum number of digits to appear for the d, i,
o, u, x, and X conversions, the number of digits to appear after
the decimal-point character for a, A, e, E, f, and F conversions,
the maximum number of significant digits for the g and G conversions,
or the maximum number of bytes to be written for s conversions.
*/
