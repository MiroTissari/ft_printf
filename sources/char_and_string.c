/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_and_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:47:48 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/20 13:34:09 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char	*temp;
	char	*str;
	int		i;

	if (chr == '%')
		return (print_char(data, chr));
	temp = ft_strnew(1);
	temp[0] = chr;
	if (data->width > 1)
		str = parcer(data, temp, 1);
	else
		str = ft_strdup(temp);
	free(temp);
	i = 0;
	while (str[i] != '\0')
		data->ret_val += write(1, &str[i++], 1);
	free (str);
}

char	*deal_null(char *str, t_check *data)
{
	char	*new;

/*	if (str is int)
		exit(1);*/
	if (str == NULL)
	{
		if ((data->precision >= 6 || data->dot == 0)
			|| (data->dot == 0 && data->width == 0))
			new = ft_strdup("(null)");
		else
			new = ft_strdup("");
	}
	else
		new = ft_strdup(str);
	return (new);
}

void	handle_string(t_check *data, char *str)
{
	char	*temp;
	char	*save;

	save = deal_null(str, data);
	temp = string_precision(data, save, ft_strlen(save));
	free (save);
	if (data->width > (int)ft_strlen(temp))
		save = parcer(data, temp, ft_strlen(temp));
	else
		save = ft_strdup(temp);
	free (temp);
	//save = string_flags(data, save);
	print_str(data, save);
	free (save);
}
