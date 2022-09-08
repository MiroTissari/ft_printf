/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:22:34 by mtissari          #+#    #+#             */
/*   Updated: 2022/06/29 20:06:11 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/ft_printf.h"
/*
char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	x;

	x = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	while (x < size)
	{
		str[x] = '\0';
		x++;
	}
	str[size] = '\0';
	return (str);
}

char	*rounding_floats(char *str, int len)	//len needs to be already incremented so that it has whole numbers and '.' in it!
{
	char	*new;
	char	temp[len + 1];
	int		i;

	if (str[len + 1] > '4')
	{
		i = 0;
		while ((str[len + 1] == '9' || str[len + 1] == '.') && str[len])
		{
			if (str[len] == '9' || str[len + 1] == '.')
			{
				temp[i++] = '0';
				if (len == 0)
					temp[i++] = '1';
			}
			else if (str[len] == '.')
				temp[i++] = '.';
			else
				temp[i++] = str[len] + 1;
			len--;
		}
		printf("1st temp: %s\n", temp);
		while (len >= 0 || str[len])
			temp[i++] = str[len--];
		printf("2nd temp: %s\n", temp);
		new = ft_strnew(i + 1);
		len = 0;
		while (i >= 0)
			new[len++] = temp[--i];
		printf("1st new: %s\n", new);
		return (new);
	}
	return (str);
}
*/
int	main(void)
{
	int	i;
	char	*str;
	char	c;
	char	*s;

	s = "1.50000000099999444";
	c = 'X';
	str = "let's go";
	i = 938776;
	//printf("rounding test: %s\n", rounding_floats(s, 9));
	//printf("this is a test for normal\n");
	//printf("the number of characters: %n for normal\n", &i);
	//printf("%d\n", i);
	printf("trying hex conversion in normal: %#10.8x\n", i);
	//printf("write normal: '%s' and '%%' and then character: '%c'\n", str, c);
	ft_printf("this is a test for small\n");
	//small_printf("test");
	ft_printf("write this: '%s' and '%%' and then character: '%c'\n", str, c);
	
	printf("'%%i = %i'\n", i);
	printf("'%%+d = %+d'\n", i);
	printf("this is the tester'%12.7d' yes\n", 90123);
	printf("'%015.5f'\n", 9.99999999999);
	//ft_printf("check 1: %s\n check", "hello");
	//ft_printf("%i", fd);
	printf("'%47.5s'|%n|\n", "moikkamoi", &i);
	printf("|%05c| \n", 'f');
	printf("%05%");		//check how this should behave!!!!!
	printf("\n");
//	ft_printf("%s\n", output);
//	printf("%.0lf %Lf\n", 1.5f, 1.5L);
//	ft_printf("%X %i\n", 255, -12345);
//	ft_printf("%d and %s\n", 345, "check");
//	ft_printf("%++++++0000lllhlhlhlhlhlhlhlhd", 22525526262);
//	ft_printf("\ncheck\n");	
}
