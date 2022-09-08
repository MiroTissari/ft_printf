
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
	if (data->hash == 1 && str[0] != '0')
		save = ft_strjoin_free("0", save, 0, 2);
	if (data->width > (int)ft_strlen(save))
		str = parcer(data, save, ft_strlen(save));
	else
		str = ft_strdup(save);
	free (save);
	print_str(data, str);
	free (str);
}

char	*hash_hex(t_stuff *data, char *str, unsigned long long int num)
{
	int	i;

	i = 0;
	if (data->hash == 1 && data->period == 0 && num > 0)
	{
		while (str[i] == ' ')
			i++;
		if (i >= 2)
		{
			printf("r");
			str[i - 2] = '0';
			str[i - 1] = data->format;
		}
		else if (data->zero == 1 && str[i] == '0' && str[i + 1] == '0')
		{
			printf("t");
			str[i] = '0';
			str[i + 1] = data->format;
		}
		else
		{
			printf("y");
			str[i] = '0';
			str[i + 1] = data->format;
		}
		data->hash = 0;
	}
	return (str);
}

void	handle_hex(t_stuff *data, char *str, unsigned long long int num)
{
	char	*save;

	if (data->period == 1)
		data->zero = 0;
	if (num == 0)
		save = ft_strdup("");
	else
		save = oux_precision(data, str, ft_strlen(str));
	free (str);
	if (data->width > (int)ft_strlen(save))
		str = hex_parcer(data, save, ft_strlen(save));
	else
		str = ft_strdup(save);
	str = hash_hex(data, str, num);
	free (save);
	print_str(data, str);
//	free (str);
}


