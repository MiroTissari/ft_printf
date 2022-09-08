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
# include <stdio.h>
# include "../libft/libft.h"

# define HeX	"0123456789abcdef"
# define HEX	"0123456789ABCDEF"
# define DEC	"0123456789"
# define OCT	"01234567"

typedef struct s_stuff
{
	int			ret_val;
	int			index_add;
	int			format;

	int			flag_nb;
	int			hash;
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			period;

	int			l;
	int			ll;
	int			L;
	int			h;
	int			hh;
	int			negative;

	int			width;
	int			precision;
}				t_stuff;

int		ft_printf(const char *str, ...);
void	set_values(t_stuff *data);
void	format_identifier(const char *str, va_list argp, t_stuff *data);
int		check_flags(char *str, t_stuff *data, int i);


int		verify_flags(char *s, int i);
void	set_flags(char flag, t_stuff *data);
int		set_width_and_precision(char *str, int i, t_stuff *data);
int		set_modifiers(char *str, int i, t_stuff *data);

void	handle_string(t_stuff *data, char *str);
void	handle_char(t_stuff *data, int chr);
void	print_char(t_stuff *data, int chr);
void	print_str(t_stuff *data, char *str);
char	*deal_null(char *str, t_stuff *data);

void	modify_di(t_stuff *data, va_list argp);
void	modify_oux(t_stuff *data, va_list argp, char format);

void	handle_numbers(t_stuff *data, va_list argp, char format);
char	*modifier_check(t_stuff *data, va_list argp, char format);
char	*modifier_ll(t_stuff *data, va_list argp);
char	*modifier_hh(t_stuff *data, va_list argp);

void	handle_int(t_stuff *data, char *str, long long int num);
void	handle_uint(t_stuff *data, char *str, unsigned long long int num);

void	handle_hex(t_stuff *data, char *str, unsigned long long int num);
char	*hash_hex(t_stuff *data, char *str, unsigned long long int num);
void	handle_oct(t_stuff *data, char *str, unsigned long long int num);
void	handle_pointer(t_stuff *data, va_list argp);

char	*uitoa_base(unsigned long long int nb, char *base);
char	*ft_itoa_base(long long int nb, char *base);

char	*parcer(t_stuff *data, char *str, int len);
char	*hex_parcer(t_stuff *data, char *str, int len);

char	*rounding_floats(char *str, int len);

char	*string_precision(t_stuff *data, char *str, int len);
char	*double_precision(t_stuff *data, char *str, int len);
char	*di_precision(t_stuff *data, char *str, int len, long long int num);
char	*oux_precision(t_stuff *data, char *str, int len);



#endif
