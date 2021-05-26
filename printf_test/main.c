#include "include/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

int	main(void)
{
	int	res1, res2;
	const wchar_t *wstr = L"aaaaaâêḑaaaaa😄";
	const char *str = "Hello World!";

	setlocale(LC_ALL, "");
	res1 = ft_printf("%*lc|\n", -25, L'😄');
	res2 = printf("%*lc|\n", -25, L'😄');
	ft_printf("F: %d, C: %d\n", res1, res2);
	res1 = ft_printf("%22.10ls|\n", wstr);
	res2 = printf("%22.10ls|\n", wstr);
	ft_printf("F: %d, C: %d\n", res1, res2);
	res1 = ft_printf("%22.45ls|\n", wstr);
	res2 = printf("%22.45ls|\n", wstr);
	ft_printf("F: %d, C: %d\n", res1, res2);
	res1 = ft_printf("%22.8ls|\n", wstr);
	res2 = printf("%22.8ls|\n", wstr);
	ft_printf("F: %d, C: %d\n", res1, res2);
	res1 = ft_printf("%-25.45ls|\n", wstr);
	res2 = printf("%-25.45ls|\n", wstr);
	ft_printf("F: %d, C: %d\n", res1, res2);
	res1 = ft_printf("%.ls|\n", wstr);
	res2 = printf("%.ls|\n", wstr);
	ft_printf("F: %d, C: %d\n", res1, res2);
	res1 = ft_printf("%5.ls|\n", wstr);
	res2 = printf("%5.ls|\n", wstr);
	ft_printf("F: %d, C: %d\n", res1, res2);
	res1 = ft_printf("%.0ls|\n", wstr);
	res2 = printf("%.0ls|\n", wstr);
	ft_printf("F: %d, C: %d\n", res1, res2);
	res1 = ft_printf("%.18ls|\n", wstr);
	res2 = printf("%.18ls|\n", wstr);
	ft_printf("F: %d, C: %d\n", res1, res2);
}