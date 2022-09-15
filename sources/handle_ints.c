/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:48:22 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/15 17:17:35 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_uint(t_flags *data, char *str, unsigned long long int num)
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

/*
char	*int_flags(t_flags *data, char *str)
{
	if (data->period == 1)
	{

	}
	if (data->minus == 1)
	{

	}
}
*/
void	handle_int(t_flags *data, char *str, long long int num)
{
	int		len;
	int		i;
	char	*save;

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
