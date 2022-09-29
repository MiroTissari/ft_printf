
#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	i;
	int	n;
	int	n1;
	char	*str;
	char	c;
	char	*s;
	unsigned long long int h;

	h = 1LLU ;
	s = "1.50000000099999444";
	c = 'X';
	str = "let's go";
	i = -938776;
	//printf("rounding test: %s\n", rounding_floats(s, 9));
	//printf("this is a test for normal\n");
	//printf("the number of characters: %n for normal\n", &i);
	//printf("Hex conversion in normal:\n");
	printf("POINTERS:\n\n");
	printf("thepointer |%p|\n", &str);
	ft_printf("my pointer |%p|\n", &str);
	printf("thepointer |%+15p|\n", &str);
	ft_printf("my pointer |%+15p|\n", &str);
	printf("thepointer |% 15p|\n", &str);
	ft_printf("my pointer |% 15p|\n", &str);
	printf("thepointer |% +019p|\n", &str);
	ft_printf("my pointer |% +019p|\n", &str);
	printf("thepointer |%# .18p|\n", &str);
	ft_printf("my pointer |%# .18p|\n\n", &str);

	printf("HEX:\n\n");
	printf("PRINTF:\nu int: |%#-10.1llX|\n", h);
	ft_printf("MY PRINTF:\nu int: |%#-10.1llX|\n", h);
	printf("PRINTF:\nu int: |%#20.60llX|\n", h);
	ft_printf("MY PRINTF:\nu int: |%#20.60llX|\n", h);
	printf("PRINTF:\nu int: |%#-10.30X|\n", h);
	ft_printf("MY PRINTF:\nu int: |%#-10.30X|\n", h);
	printf("PRINTF:\nu int: |%#10.30llx|\n", h);
	ft_printf("MY PRINTF:\nu int: |%#10.30llx|\n", h);
	printf("PRINTF:\nu int: |%#-5llX|\n", h);
	ft_printf("MY PRINTF:\nu int: |%#-5llX|\n", h);
	printf("PRINTF:\nu int: |%#10llX|\n", h);
	ft_printf("MY PRINTF:\nu int: |%#10llX|\n", h);
	printf("theprintf: |%#020.x|\n", 0);
	ft_printf("my printf: |%#020.x|\n", 0);
	printf("theprintf: |%#20x|\n", i);
	ft_printf("my printf: |%#20x|\n", i);
	printf("theprintf: |% -#20.12X|\n", i);
	ft_printf("my printf: |% -#20.12X|\n", i);
	printf("theprintf: |%+#20.12x|\n", i);
	ft_printf("my printf: |%+#20.12x|\n", i);
	printf("theprintf: |% -#20.12x|\n", i);
	ft_printf("my printf: |%- #20.12x|\n", i);
	printf("PRINTF:\nu int: |%#10llX|\n", h);
	ft_printf("MY PRINTF:\nu int: |%#10llX|\n\n", h);

	printf("OCTAL:\n\n");
	printf("theprintf: |%#20.12o|\n", 0);
	ft_printf("my printf: |%#20.12o|\n", 0);
	printf("theprintf: |% -#20.12o|\n", i);
	ft_printf("my printf: |% -#20.12o|\n", i);
	printf("theprintf: |%+#20.12o|\n", i);
	ft_printf("my printf: |%+#20.12o|\n", i);
	printf("theprintf: |% -#20.12o|\n", i);
	ft_printf("my printf: |%- #20.12o|\n\n", i);

	printf("UNSIGNED INT:\n");
	printf("theprintf: |% +.3llu|\t|% +10.12u|\n", 0ll, 1);
	ft_printf("my printf: |% +.3llu|\t|% +10.12u|\n", 0ll, 1);
	printf("theprintf: |% -#20.12u|\n", 938776);
	ft_printf("my printf: |% -#20.12u|\n", 938776);
	printf("theprintf: |%+#20.12u|\n", 938776);
	ft_printf("my printf: |%+#20.12u|\n", 938776);
	printf("theprintf: |% -#20.12u|\n", 938776);
	ft_printf("my printf: |%- #20.12u|\n\n", 938776);

	printf("INT:\n");
	printf("theprintf: |% +.3lli|\t|% +10.12i|\n", 0ll, 1);
	ft_printf("my printf: |% +.3lli|\t|% +10.12i|\n", 0ll, 1);
	printf("theprintf: |% .3lli|\t|% 10.12i|\n", 0ll, 1);
	ft_printf("my printf: |% .3lli|\t|% 10.12i|\n", 0ll, 1);
	printf("theprintf: |% -#20.12i|\n", 938776);
	ft_printf("my printf: |% -#20.12i|\n", 938776);
	printf("theprintf: |%+#20.12i|\n", 938776);
	ft_printf("my printf: |%+#20.12i|\n", 938776);
	printf("theprintf: |% -#20.12i|\n", 938776);
	ft_printf("my printf: |%- #20.12i|\n\n", 938776);
	printf("theprintf: \t|%10.0i| \t|% +.3li|\t|%.4lli|\n", 4, 57, 12);
	ft_printf("my_printf: \t|%10.0i| \t|% +.3li|\t|%.4lli|\n", 4, 57, 12);
	
	printf("\n\nFLOATS:\n\n");
	printf("theprintf: \t|%0lf| \t|%Lf|\n", 1.5, 1.5l);
	ft_printf("my_printf: \t|%0lf| \t|%Lf|\n", 1.5, 1.5l);
	printf("theprintf: \t|%+.0lf| \t|%lf|\n", 2.5f, 1.5l);
	ft_printf("my_printf: \t|%+.0lf| \t|%lf|\n", 2.5f, 1.5l);
	printf("theprintf: \t|%.1f| \t|%Lf|\n", 3.55, 3.55l);
	ft_printf("my_printf: \t|%.1f| \t|%Lf|\n", 3.55, 3.55l);
	printf("theprintf: \t|%#.0lf| \t|%f|\n", 2.5f, 1.5);
	ft_printf("my_printf: \t|%#.0lf| \t|%f|\n", 2.5f, 1.5);
	printf("theprintf: \t|%#.10lf| \t|%Lf|\n", 1.5555555f, 1.5L);
	ft_printf("my_printf: \t|%#.10lf| \t|%Lf|\n", 1.5555555f, 1.5L);
	printf("theprintf: \t|%10.0lf| \t|%Lf|\n", -1.5f, 1.5L);
	ft_printf("my_printf: \t|%10.0lf| \t|%Lf|\n", -1.5f, 1.5L);

	printf("theprintf: \t|%#10.29lf| \t|%.2Lf|\n", -1.999999999999999, 0.0L);
	ft_printf("my_printf: \t|%#10.29lf| \t|%.2Lf|\n", -1.999999999999999, 0.0L);

	printf("theprintf: \t|%+.3Lf||%+.3Lf||%+.12Lf||\n", 1.5L, 0.0L, 0.0L);
	ft_printf("my_printf: \t|%+.3Lf||%+.3Lf||%+.12Lf||\n", 1.5L, 0.0L, 0.0L);

	printf("theprintf: \t|%10.0f| \t|%+.3Lf|\t|%.4f|\n", 4.5, 0.0L, 0.0/0);
	ft_printf("my_printf: \t|%10.0f| \t|%+.3Lf|\t|%.4f|\n", 4.5, 0.0L, 0.0/0);
	printf("theprintf: \t|%10.0Llf|\n", 1.5);
	ft_printf("my_printf: \t|%10.0Llf|\n\n", 1.5);
	printf("%+0lld", 22525526262);
	ft_printf("%++++++0000lllhlhlhlhlhlhlhlhd", 22525526262);

	printf("theprintf: \t|%%%|\n", 1.5);
	ft_printf("my_printf: \t|%%%|------\n\n", 1.5);

	printf("c with null|%3c|\n", 0);
	ft_printf("c with null|%3c|\n", 0);
	printf("{%3c}\n", 0);
	ft_printf("{%3c}\n", 0);

	printf("{% 03d}\n", 0);
	ft_printf("{% 03d}\n\n", 0);

	printf("%.0p, %.p\n", 0, 0);
	ft_printf("%.0p, %.p\n\n", 0, 0);

	printf("|%.c|\n", 0);
	ft_printf("|%.c|\n\n", 0);

	printf("{%f}{%lf}{%Lf}\n", -1.42, -1.42, -1.42l);
	ft_printf("{%f}{%lf}{%Lf}\n\n", -1.42, -1.42, -1.42l);

	n = printf("|%|\n");
	printf("|%i|\n", n);
	n1 = ft_printf("|%|\n");
	printf("|%i|\n\n", n1);

	printf("|%#.f| |%#.0f| |%#.15Lf|\n", 0.0, 0.0l, 0.0l);
	ft_printf("|%#.f| |%#.0f| |%#.15Lf|\n\n", 0.0, 0.0l, 0.0l);

	printf("|%#x|\n", 2147483647);
	ft_printf("|%#x|\n\n", 2147483647);


	system("\nleaks test");
	printf("\n\n");
}
