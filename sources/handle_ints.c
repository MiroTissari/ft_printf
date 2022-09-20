/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:48:22 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/20 17:32:41 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_uint(t_check *data, char *str, unsigned long long int num)
{
	int		len;
	int		i;
	char	*save;

	if (num == 0)
		data->flag_nb = 1; //deal with 0!!
	save = oux_precision(data, str, ft_strlen(str));
	free (str);
	len = ft_strlen(save);
	if (data->width > len)
		str = parcer(data, save, len);
	else
		str = ft_strdup(save);
	free (save);
	i = 0;
	while (str[i] != '\0')
	{
		print_char(data, str[i++]);
	}
	free (str);
}

void	handle_int_zero(t_check *data, char *str, long long int num)
{
	char	*save;
	int		len;
	int		i;

	if (data->period == 1 && data->precision == 0)
	{
		save = ft_strdup("");
		data->zero = 0;
	}
	else
		save = ft_strdup("0");
	len = ft_strlen(save);
	free (str);
	if (data->width > len)
		str = parcer(data, save, len);
	else
		str = ft_strdup(save);
	free (save);
	if (num < 0)
		str = ft_strjoin_free("-", str, 0, 2);
	i = 0;
	while (str[i] != '\0')
	{
		print_char(data, str[i++]);
	}
	free (str);
}

void	handle_int(t_check *data, char *str, long long int num)
{
	int		len;
	int		i;
	char	*save;

	if (num == 0)
		handle_int_zero(data, str, num);
	save = di_precision(data, str, ft_strlen(str), num);
	free (str);
	len = ft_strlen(save);
	if (data->width > len)
		str = parcer(data, save, len);
	else
		str = ft_strdup(save);
	free (save);
	if (num < 0)
		str = ft_strjoin_free("-", str, 0, 2);
	i = 0;
	while (str[i] != '\0')
	{
		print_char(data, str[i++]);
	}
	free (str);
}
