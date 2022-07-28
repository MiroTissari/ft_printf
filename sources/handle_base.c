

char	*dec_to_octal(void *num, int len, t_stuff *data)
{
	int	i;
	float	remain;
	char	temp[len];

	i = 0;
	remain = (float)*num;
	while (remain >= 1 || i < len)
	{
		temp[i] = remain % 8;
		remain /= 8;
		i++;
	}
	while (len >= 0)
		data->ret_val = write(1, &temp[len--], 1);
}

char	*dec_to_hex(void *num, int len)
{
	int			i;
	float		nb;
	float		remain;
	char		temp[len];
	char		*hex;

	i = 0;
	remain = num;
	while (remain >= 1 || i < len)
	{
		nb = remain % 16;
		if (nb >= 10)
			temp[i] = (nb - 10 + 65);
		else
			temp[i] = (nb + '0');
		i++;
		remain = remain / 16;
	}
	num = 0;
	hex = ft_strnew(i);
	while (--i >= 0)
		*hex++ = temp[i];
	return (hex);
}
