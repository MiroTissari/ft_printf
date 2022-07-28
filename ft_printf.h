/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:23:16 by mtissari          #+#    #+#             */
/*   Updated: 2022/06/29 19:45:06 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//# include "libft.h"

typedef struct s_stuff
{
	int			ret_val;
	int			index_add;

	int			flag_nb;
	int			hash;
	int			plus;
	int			minus;
	int			zero;
	int			space;
}				t_stuff;

//int		ft_printf(const char *str, ...);
void	set_values(t_stuff *data);
void	format_identifier(const char *str, va_list *argp, t_stuff *data);
int		small_printf(const char *str, ...);

#endif
