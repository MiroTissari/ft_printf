
#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	i;
	char	*str;
	char	c;
	char	*s;

	s = "1.50000000099999444";
	c = 'X';
	str = "let's go";
	i = -938776;
	//printf("rounding test: %s\n", rounding_floats(s, 9));
	//printf("this is a test for normal\n");
	//printf("the number of characters: %n for normal\n", &i);
	//printf("Hex conversion in normal:\n");
	printf("thepointer |%p|\n", &str);
	ft_printf("my pointer |%p|\n\n", &str);

	printf("HEX:\n");
	printf("theprintf: |%#020.x|\n", 0);
	ft_printf("my printf: |%#020.x|\n", 0);

	printf("theprintf: |%#20x|\n", i);
	ft_printf("my printf: |%#20x|\n", i);

	printf("theprintf: |% -#20.12X|\n", i);
	ft_printf("my printf: |% -#20.12X|\n", i);
	printf("theprintf: |%+#20.12x|\n", i);
	ft_printf("my printf: |%+#20.12x|\n", i);
	printf("theprintf: |% -#20.12x|\n", i);
	ft_printf("my printf: |%- #20.12x|\n\n", i);
	printf("OCTAL:\n");
	printf("theprintf: |%#20.12o|\n", 0);
	ft_printf("my printf: |%#20.12o|\n", 0);
	printf("theprintf: |% -#20.12o|\n", i);
	ft_printf("my printf: |% -#20.12o|\n", i);
	printf("theprintf: |%+#20.12o|\n", i);
	ft_printf("my printf: |%+#20.12o|\n", i);
	printf("theprintf: |% -#20.12o|\n", i);
	ft_printf("my printf: |%- #20.12o|\n\n", i);
	printf("UNSIGNED INT:\n");
	printf("theprintf: |%#20.12u|\n", 0);
	ft_printf("my printf: |%#20.12u|\n", 0);
	printf("theprintf: |% -#20.12u|\n", 938776);
	ft_printf("my printf: |% -#20.12u|\n", 938776);
	printf("theprintf: |%+#20.12u|\n", 938776);
	ft_printf("my printf: |%+#20.12u|\n", 938776);
	printf("theprintf: |% -#20.12u|\n", 938776);
	ft_printf("my printf: |%- #20.12u|\n\n", 938776);
	//printf("write normal: '%s' and '%%' and then character: '%c'\n", str, c);
	ft_printf("\nthis is a test for my printf\n\n");
	ft_printf("my printff: '%%' and then string: '%015s'\n", str);
	printf("the printf: '%%' and then string: '%015s'\n\n", str);
	ft_printf("my printff: '%%' and then string: '% -15.24s'\n", str);
	printf("the printf: '%%' and then string: '% -15.24s'\n\n", str);
	
	ft_printf("my printff '%%i = |%12.15i|'\n", i);
	printf("the printf '%%i = |%#12.15i|'\n", i);
	//printf("'%%+d = |%+d|'\n", i);
	//printf("some text before the |%%12.7d|'%12.7d' yes\n", 90123);
	printf("'%015.5f'\n", 9.99999999999);
	//ft_printf("check 1: %s\n check", "hello");
	//ft_printf("%i", fd);
	//printf("'%47.5s'|%n|\n", "moikkamoi", &i);
	//printf("%%n for the previous: |%i|\n", i);
	//printf("|%05c| \n", 'f');
	//printf("|%+5%|");		//check how this should behave!!!!!
	system("leaks ft_printf.c");
	printf("\n\n\n");
//	ft_printf("%s\n", output);
	printf("f & L \t|%0lf| \t|%Lf|\n", 1.5, 1.5l);
	printf("f & l \t|%.0lf| \t|%lf|\n", 2.5f, 1.5l);
	printf("f & l \t|%#.0lf| \t|%f|\n", 2.5f, 1.5);
	printf("f & L \t|%#.10lf| \t|%Lf|\n", 1.5f, 1.5L);
	printf("f & L \t|%10.0lf| \t|%Lf|\n", 1.5f, 1.5L);
//	ft_printf("%X %i\n", 255, -12345);
//	ft_printf("%d and %s\n", 345, "check");
//	ft_printf("%++++++0000lllhlhlhlhlhlhlhlhd", 22525526262);
//	ft_printf("\ncheck\n");	
}
