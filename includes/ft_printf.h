/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:23:16 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/15 17:39:33 by mtissari         ###   ########.fr       */
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

typedef struct s_flags
{
	int			ret_val;
	int			index_add;
	int			format;
	char		*hex;

	int			flag_nb;
	int			hash;
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			period;

	int			l;
	int			ll;
	int			cap_l;
	int			h;
	int			hh;
	int			negative;

	int			width;
	int			precision;
}				t_flags;

int			ft_printf(const char *str, ...);
void		set_values(t_flags *data);
void		format_identifier(const char *str, va_list argp, t_flags *data);
int			check_flags(char *str, t_flags *data, int i);


int			verify_flags(char *s, int i);
void		set_flags(char flag, t_flags *data);
int			set_width_and_precision(char *str, int i, t_flags *data);
int			set_modifiers(char *str, int i, t_flags *data);

void		handle_string(t_flags *data, char *str);
void		handle_char(t_flags *data, int chr);
void		print_char(t_flags *data, int chr);
void		print_str(t_flags *data, char *str);
char		*deal_null(char *str, t_flags *data);

void		modify_float(t_flags *data, va_list argp);
void		modify_di(t_flags *data, va_list argp);
void		modify_oux(t_flags *data, va_list argp, char format);

/*void		handle_numbers(t_flags *data, va_list argp, char format);
char		*modifier_check(t_flags *data, va_list argp, char format);
char		*modifier_ll(t_flags *data, va_list argp);
char		*modifier_hh(t_flags *data, va_list argp);*/

void		handle_int(t_flags *data, char *str, long long int num);
void		handle_uint(t_flags *data, char *str, unsigned long long int num);

void		handle_hex(t_flags *data, char *str, unsigned long long int num);
char		*hash_hex(t_flags *data, char *str, unsigned long long int num);
char		*hash_hex_edge(t_flags *data, char *str, unsigned long long int num);
char		*handle_hex_zero(t_flags *data);
void		handle_oct(t_flags *data, char *str, unsigned long long int num);
void		handle_pointer(t_flags *data, va_list argp);

void		handle_float(t_flags *data, long double num);
long double	float_precision(t_flags *data, int prec, long double num);
long double	float_round(t_flags *data, int prec, long double num);

char		*uitoa_base(unsigned long long int nb, char *base);
char		*ft_itoa_base(long long int nb, char *base);

char		*parcer(t_flags *data, char *str, int len);
char		*hex_parcer(t_flags *data, char *str, int len);

char		*rounding_floats(char *str, int len);

char		*string_precision(t_flags *data, char *str, int len);
char		*double_precision(t_flags *data, char *str, int len);
char		*di_precision(t_flags *data, char *str, int len, long long int num);
char		*oux_precision(t_flags *data, char *str, int len);

#endif
