/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:42:11 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/29 19:29:31 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
char	*pointer_flags(t_check *data, char *str)
{
	if (data->plus == 1)
	{
		if ((str[0] == '0' || str[0] == ' ') && str[1] != 'x')
			str[0] = '+';
		else
			str = ft_strjoin_free("+", str, 0, 2);
		data->plus = 0;
	}
	else if (data->space == 1 && str[0] != ' ')
	{
		if (str[0] == '0' && str[1] != 'x')
			str[0] = ' ';
		else
			str = ft_strjoin_free(" ", str, 0, 2);
		data->space = 0;
	}
	return (str);
}
	This function is only for linux compiling,
	because on linux, the pointers follow '+' and ' ' -flags.
*/

void	handle_pointer(t_check *data, va_list *argp)
{
	char			*str;
	char			*save;
	unsigned long	nb;

	nb = (unsigned long)va_arg(*argp, unsigned long);
	if (data->precision == 0 && data->dot == 1 && nb == 0)
		str = ft_strdup("");
	else
		str = uitoa_base(nb, HX);
	if (data->dot == 1)
		data->zero = 0;
	save = oux_precision(data, str, ft_strlen(str), data->format);
	free (str);
	if (data->zero == 0 || data->width <= (int)ft_strlen(save))
		save = ft_strjoin_free("0x", save, 0, 2);
	if (data->width > (int)ft_strlen(save))
		str = hex_parcer(data, save, ft_strlen(save));
	else
		str = ft_strdup(save);
	free (save);
	//if (data->zero == 1 && (data->space == 1 || data->plus == 1))
	//	str[2] = 'x';
	if (data->zero == 1 && str[1] == '0')
		str[1] = 'x';
//	if (data->space == 1 || data->plus == 1)
//		str = pointer_flags(data, str);
	print_str(data, str);
	free (str);
}
