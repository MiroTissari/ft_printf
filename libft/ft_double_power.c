

long double	double_power(long double num, int prec)
{
	long double	i;
	int			j;

	j = 0;
	i = 1.0;
	while (j < prec)
	{
		i *= num;
		j++;
	}
	return (i);
}
