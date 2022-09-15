
#include "ft_printf.h"

void	handle_pointer(t_stuff *data, va_list argp)
{
	char	*str;
	char	*save;

	str = ft_itoa_base((unsigned long)va_arg(argp, unsigned long), HeX);
	save = oux_precision(data, str, ft_strlen(str));
	free (str);
	save = ft_strjoin_free("0x", save, 0, 2);
	if (data->width > (int)ft_strlen(save))
		str = hex_parcer(data, save, ft_strlen(save));
	else
		str = ft_strdup(save);
	free (save);
	if (data->space == 1)
		str = ft_strjoin_free(" ", str, 0, 2);
	else if (data->plus == 1)
		str = ft_strjoin_free("+", str, 0, 2);
	print_str(data, str);
	free (str);
}

void	handle_oct(t_stuff *data, char *str, unsigned long long int num)
{
	char	*save;

	if (num == 0)
		data->flag_nb = 1;
	if (data->period == 1)
		data->zero = 0;
	save = oux_precision(data, str, ft_strlen(str));
	free (str);
	if (data->width > (int)ft_strlen(save))
		str = parcer(data, save, ft_strlen(save));
	else
		str = ft_strdup(save);
	if (data->hash == 1 && str[0] != '0' && save[0] != '0')
		str = ft_strjoin_free("0", str, 0, 2);
	free (save);
	print_str(data, str);
	free (str);
}

char	*hash_hex_edge(t_stuff *data, char *str, unsigned long long int num)
{
	if (data->format == 'x' && num > 0)
		str = ft_strjoin("0x", str);
	else if (data->format == 'X' && num > 0)
		str = ft_strjoin("0X", str);
	return (str);
}

char	*hash_hex(t_stuff *data, char *str, unsigned long long int num)
{
	int	i;

	i = 0;
	if (data->hash == 1 && data->period == 0 && num > 0)
	{
		while (str[i] == ' ')
			i++;
		if (i >= 2 && data->minus == 0)
		{
			str[i - 2] = '0';
			str[i - 1] = data->format;
		}
		else if (data->zero == 1 && str[i] == '0' && str[i + 1] == '0')
		{
			str[i] = '0';
			str[i + 1] = data->format;
		}
		else
		{
			str[0] = '0';
			str[1] = data->format;
		}
		data->hash = 0;
	}
	return (str);
}

char	*handle_hex_zero(t_stuff *data)
{
	char	*new;

	if (data->precision < 1)
		new = ft_strdup("");
	else
	{
		new = ft_strnew(data->precision);
		new = ft_memset(new, '0', data->precision);
	}
	data->hash = 0;
	return (new);
}

void	handle_hex(t_stuff *data, char *str, unsigned long long int num)
{
	char	*save;

	if (data->period == 1 || data->minus == 1)
		data->zero = 0;
	if (num == 0)
		data->hash = 0;
	if ((num == 0 && data->period == 1))
		save = handle_hex_zero(data);
	else
		save = oux_precision(data, str, ft_strlen(str));
	free (str);
	if (data->width >= (int)ft_strlen(save))
		str = hex_parcer(data, save, ft_strlen(save));
	else if (data->hash == 1 && ft_strlen(save) < 3)
		str = hash_hex_edge(data, save, num);
	else
		str = ft_strdup(save);
	str = hash_hex(data, str, num);
	free (save);
	print_str(data, str);
//	free (str);
}
