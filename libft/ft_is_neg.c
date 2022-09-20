
int	ft_is_neg(double num)
{
	long long int	*binary;
	char			neg;

	binary = (long long int *)&num;
	neg = (char)(*binary >> 63);
	if (neg == 0)
		return (0);
	return (1);
}
