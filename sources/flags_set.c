
#include "ft_printf.h"

int	set_modifiers(char *str, int i, t_stuff *data)
{
	if (str[i] == 'l' && data->l == 0 && data->ll == 0)
	{
		if (str[i + 1] == 'l' && data->l == 1)
		{
			data->ll = 1;
			return (1);
		}
		data->l = 1;
	}
	else if (str[i] == 'h' && data->h == 0 && data->hh == 0)
	{
		if (str[i + 1] == 'h' && data->h == 1)
		{
			data->hh = 1;
			return (1);
		}
		data->h = 1;
	}
	else if (str[i] == 'L' && data->L == 0)
		data->L = 1;
	return (0);
}

int	set_width_and_precision(char *str, int i, t_stuff *data)
{
	int		len;
	char	temp[11];

	len = 0;
	while (str[i + len] >= 48 && str[i + len] <= 57)
		len++;
	/*if (len > 10)
		error_handling("directive output of 2147483648 bytes exceeds ‘INT_MAX’")*/
	if (data->width == 0 && data->period == 0)
	{
		len = 0;
		while (str[i] >= 48 && str[i] <= 57)
			temp[len++] = str[i++];
		data->width = ft_atoi(temp);
	}
	else if (data->precision == 0 && data->period == 1)
	{
		len = 0;
		while (str[i] >= 48 && str[i] <= 57)
			temp[len++] = str[i++];
		temp[len] = '\0';
		data->precision = ft_atoi(temp);
	}
	return (i);
}

void	set_flags(char flag, t_stuff *data)
{
	if (flag == ' ' && data->plus == 0)
		data->space = 1;
	else if (flag == '0' && data->minus == 0)
		data->zero = 1;
	else if (flag == '-')
	{
		data->minus = 1;
		data->zero = 0;
	}
	else if (flag == '+')
	{
		data->plus = 1;
		data->space = 0;
	}
	else if (flag == '#')
		data->hash = 1;
}

int	verify_flags(char *s, int i)
{
	int	num;

	num = 0;
	while (s[num] != '%' && s[num] != 'a' && s[num] != 'A' && s[num] != 'g'
		&& s[num] != 'G' && s[num] != 'e' && s[num] != 'E' && s[num] != 'f'
		&& s[num] != 'F' && s[num] != 'n' && s[num] != 'p' && s[num] != 'c'
		&& s[num] != 's' && s[num] != 'd' && s[num] != 'i' && s[num] != 'o'
		&& s[num] != 'u' && s[num] != 'x' && s[num] != 'X')
	{
		if (s[num] != ' ' && s[num] != '0' && s[num] != '#' && s[num] != '-'
			&& s[num] != '+' && s[num] != '.' && s[num] != '*' && s[num] != 'l'
			&& s[num] != 'h' && s[num] != 'L' && s[num] != 'j' && s[num] != 't'
			&& s[num] != 'z')
		{
			if (s[num] <= 48 && s[num] >= 57)
				write(1, "error", 6);
		}
		num++;
	}
	return (i + num);
}
