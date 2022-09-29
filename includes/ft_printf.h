/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:23:16 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/29 23:06:13 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

# define HX		"0123456789abcdef"
# define HEX	"0123456789ABCDEF"
# define DEC	"0123456789"
# define OCT	"01234567"

typedef struct s_check
{
	int			ret_val;
	int			index_add;
	int			format;
	char		*temp_width;
	char		*temp_prec;

	int			flag_nb;
	int			hash;
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			dot;

	int			l;
	int			ll;
	int			cap_l;
	int			h;
	int			hh;
	int			negative;
	int			nil;

	int			width;
	int			precision;
}				t_check;

int			ft_printf(const char *str, ...);
void		set_values(t_check *data);
void		format_identifier(char *str, va_list *argp, t_check *data);
int			check_flags(char *str, t_check *data, int i, va_list *argp);
int			false_output(char *str, t_check *data, int i);

int			verify_flags(char *s);
void		set_flags(char flag, t_check *data);
int			set_width_and_precision(char *str, int i, t_check *data);
int			set_modifiers(char *str, int i, t_check *data);
void		length_check(char *str, int i);

void		handle_string(t_check *data, char *str);
void		handle_char(t_check *data, int chr);
void		print_char(t_check *data, int chr);
void		print_str(t_check *data, char *str);
char		*deal_null(char *str, t_check *data);

void		modify_float(t_check *data, va_list *argp);
void		modify_di(t_check *data, va_list *argp);
void		modify_oux(t_check *data, va_list *argp, char format);

/*void		handle_numbers(t_check *data, va_list argp, char format);
char		*modifier_check(t_check *data, va_list argp, char format);
char		*modifier_ll(t_check *data, va_list argp);
char		*modifier_hh(t_check *data, va_list argp);*/

void		handle_int(t_check *data, char *str);
void		handle_uint(t_check *data, char *str);
void		handle_int_zero(t_check *data, char *str);
void		handle_uint_zero(t_check *data, char *str);
char		*int_flag_check(t_check *data, char	*str, int len);

void		handle_hex(t_check *data, char *str, unsigned long long int num);
char		*hash_hex(t_check *data, char *str, unsigned long long int num);
char		*hash_hex_edge(t_check *data, char *str, unsigned long long int nb);
char		*handle_hex_zero(t_check *data);
void		handle_oct(t_check *data, char *str, unsigned long long int num);

void		handle_pointer(t_check *data, va_list *argp);
char		*pointer_flags(t_check *data, char *str);

void		handle_float(t_check *data, long double num);
long double	float_round(t_check *data, int prec, long double num);
char		*float_nan_inf(long double num, t_check *data);
char		*float_flag_check(t_check *data, char *str, int len);

char		*ft_ftoa(long double num, int precision, int neg, t_check *data);
char		*get_decimal(long double dec, int precision);

char		*uitoa_base(unsigned long long int nb, char *base);
char		*ft_itoa_base(long long int nb, char *base);

char		*parcer(t_check *data, char *str, int len);
char		*hex_parcer(t_check *data, char *str, int len);

char		*rounding_floats(char *str, int len);

char		*string_precision(t_check *data, char *str, int len);
char		*double_precision(t_check *data, char *str, int len);
char		*di_precision(t_check *data, char *str, int len);
char		*oux_precision(t_check *data, char *str, int len, int form);

#endif
