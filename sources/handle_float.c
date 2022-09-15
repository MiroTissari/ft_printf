
#include "ft_printf.h"

long double	float_round(t_stuff *data, int prec, long double num)
{
	long double	round;

	round = 0.5;
	if (num < 0)
	{
		round *= -1;
		data->negative = 1;
	}
	while (prec > 0)
	{
		round /= 10.0;
		prec--;
	}
	return (round);
}

long double	float_precision(t_stuff *data, int prec, long double num)
{
	num += float_round(data, prec, num);
	while (num > 1)
		num /= 10;
}

void	handle_float(t_stuff *data, long double num)
{
	long double	flo;

	flo = float_precision(data, data->precision, num);
}
