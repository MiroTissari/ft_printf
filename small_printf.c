/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:55:14 by mtissari          #+#    #+#             */
/*   Updated: 2022/06/29 20:19:02 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	set_values(t_stuff *data)
{
	data->flag_nb = 0;
	data->hash = 0;
	data->minus = 0;
	data->plus = 0;	
	data->space = 0;
	data->zero = 0;
	data->index_add = 0;
}

void	format_identifier(const char *str, va_list *argp, t_stuff *data)
{
	int	i;
	int	x;
	char	*temp;
	char	*tempo;

	i = 1;
	x = 0;
	if (str[i] == '%')
		data->ret_val += write(1, "%", 1);
	else if (str[i] == 'c')
	{
		i = va_arg(*argp, int);
		data->ret_val += write(1, &i, 1);
	}
	else if (str[i] == 's')
	{
		temp = (char *)malloc(sizeof(char) * 100);
		tempo = va_arg(*argp, char *);
		while (tempo[x] != '\0')
		{
			temp[x] = tempo[x];
			x++;
		}
		temp[x] = '\0';
		i = 0;
		while (temp[i] != '\0')
		{
			data->ret_val += write(1, &temp[i], 1);
			i++;
		}
		free (temp);
	}
	else
		return ;
	data->index_add++;
}

int	small_printf(const char *str, ...)
{
	t_stuff	data;
	va_list	argp;
	int		i;

	va_start(argp, str);
	data.ret_val = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			set_values(&data);
			format_identifier(&str[i], &argp, &data);
			i += data.index_add;
		}
		else
			data.ret_val += write(1, &str[i], 1);
		i++;
	}
	va_end(argp);
	printf ("%i\n", data.ret_val);
	return (data.ret_val);
}

/*
gcc -Wall -Wextra -Werror small_printf.c main.c ft_printf.h -o small
*/
