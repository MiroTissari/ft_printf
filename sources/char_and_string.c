/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_and_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:47:48 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 15:40:06 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_char(t_check *data, int chr)
{
	data->ret_val += write(1, &chr, 1);
}

void	print_str(t_check *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		data->ret_val += write(1, &str[i++], 1);
}

void	handle_char(t_check *data, int chr)
{
	char	*str;
	int		i;

	if (data->width == 0 && data->precision == 0)
		return (print_char(data, chr));
	str = parcer(data, "", 1);
	i = 0;
	if (data->minus == 0)
	{
		while (str[i] != '\0')
			data->ret_val += write(1, &str[i++], 1);
		data->ret_val += write(1, &chr, 1);
	}
	else
	{
		data->ret_val += write(1, &chr, 1);
		while (str[i] != '\0' && i < data->width - 1)
			data->ret_val += write(1, &str[i++], 1);
	}
	free (str);
}

char	*deal_null(char *str)
{
	char	*new;

	if (str == NULL)
	{
		new = ft_strdup("(null)");
	}
	else
		new = ft_strdup(str);
	return (new);
}

void	handle_string(t_check *data, char *str)
{
	char	*temp;
	char	*save;

	save = deal_null(str);
	temp = string_precision(data, save, ft_strlen(save));
	free (save);
	if (data->width > (int)ft_strlen(temp))
		save = parcer(data, temp, ft_strlen(temp));
	else
		save = ft_strdup(temp);
	free (temp);
	print_str(data, save);
	free (save);
}
