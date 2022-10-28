/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronjones <aaronjones@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:37:55 by aaronjones        #+#    #+#             */
/*   Updated: 2022/08/18 22:09:23 by aaronjones       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
	char c;
	char *str;
	char *str1;
	char *str2;
	char *str_null;
	char *str3;
	int	num;
	long long int i;
	int x;
	char a;
	unsigned long long int h;
	char	b;
	long long int	m;
	float p;
	int f;
	int g;
	
	g = 0;
	f = 0;
	p = 54;
	b = 'x';
	h = 18446744073709551615LLU ;
	a = 34;
	x = 1;
	i = 9223372036854775807;
	m = -9223372036854775807;
	num = 12345;
	c = 'A';
	str = "sTrInG 1";
	str1 = "StRiNg 2";
	str2 = "54321";
	str3 = "0123456789";
	str_null = NULL;

	ft_printf("MY PRINTF:\nString 1: %s\nString 2: %s\nCharacter: %c\n", str, str1, c);
	printf("\nNORMAL PRINTF:\nString 1: %s\nString 2: %s\nCharacter: %c\n", str, str1, c);
	ft_printf("MY PRINTF:\nString 1 & String 2 and Character: %s%s%c\n", str, str1, c);
	printf("\nNORMAL PRINTF:\nString 1 & String 2 and Character: %s%s%c\n", str, str1, c);
	ft_printf("MY PRINTF:\nString 1 between percents %-2%%s%%\n", str);
	printf("\nNORMAL PRINTF:\nString 1 between percents %-2%%s%%\n", str);
	printf("\nMY PRINTF:\n");
	ft_printf("%%%%%%%%");
	printf("\n");
	printf("NORMAL PRINTF:\n%%%%%%%%");
	printf("\n");
	printf("\n");
	ft_printf("MY PRINTF:\n%-08%|%-5%|%30%|%-05%|%05.9%|%05%|%0-8.8%:");
	printf("\n");
	printf("NORMAL PRINTF:\n%-08%|%-5%|%30%|%-05%|%05.9%|%05%|%0-8.8%:\n");
	printf("\n\n");
	ft_printf("MY PRINTF:\nNumbered string: |%s|\n", str3);
	printf("PRINTF:\nNumbered string: |%s|\n", str3);
	ft_printf("MY PRINTF:\nNumbered string: |%-15s|\n", str3);
	printf("PRINTF:\nNumbered string: |%-15s|\n", str3);
	ft_printf("MY PRINTF:\nNumbered string: |%15s|\n", str3);
	printf("PRINTF:\nNumbered string: |%15s|\n", str3);
	ft_printf("MY PRINTF:\nNumbered string: |%3s|\n", str3);
	printf("PRINTF:\nNumbered string: |%3s|\n", str3);
	ft_printf("MY PRINTF:\nNumbered string: |%-3s|\n", str3);
	printf("PRINTF:\nNumbered string: |%-3s|\n", str3);
	printf("\nNull strings:\n");
	ft_printf("MY PRINTF:\nNULL string: |%s|\n", str_null);
	printf("PRINTF:\nNULL string: |%s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%-10s|\n", str_null);
	printf("PRINTF:\nNULL string: |%-10s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%10s|\n", str_null);
	printf("PRINTF:\nNULL string: |%10s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%3s|\n", str_null);
	printf("PRINTF:\nNULL string: |%3s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%-3s|\n", str_null);
	printf("PRINTF:\nNULL string: |%-3s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%.s|\n", str_null);
	printf("PRINTF:\nNULL string: |%.s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%-10.3s|\n", str_null);
	printf("PRINTF:\nNULL string: |%-10.3s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%10.3s|\n", str_null);
	printf("PRINTF:\nNULL string: |%10.3s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%-10.5s|\n", str_null);
	printf("PRINTF:\nNULL string: |%-10.5s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%10.5s|\n", str_null);
	printf("PRINTF:\nNULL string: |%10.5s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%3.3s|\n", str_null);
	printf("PRINTF:\nNULL string: |%3.3s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%-3.3s|\n", str_null);
	printf("PRINTF:\nNULL string: |%-3.3s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%-3.5s|\n", str_null);
	printf("PRINTF:\nNULL string: |%-3.5s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%3.5s|\n", str_null);
	printf("PRINTF:\nNULL string: |%3.5s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%-3.15s|\n", str_null);
	printf("PRINTF:\nNULL string: |%-3.15s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%3.15s|\n", str_null);
	printf("PRINTF:\nNULL string: |%3.15s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%-10.15s|\n", str_null);
	printf("PRINTF:\nNULL string: |%-10.15s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%10.15s|\n", str_null);
	printf("PRINTF:\nNULL string: |%10.15s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%10.s|\n", str_null);
	printf("PRINTF:\nNULL string: |%10.s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%-10.s|\n", str_null);
	printf("PRINTF:\nNULL string: |%-10.s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%10.0s|\n", str_null);
	printf("PRINTF:\nNULL string: |%10.0s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%-10.0s|\n", str_null);
	printf("PRINTF:\nNULL string: |%-10.0s|\n", str_null);
	ft_printf("MY PRINTF:\nNULL string: |%-15s%c%-7.15s%5%|%5c%-5c|\n", str_null, c, str3, c, c);
	printf("      PRINTF:\nNULL string: |%-15s%c%-7.15s%5%|%5c%-5c|\n", str_null, c, str3, c, c);
	ft_printf("MY PRINTF:\nNULL string: |%-15s%c%-7.15s%5%|%5c%-5c|\n", str3, c, str_null, c, c);
	printf("      PRINTF:\nNULL string: |%-15s%c%-7.15s%5%|%5c%-5c|\n", str3, c, str_null, c, c);
	ft_printf("MY PRINTF:\nNULL string: |%-10.3s%-7.15s%5%|%5c%-5c|\n", str_null, str3, c, c);
	printf("      PRINTF:\nNULL string: |%-10.3s%-7.15s%5%|%5c%-5c|\n", str_null, str3, c, c);
	ft_printf("MY PRINTF:\nNULL string: |%-10s%c%-15.15s%5%|%5c%-5c|\n", str_null, c, str3, c, c);
	printf("      PRINTF:\nNULL string: |%-10s%c%-15.15s%5%|%5c%-5c|\n", str_null, c, str3, c, c);
	ft_printf("MY PRINTF:\nNULL string: |%10s%hc%15.15s%5%|%5c%-5c|\n", str_null, c, str3, c, c);
	printf("      PRINTF:\nNULL string: |%10s%c%15.15s%5%|%5c%-5c|\n", str_null, c, str3, c, c);
	ft_printf("MY PRINTF:\nNULL string: |%010s|%c|%s|%5%|%5c|%-5c|\n", str_null, c, str3, c, c);
	printf("      PRINTF:\nNULL string: |%010s|%c|%s|%5%|%5c|%-5c|\n", str_null, c, str3, c, c);
	printf("\nCharacters:\n");
	ft_printf("MY PRINTF:\nCharacter: |%.5c|\n", c);
	printf("PRINTF:\nCharacter: |%.5c|\n", c);
	ft_printf("MY PRINTF:\nCharacter: |%0.5c|\n", c);
	printf("PRINTF:\nCharacter: |%0.5c|\n", c);
	ft_printf("MY PRINTF:\nCharacter: |%05c|\n", c);
	printf("PRINTF:\nCharacter: |%05c|\n", c);
	ft_printf("MY PRINTF:\nCharacter: |%-c|\n", c);
	printf("PRINTF:\nCharacter: |%-c|\n", c);
	ft_printf("MY PRINTF:\nCharacter: |%5c|\n", c);
	printf("PRINTF:\nCharacter: |%5c|\n", c);
	ft_printf("MY PRINTF:\nCharacter: |%-5c|\n", c);
	printf("PRINTF:\nCharacter: |%-5c|\n", c);
	ft_printf("MY PRINTF:\nCharacter: |%15c|\n", c);
	printf("PRINTF:\nCharacter: |%15c|\n", c);
	ft_printf("MY PRINTF:\nCharacter: |%05c|\n", a);
	printf("PRINTF:\nCharacter: |%05c|\n", a);
	ft_printf("MY PRINTF:\nCharacter: |%-c|\n", a);
	printf("PRINTF:\nCharacter: |%-c|\n", a);
	ft_printf("MY PRINTF:\nCharacter: |%5c|\n", a);
	printf("PRINTF:\nCharacter: |%5c|\n", a);
	ft_printf("MY PRINTF:\nCharacter: |%-5c|\n", a);
	printf("PRINTF:\nCharacter: |%-5c|\n", a);
	ft_printf("MY PRINTF:\nCharacter: |%5c|\n", a);
	printf("PRINTF:\nCharacter: |%5c|\n", a);
	printf("\npointers\n");
	ft_printf("MY PRINTF:\npointers: |%p|\n", &a);
	printf("PRINTF:\npointers: |%p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%20p|\n", &a);
	printf("PRINTF:\npointers: |%20p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%20.30p|\n", &a);
	printf("PRINTF:\npointers: |%20.30p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%-25p|\n", &a);
	printf("PRINTF:\npointers: |%-25p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%-25.5p|\n", &a);
	printf("PRINTF:\npointers: |%-25.5p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%.p|\n", &a);
	printf("PRINTF:\npointers: |%.p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%-30p|\n", &a);
	printf("PRINTF:\npointers: |%-30p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%- 30p|\n", &a);
	printf("PRINTF:\npointers: |%- 30p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%30.16p|\n", &a);
	printf("PRINTF:\npointers: |%30.16p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%016.20p|\n", &a);
	printf("PRINTF:\npointers: |%016.20p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%-016.20p|\n", &a);
	printf("PRINTF:\npointers: |%-016.20p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%030p|\n", &a);
	printf("PRINTF:\npointers: |%030p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%05p|\n", &a);
	printf("PRINTF:\npointers: |%05p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%-030p|\n", &a);
	printf("PRINTF:\npointers: |%-030p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%016p|\n", &a);
	printf("PRINTF:\npointers: |%016p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%-20.p|\n", &a);
	printf("PRINTF:\npointers: |%-20.p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%020p|\n", &a);
	printf("PRINTF:\npointers: |%020p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%-020p|\n", &a);
	printf("PRINTF:\npointers: |%-020p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%18.13p|\n", &a);
	printf("PRINTF:\npointers: |%18.13p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |%18.12p|\n", &a);
	printf("PRINTF:\npointers: |%18.12p|\n", &a);
	ft_printf("MY PRINTF:\npointers: |% 0.13p|\n", &a);
	printf("PRINTF:\npointers: |% 0.13p|\n", &a);

	f = ft_printf("PRINTF:\npointers: |%+0.13p|\n", &a);
	g = printf("PRINTF:\npointers: |%+0.13p|\n", &a);

	printf("\n\n\n|%i|\t\t|%i|\n", f, g);
	
	system("leaks a.out");
	return 0;
}
