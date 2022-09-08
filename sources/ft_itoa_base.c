

#include "ft_printf.h"

static int	ft_unsigned_intlen(unsigned long long int i, int base)
{
	int		j;

	j = 0;
	while (i > ((unsigned long long int)base - 1))
	{
		i = i / base;
		j++;
	}
	return (j + 1);
}

char	*uitoa_base(unsigned long long int nb, char *base)
{
	int		len;
	int		b;
	char	*conversion;

	b = ft_strlen(base);
	len = ft_unsigned_intlen(nb, b);
	conversion = ft_strnew(len);
	if (!conversion)
		return (NULL);
	if (len == 0)
		conversion[0] = base[0];
	while (len > 0)
	{
		conversion[--len] = base[nb % b];
		nb = nb / b;
	}
	return (conversion);
}

static int	ft_intlen(long long int i, int base)
{
	int		j;

	j = 0;
	if (i < 0)
	{
		i = i * (-1);
	}
	while (i > (base - 1))
	{
		i = i / base;
		j++;
	}
	return (j + 1);
}

char	*ft_itoa_base(long long int nb, char *base)
{
	int		len;
	int		b;
	char	*conversion;

	b = ft_strlen(base);
	len = ft_intlen(nb, b);
	conversion = ft_strnew(len);
	if (!conversion)
		return (NULL);
	if (len == 0)
		conversion[0] = base[0];
	if (nb < 0)
		nb = nb * -1;
	while (len > 0)
	{
		conversion[--len] = base[nb % b];
		nb = nb / b;
	}
	return (conversion);
}

/*
	This function converts any number to any base,
	as long as the parameter "base" is the wanted base 
	in writing:
	base 16(hex):	"0123456789abcdef" OR "0123456789ABCDEF"
	base 10(decimal):	"0123456789"
	base 8(octal):	"01234567"
*/
