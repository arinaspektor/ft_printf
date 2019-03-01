/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:29:40 by aspektor          #+#    #+#             */
/*   Updated: 2018/12/05 19:29:40 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <fcntl.h>
#include <locale.h>

int		main(void)
{
	printf("\n\x1b[35m-------- DIFFERENT TESTS --------\x1b[0m\n\n");

	int d = printf("");
	printf("%d\n", d);
	int d1 = ft_printf("");
	printf("%d\n\n", d1);

	d = printf("string %");
	printf("%d\n", d);
	d1 = ft_printf("string %");
	printf("%d\n\n", d1);


	d = printf("   \x1b[32mprintf:\x1b[0m %10");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %10");
	printf("%d\n\n", d1);

	d = printf("% ");
	printf("%d\n", d);
	d1 = ft_printf("% ");
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m simple string\t");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m simple string\t");
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %10Q\t");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %10Q\t");
	printf("%d\n", d1);
	printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %10L\t");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %10L\t");
	printf("%d\n", d1);
	printf("\n");


	d = printf("   \x1b[32mprintf:\x1b[0m %10R\t", 256);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %10R\t", 256);
	ft_printf("%d\n\n", d1);

	d = printf("%s", "   \x1b[32mprintf:\x1b[0m inserted string\t");
	printf("%d\n", d);
	d1 = ft_printf("%s", "\x1b[33mft_printf:\x1b[0m inserted string\t");
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m simple + %s\t", "inserted string");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m simple + %s\t", "inserted string");
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m NULL-pointer %s\t", NULL);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m NULL-pointer %s\t", NULL);
	printf("%d\n\n", d1);

	printf("   \x1b[32mprintf:\x1b[0m just char\t");
	d = printf("%c", 'a');
	printf("\t");
	printf("%d\n", d);
	ft_printf("\x1b[33mft_printf:\x1b[0m just char\t");
	d1 = ft_printf("%c", 'a');
	ft_printf("\t");
	printf("%d\n", d1);
	ft_printf("\n");

	printf("   \x1b[32mprintf:\x1b[0m integer\t");
	d = printf("%d", -546777777);
	printf("\t");
	printf("%d\n", d);
	ft_printf("\x1b[33mft_printf:\x1b[0m integer\t");
	d1 = ft_printf("%d", -546777777);
	printf("\t");
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m string with symbol %%\t");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m string with symbol %%\t");
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m mixed types: char - %c, int - %d, str - %s\t", 'B', 230, "string");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m mixed types: char - %c, int - %d, str - %s\t", 'B', 230, "string");
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %s%s%s%s%s\t", "this", "is", "a", "multi", "string");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %s%s%s%s%s\t", "this", "is", "a", "multi", "string");
	printf("%d\n", d1);
	ft_printf("\n");


	d = printf("   \x1b[32mprintf:\x1b[0m string with space % s\t", "str");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m string with space % s\t", "str");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m integer i - %i\t", 2147483647);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m integer i - %i\t", 2147483647);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m i_hex - %i, i_binary - %i, i_octal - %i\t", 0XFF, 0b1000, 077);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m i_hex - %i, i_binary - %i, i_octal - %i\t", 0XFF, 0b1000, 077);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m d_hex - %d, d_binary - %d, d_octal - %d\t", 0XFAB, 0b1001, 0177);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m d_hex - %d, d_binary - %d, d_octal - %d\t", 0XFAB, 0b1001, 0177);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m unsigned int - %u\t", -255);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m unsigned int - %u\t", -255);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m unsigned int with plus - %+u\t", 4294967295);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m unsigned int with plus - %+u\t", 4294967295);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m sign '+' - %+d\t", 100);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m sign '+' - %+d\t", 100);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m sign '+' neg - %+d\t", -555555);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m sign '+' neg - %+d\t", -555555);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m big U long - %U\t",  4294967296);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m big U long - %U\t", 4294967296);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m small u long - %u\t",  4294967296);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m small u long - %u\t", 4294967296);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m big U -1 - %U\t",  -1);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m big U -1 - %U\t", -1);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m small u -1 - %u\t",  -1);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m small u -1 - %u\t", -1);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m hex_x - %x\t", 'j');
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m hex_x - %x\t", 'j');
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m hex_X - %X\t", 'J');
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m hex_X - %X\t", 'J');
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m neg hex_x - %x, neg hex_X - %X\t", -42, -9999);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m neg hex_x - %x, neg hex_X - %X\t", -42, -9999);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m octal - %o\t", 1000);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m octal - %o\t", 1000);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m small u with -l - %lu\t",  4294967295);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m small u with -l - %lu\t", 4294967295);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m big U with -l - %lU\t",  4294967295);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m big U with -l - %lU\t", 4294967295);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m d with -l - %ld\t",  4294967296);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m d with -l - %ld\t", 4294967296);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m small x with -l - %lx\t",  4294967296);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m small x with -l - %lx\t", 4294967296);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m big X with -l - %lX\t",  4294967296);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m big X with -l - %lX\t", 4294967296);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m spaces between %   %\t");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m spaces between %   %\t");
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m d with + and -l - %+ld\t",  4294967296);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m d with + and -l - %+ld\t", 4294967296);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m max ull int - %llu\t", 18446744073709551615);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m max ull int - %llu\t", 18446744073709551615);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m min ll int - %lld\t", -9223372036854775808);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m min ll int - %lld\t", -9223372036854775808);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m +d 0 - %+d\t", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m +d 0 - %+d\t", 0);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m space after flag - %+ d\t", 42);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m space after flag - %+ d\t", 42);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m short int i - %hi\t", 55655555);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m short int i - %hi\t", 55655555);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m unsigned short int - %hu\t", -1);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m unsigned short int - %hu\t", -1);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m integer i - % d\t", -1);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m integer i - % d\t", -1);
	printf("%i\n", d1);
	ft_printf("\n");

	printf("   \x1b[32mprintf:\x1b[0m just %%\t");
	d = printf("%");
	printf("\t");
	printf("%d\n", d);
	ft_printf("\x1b[33mft_printf:\x1b[0m just %%\t");
	d1 = ft_printf("%");
	ft_printf("\t");
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m wrong spec - % Z\t");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m wrong spec - % Z\t");
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m hh spec - %hhd\t", 666);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m hh spec - %hhd\t", 666);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m j spec - %jx\t", 4294967296);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m j spec - %jx\t", 4294967296);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m space before h - % h\t");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m space before h - % h\t");
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m integer i - % d\t", 42);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m integer i - % d\t", 42);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m integer i - % +++d\t", 1);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m integer i - % +++d\t", 1);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m integer d space after plus - %+++ d\t", 1);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m integer d space after plus - %+++ d\t", 1);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m integer d space and plus - % +d\t", 1);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m integer d space and plus - % +d\t", 1);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m integer d width and plus - %5+d\t", 10);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m integer d width and plus - %5+d\t", 10);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m neg integer d width and plus - %5+d\t", -10);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m neg integer d width and plus - %5+d\t", -10);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m integer d zero space - %0 d\t", 10);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m integer d zero space - %0 d\t", 10);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m neg integer d width and plus - %-0+5d\t", -42);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m neg integer d width and plus - %-0+5d\t", -42);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m 4to-to - %-05%\t");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m 4to-to - %-05%\t");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %-010s is a string\t", "this");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %-010s is a string\t", "this");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m unnecessary argument %O\t", 42);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m unnecessary argument %O\t", 42);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m unnecessary argument %x\t", 42);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m unnecessary argument %x\t", 42);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m char left aligned %-6s\t", "hello");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m char left aligned %-6s\t", "hello");
	printf("%d\n", d1);
	printf("\n");


	d = printf("   \x1b[32mprintf:\x1b[0m sign '+' char - %+c\t", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m sign '+' char - %+c\t", 0);
	ft_printf("%d\n", d1);
	ft_printf("\n");


	d = printf("   \x1b[32mprintf:\x1b[0m %cmm\t", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %cmm\t", 0);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m str with zeros %09s\t", "hello");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m str with zeros %09s\t", "hello");
	printf("%d\n", d1);
	ft_printf("\n");


	d = printf("   \x1b[32mprintf:\x1b[0m str with zeros %09s\t", "hello");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m str with zeros %09s\t", "hello");
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m char %-*c\t", 22, 'b');
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m char %-*c\t", 22, 'b');
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m char %0*c\t", 6, 'f');
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m char %0*c\t", 6, 'f');
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m char %-0*c\t", 10, 'm');
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m char %-0*c\t", 10, 'm');
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m format octal %#o\t", 10);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m format octal %#o\t", 10);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m octal zero %#o\t", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m octal zero %#o\t", 0);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m big O LONG_MAX %#O\t", LONG_MAX);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m big O LONG_MAX %#O\t", LONG_MAX);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m format ll hex %#llx\t", 9223372036854775807);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m format ll hex %#llx\t", 9223372036854775807);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m format HEX %#X\t", 555);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m format HEX %#X\t", 555);
	printf("%d\n", d1);
	ft_printf("\n");

	int *ptr;
	int x = 10;
	ptr = &x;

	d = printf("   \x1b[32mprintf:\x1b[0m addres %p\t", ptr);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m addres %p\t", ptr);
	printf("%d\n", d1);
	ft_printf("\n");

	char *t = "test_simple_mix";
	d = printf("   \x1b[32mprintf:\x1b[0m s: %s, p: %p, d:%d\t", "a string", &t, 42);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m s: %s, p: %p, d:%d\t", "a string", &t, 42);
	printf("%d\n", d1);
	ft_printf("\n");

	//HH после 127 превращается в long
	d = printf("   \x1b[32mprintf:\x1b[0m hhld %hhld\t", 128);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m hhld %hhld\t", 128);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m lhhd %lhhd\t", 128);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m lhhd %lhhd\t", 128);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m lhhd %lhhd\t",  9223372036854775807);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m lhhd %lhhd\t",  9223372036854775807);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m hhld %hhld\t",9223372036854775807);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m hhld %hhld\t",9223372036854775807);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m hhzd %hhzd\t",9223372036854775807);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m hhzd %hhzd\t",9223372036854775807);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m llzd %llzd\t",9223372036854775807);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m llzd %llzd\t",9223372036854775807);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m hhlc %hhlc\t", 54);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m hhlc %hhlc\t", 54);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m ll#x %ll#x\t", 9223372036854775807);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m ll#x %ll#x\t", 9223372036854775807);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m zero octal with format %#o\t", 0);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m zero octal with format %#o\t", 0);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m zero hex with format %#x\t", 0);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m zero hex with format %#x\t", 0);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m neg hex with format %#x\t", -255);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m neg hex with format %#x\t", -255);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m neg octal with format %#o\t", -255);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m neg octal with format %#o\t", -255);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m str with precision %.3s\t", "hello");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m str with precision %.3s\t", "hello");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m NULL with precision %.3s\t", NULL);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m NULL with precision %.3s\t",  NULL);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m str with precision %.3s\t", "hello");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m str with precision %.3s\t", "hello");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m str with lalign %-15s\t", "hello");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m str with lalign %-15s\t", "hello");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m char with lalign %-15c\t", 'A');
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m char with lalign %-15c\t", 'A');
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m str with ralign %15s\t", "hello");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m str with ralign %15s\t", "hello");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m str with zero padding %015s\t", "hello");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m str with zero padding %015s\t", "hello");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m char non argument %c\t");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m char non argument %c\t");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m #08x %#08x\t", 42);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m #08x %#08x\t", 42);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m integer d width and plus - %0+5d\t", 42);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m integer d width and plus - %0+5d\t", 42);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m octal zero %+o\t", 5);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m octal zero %+o\t", 5);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m octal zero % o\t", 5);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m octal zero % o\t", 5);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m octal zero %10o\t", 5);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m octal zero %10o\t", 5);
	printf("%d\n", d1);
	ft_printf("\n");


	d = printf("   \x1b[32mprintf:\x1b[0m octal zero width %010o\t", 5);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m octal zero width %010o\t", 5);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m octal format width %#10o\t", 5);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m octal format width %#10o\t", 5);
	printf("%d\n", d1);
	ft_printf("\n");


	d = printf("   \x1b[32mprintf:\x1b[0m octal precision %.5o\t", 5);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m octal precision %.5o\t", 5);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m octal precision int %.5d\t", 1000000000);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m octal precision int %.5d\t", 1000000000);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m precision 10 int %.10d\t", 10);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m precision 10 int %.10d\t", 10);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m precision 0 int %.0d\t", 1000);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m precision 0 int %.0d\t", 1000);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m precision width int %10.3d\t", 1);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m precision width int %10.3d\t", 1);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m octal precision zero %07.5o\t", 5);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m octal precision zero %07.5o\t", 5);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m octal zero %10*05o\t", 10, 5);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m octal zero %10*05o\t", 10,  5);
	printf("%d\n", d1);
	ft_printf("\n");

	printf("\n\x1b[35m-------- FLOATS --------\x1b[0m\n\n");

	d = printf("   \x1b[32mprintf:\x1b[0m just float f %f\t", 0.5);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m just float f %f\t", 0.5);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m just float F %F\t", 0.3);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m just float F %F\t", 0.3);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m just float f 0 %f\t", 0.0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m just float f 0 %f\t", 0.0);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m FLOAT with precision 3 %.3F\t", 6.00004);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m FLOAT with precision 3 %.3F\t", 6.0004);
	printf("%d\n", d1);
	ft_printf("\n");


	d = printf("   \x1b[32mprintf:\x1b[0m float with precision 0 %.0f\t", 5.4);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with precision 0 %.0f\t", 5.4);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m format float with precision 0 %#.0f\t", 5.4);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m format float with precision 0 %#.0f\t", 5.4);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with precision 0 %.0f\t", 0.9);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with precision 0 %.0f\t", 0.9);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with precision 0 %.0f\t", 5.9);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with precision 0 %.0f\t", 5.9);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with precision 0 %.0f\t", 5.5);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with precision 0 %.0f\t", 5.5);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with precision 1 %.1f\t", 7.7);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with precision 1 %.1f\t", 7.7);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with precision 1 %.1f\t", 7.76);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with precision 1 %.1f\t", 7.76);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with precision 2 %.2f\t", 7.766);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with precision 2 %.2f\t", 7.766);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with precision without value %.f\t", 3.4);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with precision without value %.f\t", 3.4);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with precision without value and format %#.f\t", 3.4);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with precision without value and format %#.f\t", 3.4);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m neg float with precision 10 %.10f\t", -0.7);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m neg float with precision 10 %.10f\t", -0.7);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m L flag float %Lf\t", 5.1L);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m L flag float %Lf\t", 5.1L);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m l flag float %Lf\t", 5.56879804);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m l flag float %Lf\t", 5.56879804);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with zero pad 3 %03f\t", 1.4);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with zero pad 3 %03f\t", 1.4);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with zero pad 5 & precision 0 %05.0f\t", 3.05);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with zero pad 5 & precision 0 %05.0f\t", 3.05);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with width 20 & precision 5 %20.5f\t", 2228.22);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with width 20 & precision 5 %20.5f\t", 2228.22);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with width 20 & precision 5 %20.5f\t", 7.543);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with width 20 & precision 5 %20.5f\t", 7.543);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m float with zero pad 5 & precision 0 %05.0f\t", -3.9);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m float with zero pad 5 & precision 0 %05.0f\t", -3.9);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %.*f f * 25\t", 25, 0.22222222222299999999999999999999);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.*f f * 25\t", 25, 0.22222222222299999999999999999999);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %.*Lf Lf *19\t", 19, 0.333333333333333333L);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.*Lf Lf *19\t", 19, 0.333333333333333333L);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %.*f f * 0\t", 0, 0.22222);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.*f f * 0\t", 0, 0.22222);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %.Lf Lf .\t", 20, 0.333333333333333333L);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.Lf Lf .\t", 20, 0.333333333333333333L);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	printf("{%d}\n", printf("\033[1;32mTest 2 => \033[0m|%f||%F|", -1.42, -1.42));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 2 => \033[0m|%f||%F|", -1.42, -1.42));
	ft_printf("\n");

	printf("{%d}\n", printf("\033[1;32mTest 13 => \033[0m|%025f||%025F|", 42424242.4242424242424242, 424242424242.424242424242));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 13 => \033[0m|%025f||%025F|", 42424242.4242424242424242, 424242424242.424242424242));
	ft_printf("\n");

	printf("{%d}\n", printf("\033[1;32mTest 3 => \033[0m|%f||%F|", 1444565444646.6465424242242, 1444565444646.6465424242242));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 3 => \033[0m|%f||%F|", 1444565444646.6465424242242, 1444565444646.6465424242242));
	ft_printf("\n");

	printf("{%d}\n", printf("\033[1;32mTest 4 => \033[0m|%f||%F|", 	-1444565444646.6465424242242454654, -1444565444646.6465424242242454654));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 4 => \033[0m|%f||%F|", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654));
	ft_printf("\n");

	printf("{%d}\n", printf("\033[1;32mTest 15 => \033[0m|%0.10f||%0.10F||%0.10LF|", 42424242.4242424242424242, 424242424242.424242424242, 424242424242.424242424242L));
	ft_printf("{%d}\n\n", ft_printf("\033[1;31mTest 15 => \033[0m|%0.10f||%0.10F||%0.10LF|", 42424242.4242424242424242,424242424242.424242424242, 424242424242.424242424242L));

	printf("{%d}\n", printf("\033[1;32mTest 15 => \033[0m|%0.12f||%0.12F||%0.12LF|", 42424242.4242424242424242, 424242424242.424242424242, 424242424242.424242424242L));
	ft_printf("{%d}\n\n", ft_printf("\033[1;31mTest 15 => \033[0m|%0.12f||%0.12F||%0.12LF|", 42424242.4242424242424242,424242424242.424242424242, 424242424242.424242424242L));

	d = printf("   \x1b[32mprintf:\x1b[0m neg 0 float %f\t", -0.0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m neg 0 float %f\t", -0.0);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %f\t", 1.0999999);
   	printf("%d\n", d);
   	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %f\t", 1.0999999);
   	printf("%d\n", d1);
   	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %#.0f\t", 1, 9.9);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %#.0f\t", 1, 9.9);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %.f\t", 1, 9.6999);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.f\t", 1, 9.6999);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %05.0f\t", 1, 0.6999);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %05.0f\t", 1, 0.6999);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %+.4f\t", -67.33399);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %+.4f\t",  -67.33399);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %#+ .3f\t", -99.9999);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %#+ .3f\t",  -99.9999);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %0-10.24f\t", 0.99999999999999999999999999999999999999);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %0-10.24f\t", 0.99999999999999999999999999999999999999);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %+5f\t", 0.2344499);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %+5f\t", 0.2344499);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %#-*.*f|\t", 1, -2, 3, 4.0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %#-*.*f|\t", 1, -2, 3, 4.0);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %07.0f|\t", 0.0 / 0.0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %07.0f|\t", 0.0 / 0.0);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %10.2f|\t", 6.0 / 0.0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %10.2f|\t", 6.0 / 0.0);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %+09.1f|\t", 6.0 / -0.0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %+09.1f|\t", 6.0 / -0.0);
	printf("%d\n", d1);
	ft_printf("\n");

	printf("%d\n",  printf("%#.8Lf\t", 666.99999999L));
	ft_printf("%d\n", ft_printf("%#.8Lf\t",  666.99999999L));

	printf("%d\n",  printf("%#.9Lf\t", 666.99999999L));
	ft_printf("%d\n", ft_printf("%#.9Lf\t",  666.99999999L));

	printf("%d\n",  printf("%#.15Lf\t", 666.99999999L));
	ft_printf("%d\n", ft_printf("%#.15Lf\t",  666.99999999L));

	printf("%d\n",  printf("%#.8f\t", 666.99999999));
	ft_printf("%d\n", ft_printf("%#.8f\t",  666.99999999));

	printf("%d\n",  printf("%#.9f\t", 666.99999999));
	ft_printf("%d\n", ft_printf("%#.9f\t",  666.99999999));

	printf("%d\n",  printf("%#.15f\t", 666.99999999));
	ft_printf("%d\n", ft_printf("%#.15f\t",  666.99999999));

	printf("%d\n",  printf("%#.16f\t", 666.99999999));
	ft_printf("%d\n", ft_printf("%#.16f\t",  666.99999999));

	printf("\n\x1b[35m-------- BONUS --------\x1b[0m\n\n");



	d = printf("   \x1b[32mprintf:\x1b[0m %C%C\t", '4', '2');
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %C%C\t", '4', '2');
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m wchar_t str %ls\t", L"Tony");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m wchar_t str %ls\t", L"Tony");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m wchar_t str with precision %.2ls\t", L"Tony");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m wchar_t str with precision %.2ls\t", L"Tony");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m wint_t %lc\t", 74);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m wint_t %lc\t", 74);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m wint_t C %C\t", 74);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m wint_t C %C\t", 74);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m wchar_t str S %S\t", L"Tony");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m wchar_t str S %S\t", L"Tony");
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m wchar_t empty str %ls\t", L"");
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m wchar_t empty str %ls\t", L"");
	printf("%i\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m wchar_t NULL pointer %ls\t", NULL);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m wchar_t NULL pointer %ls\t", NULL);
	printf("%i\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m wchar_t NULL pointer and width %10ls\t", NULL);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m wchar_t NULL pointer and width %10ls\t", NULL);
	printf("%i\n\n", d1);


	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m binary - %b\t", 2);
	printf("%i\n", d1);
	ft_printf("\n");

	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m BIG B binary + format  - %#B\t", 2);
	printf("%i\n", d1);
	ft_printf("\n");

	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m BIG B binary 0 + format  - %#B\t", 0);
	printf("%i\n", d1);
	ft_printf("\n");

	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m zero binary with format - %b\t", 0);
	printf("%i\n", d1);
	ft_printf("\n");

	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m binary with format and l - %#lb\t", 50000000000);
	printf("%i\n", d1);
	ft_printf("\n");

	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m neg binary with format- %#b\t", -255);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m z spec - %zi\t", 4294967296);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m z spec - %zi\t", 4294967296);
	printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m jzd %jzd\t", 9223372036854775807);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m jzd %jzd\t", 9223372036854775807);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m zhd %zhd\t", 4294967296);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m zhd %zhd\t", 4294967296);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m jhd %jhd\t", 9223372036854775807);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m jhd %jhd\t", 9223372036854775807);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m zu %zu\t", 18446744073709551615);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m zu %zu\t", 18446744073709551615);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m zd %zd\t", -9223372036854775808);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m zd %zd\t", -9223372036854775808);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m Zu %Zu\t", 18446744073709551615);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m Zu %Zu\t", 18446744073709551615);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m Zd %Zd\t", -9223372036854775808);
	printf("%i\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m Zd %Zd\t", -9223372036854775808);
	printf("%i\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m invalid arg for str with precision %.s.\t", 42);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m invalid arg for str with precision %.s.\t", 42);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m int with precision %.1d\t", 100);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m int with precision %.1d\t", 100);
	printf("%d\n", d1);
	printf("\n");

	printf("{%d}\n", printf("\033[1;32mTest HEX => \033[0m|%#-9.5x|", 42));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest HEX => \033[0m|%#-9.5x|", 42));
	printf("\n");

	printf("{%d}\n", printf("\033[1;32mTest 17 => \033[0m|%#12x|", 42));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 17 => \033[0m|%#12x|", 42));
	ft_printf("\n");

	printf("{%d}\n", printf("\033[1;32mTest 34 => \033[0m|%09.2x|", 42));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 34 => \033[0m|%09.2x|", 42));
	ft_printf("\n");

	printf("{%d}\n", printf("\033[1;32mTest 36 => \033[0m|%#5.x, %#.0x|", 0, 42));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 36 => \033[0m|%#5.x, %#.0x|", 0, 42));
	ft_printf("\n");

	printf("{%d}\n", printf("\033[1;32mTest 38 => \033[0m|%.x, %.0x|", 42, 42));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 38 => \033[0m|%.x, %.0x|", 42, 42));
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m @moulitest: %#6.x %#6.0x\t", 0, 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m @moulitest: %#6.x %#6.0x\t", 0, 0);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %#.o %#.0o\t", 0, 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %#.o %#.0o\t", 0, 0);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %.o %.0o\t", 0, 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.o %.0o\t", 0, 0);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %#o\t", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %#o\t", 0);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %o\t", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %o\t", 0);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %#5.4o\t", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %#5.4o\t", 0);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %#.3o\t", 1);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %#.3o\t", 1);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %#.o\t", 3);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %#.o\t", 3);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %#.0o\t", 3);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %#.0o\t", 3);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m -0 %d\t", -0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m -0 %d\t", -0);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %.d %.0d\t", 0, 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.d %.0d\t", 0, 0);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %5.d %5.0d\t", 0, 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %5.d %5.0d\t", 0, 0);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %.2s is a string\t", "");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.2s is a string\t", "");
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %5.2s is a string\t", "");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %5.2s is a string\t", "");
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %-.2s is a string\t", "");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %-.2s is a string\t", "");
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %-5.2s is a string\t", "");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %-5.2s is a string\t", "");
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %0*s is a string\t", 10, "");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %0*s is a string\t", 10, "");
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %.20d d with pr 20\t", 7);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.20d d with pr 20\t", 7);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %010.d\t", 256);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %010.d\t", 256);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %010.x\t", 256);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %010.x\t", 256);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %010.o\t", 256);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %010.o\t", 256);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %010.f\t", 256);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %010.f\t", 256);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %+.0d\t", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %+.0d\t", 0);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %+.5d\t", 55);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %+.5d\t", 55);
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %.4s", "42");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.4s", "42");
	ft_printf("%d\n", d1);
	ft_printf("\n");

	d = printf("   \x1b[32mprintf:\x1b[0m %####0000 33..1..#00d\t", 256);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %####0000 33..1..#00d\t", 256);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %###-#0000 33...12..#0+0d\t", 256);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %###-#0000 33...12..#0+0d\t", 256);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %####0000 33..1d\t", 256);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %####0000 33..1d\t", 256);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %####0000 33..1f\t", 33.33);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %####0000 33..1f\t", 33.33);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %015..7f\t", 33.33);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %015..7f\t", 33.33);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %#0015..7f\t", 44.44444);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %#0015..7f\t", 44.44444);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %#0015..7d\t", 44);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %#0015..7d\t", 44);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %100  -+5d\t", 5);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %100  -+5d\t", 5);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m pointer . %.0p, %.p\t", 0, 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m pointer . %.0p, %.p\t", 0, 0);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m text after f %fdfdfd.\t");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m text after f %fdfdfd.\t");
	ft_printf("%d\n", d1);
	ft_printf("\n");
	//
	//
	// d = printf("   \x1b[32mprintf:\x1b[0m str with neg precision %.-5s.\t","hello, world");
	// printf("%d\n", d);
	// d1 = ft_printf("\x1b[33mft_printf:\x1b[0m str with neg precision %.-5s.\t","hello, world");
	// ft_printf("%d\n", d1);
	// ft_printf("\n");
	//
	d = printf("   \x1b[32mprintf:\x1b[0m char with neg precision %.-5c.\t", 122);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m char with neg precision %.-5c.\t",122);
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m char with neg precision %.-c.\t", 122);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m char with neg precision %.-c.\t",122);
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m char * with neg precision %.-3s.\t", "hi, there");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m char * with neg precision %.-3s.\t","hi, there");
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m char * with neg precision * %.*s.\t", -3, "hi, there");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m char * with neg precision * %.*s.\t", -3, "hi, there");
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m char with neg precision %.*c.\t", -5, 122);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m char with neg precision %.*c.\t", -5, 122);
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m d with neg width %*d.\t", -5, 50);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m d with neg width %*d.\t", -5, 50);
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m d with neg width %.*d.\t", -15, 50);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m d with neg width %.*d.\t", -15, 50);
	ft_printf("%d\n\n", d1);


	d = printf("   \x1b[32mprintf:\x1b[0m d with neg width %-5d.\t", -5, 50);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m d with neg width %-5d.\t", -5, 50);
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m FLOAT with neg precision -5 %.-5F\t",1.0000004);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m FLOAT with neg precision -5 %.-5F\t", 1.0000004);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m FLOAT with neg precision -5 %.*F\t", -5, 1.0000004);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m FLOAT with neg precision -5 %.*F\t", -5, 1.0000004);
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m FLOAT with neg precision * -1 %.*f\t", -1, 2.0034500004);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m FLOAT with neg precision * -1 %.*f\t", -1, 2.0034500004);
	printf("%d\n\n", d1);

	setlocale(LC_ALL, "");

	d = printf("   \x1b[32mprintf:\x1b[0m %.C", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.C", 0);
	ft_printf("%d\n\n", d1);

	printf("{%d}\n", printf("\033[1;32mTest 7 => \033[0m|%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S|", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L""));
	ft_printf("{%d}\n\n", ft_printf("\033[1;31mTest 7 => \033[0m|%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S|", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L""));

	d = printf("   \x1b[32mprintf:\x1b[0m %lc, %lc\t", L'ÊM-^ZM-^V',L'ÿ≠');
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %lc, %lc\t", L'ÊM-^ZM-^V',L'ÿ≠');
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %.4S\t", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %.4S\t", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %4.15S\t", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %4.15S\t", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%d\n\n", d1);

	printf("{%d}\n", printf("\033[1;32mTest 3 => \033[0m|%15.6S|", L"我¼是一只猫。"));
	ft_printf("{%d}\n\n", ft_printf("\033[1;31mTest 3 => \033[0m|%15.6S|", L"我¼是一只猫。"));

	printf("{%d}\n", printf("\033[1;32mTest 22 => \033[0m|%0.5S|", L"᳄ ᳄ "));
	ft_printf("{%d}\n\n", ft_printf("\033[1;31mTest 22 => \033[0m|%0.5S|", L"᳄ ᳄ "));

	d = printf("   \x1b[32mprintf:\x1b[0m %8.d\t", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %8.d\t", 0);
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %8.0d\t", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %8.0d\t", 0);
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %8.1d\t", 0);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %8.1d\t", 0);
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %8.d\t", 42);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %8.d\t", 42);
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %8.0d\t", 42);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %8.0d\t", 42);
	ft_printf("%d\n\n", d1);

	d = printf("   \x1b[32mprintf:\x1b[0m %8.1d\t", 42);
	printf("%d\n", d);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m %8.1d\t", 42);
	ft_printf("%d\n\n", d1);

	printf("{%d}\n", printf("\033[1;32mTest 24 => \033[0m|%lhl|", "9223372036854775807"));
	ft_printf("{%d}\n\n", ft_printf("\033[1;31mTest 24 => \033[0m|%lhl|", "9223372036854775807"));

	printf("{%d}\n", printf("\033[1;32mTest 25 => \033[0m|%lhlz|", "9223372036854775807"));
	ft_printf("{%d}\n\n", ft_printf("\033[1;31mTest 25 => \033[0m|%lhlz|", "9223372036854775807"));

	printf("{%d}\n", printf("\033[1;32mTest 27 => \033[0m|%lhh|", "2147483647"));
	ft_printf("{%d}\n\n", ft_printf("\033[1;31mTest 27 => \033[0m|%lhh|", "2147483647"));


	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m fd %^0.5d\t", 42);
	ft_printf("%d\n\n", d1);
	d1 = ft_printf("\x1b[33mft_printf:\x1b[0m fd %5^0\t", 42);
	ft_printf("%d\n\n", d1);



	return (0);
}
