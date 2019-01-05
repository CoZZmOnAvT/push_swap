/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/02 16:17:55 by cozzmonavt                               */
/*   Updated: 2019/01/05 23:29:02 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unity.h>
#include <fcntl.h>
#include <libgen.h>
#include "libft.h"

char * g_executable_path;

void test_ft_abs(void)
{
	TEST_ASSERT_EQUAL_INT64(0, ft_abs(0));
	TEST_ASSERT_EQUAL_INT64(1, ft_abs(1));
	TEST_ASSERT_EQUAL_INT64(1L, ft_abs(1L));
	TEST_ASSERT_EQUAL_INT64(1, ft_abs(-1));
	TEST_ASSERT_EQUAL_INT64(1L, ft_abs(-1L));
	TEST_ASSERT_EQUAL_INT64(INT64_MAX, ft_abs(INT64_MAX));
	TEST_ASSERT_EQUAL_INT64(INT64_MAX, ft_abs(-INT64_MAX));
}

void test_ft_atoi(void)
{
	TEST_ASSERT_EQUAL_INT64(0, ft_atoi("0"));
	TEST_ASSERT_EQUAL_INT64(-1, ft_atoi("-1"));
	TEST_ASSERT_EQUAL_INT64(atoi("-+1"), ft_atoi("-+1"));
	TEST_ASSERT_EQUAL_INT64(atoi("+-1"), ft_atoi("+-1"));
	TEST_ASSERT_EQUAL_INT64(atoi("+-a"), ft_atoi("+-a"));
	TEST_ASSERT_EQUAL_INT64(-65535, ft_atoi("-65535"));
	TEST_ASSERT_EQUAL_INT64(-65536, ft_atoi("-65536"));
	TEST_ASSERT_EQUAL_INT64(65536, ft_atoi("65536"));
	TEST_ASSERT_EQUAL_INT64(atoi("   1425"), ft_atoi("   1425"));
	TEST_ASSERT_EQUAL_INT64(atoi("   1425    "), ft_atoi("   1425    "));
	TEST_ASSERT_EQUAL_INT64(atoi("12s1425"), ft_atoi("12s1425"));
	TEST_ASSERT_EQUAL_INT64(atoi(""), ft_atoi(""));
	TEST_ASSERT_EQUAL_INT64(atoi("            "), ft_atoi("            "));
	TEST_ASSERT_EQUAL_INT64(atoi("Hello World"), ft_atoi("Hello World"));
	TEST_ASSERT_EQUAL_INT64(atoi(" 2147483647 "), ft_atoi(" 2147483647 "));
	TEST_ASSERT_EQUAL_INT64(atoi(" -2147483647 "), ft_atoi(" -2147483647 "));
	TEST_ASSERT_EQUAL_INT64(atoi(" -2147483648 "), ft_atoi(" -2147483648 "));
	TEST_ASSERT_EQUAL_INT64(atoi(" +2147483648 "), ft_atoi(" +2147483648 "));
	TEST_ASSERT_EQUAL_INT64(atoi(" -2147483649 "), ft_atoi(" -2147483649 "));
	TEST_ASSERT_EQUAL_INT64(atoi("9223372036854775807"), ft_atoi("9223372036854775807"));
	TEST_ASSERT_EQUAL_INT64(atoi("-9223372036854775808"), ft_atoi("-9223372036854775808"));
	TEST_ASSERT_EQUAL_INT64(atoi("9223372036854775808"), ft_atoi("9223372036854775808"));
	TEST_ASSERT_EQUAL_INT64(atoi("18446744073709551615"), ft_atoi("18446744073709551615"));
	TEST_ASSERT_EQUAL_INT64(atoi("18446744073709551616"), ft_atoi("18446744073709551616"));
	TEST_ASSERT_EQUAL_INT64_MESSAGE(atoi("922337203685477580712125325543357343463643464634633466344366323523959359238"),
			ft_atoi("922337203685477580712125325543357343463643464634633466344366323523959359238"),
			"\"922337203685477580712125325543357343463643464634633466344366323523959359238\"");
	TEST_ASSERT_EQUAL_INT64_MESSAGE(atoi("-922337203685477580712125325543357343463643464634633466344366323523959359238"),
			ft_atoi("-922337203685477580712125325543357343463643464634633466344366323523959359238"),
			"\"-922337203685477580712125325543357343463643464634633466344366323523959359238\"");
}

void test_ft_atoll(void)
{
	TEST_ASSERT_EQUAL_INT64(0, ft_atoll("0"));
	TEST_ASSERT_EQUAL_INT64(-1, ft_atoll("-1"));
	TEST_ASSERT_EQUAL_INT64(atoll("-+1"), ft_atoll("-+1"));
	TEST_ASSERT_EQUAL_INT64(atoll("+-1"), ft_atoll("+-1"));
	TEST_ASSERT_EQUAL_INT64(atoll("+-a"), ft_atoll("+-a"));
	TEST_ASSERT_EQUAL_INT64(-65535, ft_atoll("-65535"));
	TEST_ASSERT_EQUAL_INT64(-65536, ft_atoll("-65536"));
	TEST_ASSERT_EQUAL_INT64(65536, ft_atoll("65536"));
	TEST_ASSERT_EQUAL_INT64(atoll("   1425"), ft_atoll("   1425"));
	TEST_ASSERT_EQUAL_INT64(atoll("   1425    "), ft_atoll("   1425    "));
	TEST_ASSERT_EQUAL_INT64(atoll("12s1425"), ft_atoll("12s1425"));
	TEST_ASSERT_EQUAL_INT64(atoll(""), ft_atoll(""));
	TEST_ASSERT_EQUAL_INT64(atoll("            "), ft_atoll("            "));
	TEST_ASSERT_EQUAL_INT64(atoll("Hello World"), ft_atoll("Hello World"));
	TEST_ASSERT_EQUAL_INT64(atoll(" 2147483647 "), ft_atoll(" 2147483647 "));
	TEST_ASSERT_EQUAL_INT64(atoll(" -2147483647 "), ft_atoll(" -2147483647 "));
	TEST_ASSERT_EQUAL_INT64(atoll(" -2147483648 "), ft_atoll(" -2147483648 "));
	TEST_ASSERT_EQUAL_INT64(atoll(" +2147483648 "), ft_atoll(" +2147483648 "));
	TEST_ASSERT_EQUAL_INT64(atoll(" -2147483649 "), ft_atoll(" -2147483649 "));
	TEST_ASSERT_EQUAL_INT64(atoll("9223372036854775807"), ft_atoll("9223372036854775807"));
	TEST_ASSERT_EQUAL_INT64(atoll("-9223372036854775808"), ft_atoll("-9223372036854775808"));
	TEST_ASSERT_EQUAL_INT64(atoll("9223372036854775808"), ft_atoll("9223372036854775808"));
	TEST_ASSERT_EQUAL_INT64(atoll("18446744073709551615"), ft_atoll("18446744073709551615"));
	TEST_ASSERT_EQUAL_INT64(atoll("18446744073709551616"), ft_atoll("18446744073709551616"));
	TEST_ASSERT_EQUAL_INT64_MESSAGE(atoll("922337203685477580712125325543357343463643464634633466344366323523959359238"),
			ft_atoll("922337203685477580712125325543357343463643464634633466344366323523959359238"),
			"\"922337203685477580712125325543357343463643464634633466344366323523959359238\"");
	TEST_ASSERT_EQUAL_INT64_MESSAGE(atoll("-922337203685477580712125325543357343463643464634633466344366323523959359238"),
			ft_atoll("-922337203685477580712125325543357343463643464634633466344366323523959359238"),
			"\"-922337203685477580712125325543357343463643464634633466344366323523959359238\"");
}

void test_ft_atol_base(void)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ft_atol_base("Hello World", 3), "\"Hello World\"");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ft_atol_base("1", 1), "Base lower than 2");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ft_atol_base("1", 37), "Base greater than 36");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ft_atol_base("", 16), "Empty string");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ft_atol_base("                 ", 16), "Empty string");
	TEST_ASSERT_EQUAL_INT(2147483647, ft_atol_base("2147483647", 10));
	TEST_ASSERT_EQUAL_INT(2147483648, ft_atol_base("2147483648", 10));
	TEST_ASSERT_EQUAL_INT(-1, ft_atol_base("-1", 10));
	TEST_ASSERT_EQUAL_HEX64(-0x01, ft_atol_base("-1", 16));
	TEST_ASSERT_BITS(0x1555, 0x1555, ft_atol_base("1010101010101", 2));
	TEST_ASSERT_BITS(0x1, 0x1, ft_atol_base("1", 2));
	TEST_ASSERT_MESSAGE(ft_atol_base("27", 8) == 027, "027");
	TEST_ASSERT_MESSAGE(ft_atol_base("278", 8) == 027, "0278");
	TEST_ASSERT_EQUAL_HEX64(0x27, ft_atol_base("27", 16));
	TEST_ASSERT_EQUAL_HEX64(0xFF, ft_atol_base("FFG", 16));
	TEST_ASSERT_EQUAL_HEX64(0xFFFFFF, ft_atol_base("FFFFFF", 16));
	TEST_ASSERT_EQUAL_HEX64(-0xFFFFFF, ft_atol_base("-FFFFFF", 16));
	TEST_ASSERT_EQUAL_HEX64(0xFFFFFF, ft_atol_base("+FFFFFF", 16));
	TEST_ASSERT_EQUAL_HEX64(0xFFFFFFFFFFFF, ft_atol_base("FFFFFFFFFFFF", 16));
	TEST_ASSERT_EQUAL_HEX64(0xFFFFFFFFFFFFFFF, ft_atol_base("FFFFFFFFFFFFFFF", 16));
	TEST_ASSERT_EQUAL_HEX64(0x7FFFFFFFFFFFFFFF, ft_atol_base("7FFFFFFFFFFFFFFF", 16));
	TEST_ASSERT_EQUAL_HEX64(LLONG_MIN, ft_atol_base("8000000000000000", 16));
	TEST_ASSERT_EQUAL_HEX64(-0x7000000000000001, ft_atol_base("8FFFFFFFFFFFFFFF", 16));
	TEST_ASSERT_MESSAGE(ft_atol_base("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", 36) == -0x1AF5578FFCA80505, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ, Base: 36");
	TEST_ASSERT_MESSAGE(ft_atol_base("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!", 36) == -0x1AF5578FFCA80505, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!, Base: 36");
	TEST_ASSERT_MESSAGE(ft_atol_base("Z!", 36) == 35, "Z!, Base: 36");
}

void test_ft_bzero(void)
{
	char ex_1[0x11];
	char ex_2[0x11];

	TEST_ASSERT_EQUAL_MEMORY(ft_bzero(ex_1, 0x11), memset(ex_2, 0, 0x11), 0x11);
	TEST_ASSERT_EQUAL_MEMORY(ft_bzero(ex_1, 0), memset(ex_2, 0, 0), 0x11);
	ex_1[0xF] = 'A';
	ex_2[0xF] = 'A';
	TEST_ASSERT_EQUAL_MEMORY(ft_bzero(ex_1, 0xF), memset(ex_2, 0, 0xF), 0x11);
	TEST_ASSERT_EQUAL_MEMORY(ft_bzero(ex_1, 0x10), memset(ex_2, 0, 0x10), 0x11);
}

void test_ft_degtorad(void)
{
	TEST_ASSERT_EQUAL_FLOAT(0, ft_degtorad(0));
	TEST_ASSERT_EQUAL_FLOAT(M_PI / 6.0, ft_degtorad(30.0));
	TEST_ASSERT_EQUAL_FLOAT(M_PI / 4.0, ft_degtorad(45.0));
	TEST_ASSERT_EQUAL_FLOAT(M_PI / 3.0, ft_degtorad(60.0));
	TEST_ASSERT_EQUAL_FLOAT(M_PI / 2.0, ft_degtorad(90.0));
	TEST_ASSERT_EQUAL_FLOAT(2 * M_PI / 3.0, ft_degtorad(120.0));
	TEST_ASSERT_EQUAL_FLOAT(3 * M_PI / 4.0, ft_degtorad(135.0));
	TEST_ASSERT_EQUAL_FLOAT(5 * M_PI / 6.0, ft_degtorad(150.0));
	TEST_ASSERT_EQUAL_FLOAT(M_PI, ft_degtorad(180.0));
}

void test_ft_dlstnew(void)
{
	{
		t_dlist	*node = ft_dlstnew(NULL, 0);

		TEST_ASSERT_MESSAGE(node->next == node && node->prev == node, "The list is wrong linked");
		TEST_ASSERT_EQUAL_PTR(NULL, node->content);
		TEST_ASSERT_EQUAL_INT64(0, node->content_size);
		ft_dlstdelelem(&node);
	}
	{
		char const str[] = "Hello World";
		t_dlist	*node = ft_dlstnew(str, sizeof(str));

		TEST_ASSERT_EQUAL_STRING(str, node->content);
		TEST_ASSERT_EQUAL_INT64(sizeof(str), node->content_size);
		ft_dlstdelelem(&node);
	}
}

void test_ft_dlstpush(void)
{
	char const str[] = "Hello World";
	char const str2[] = "Bye World";
	t_dlist	*node = NULL;

	ft_dlstpush(&node, ft_dlstnew(str, sizeof(str)));
	// The first item of the list is always should be zero content and zero size, it's an anchor to know the beginning
	TEST_ASSERT_EQUAL_PTR(NULL, node->content);
	TEST_ASSERT_EQUAL_INT64(0, node->content_size);
	TEST_ASSERT_EQUAL_STRING(str, node->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str), node->next->content_size);
	TEST_ASSERT_EQUAL_STRING(str, node->prev->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str), node->prev->content_size);

	ft_dlstpush(&node, ft_dlstnew(str2, sizeof(str2)));
	TEST_ASSERT_EQUAL_STRING(str2, node->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str2), node->next->content_size);
	TEST_ASSERT_EQUAL_STRING(str, node->next->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str), node->next->next->content_size);

	ft_dlstclear(&node);
}


void test_ft_dlstpush_back(void)
{
	char const str[] = "Hello World";
	char const str2[] = "Bye World";
	t_dlist	*node = NULL;

	ft_dlstpush_back(&node, ft_dlstnew(str, sizeof(str)));
	// The first item of the list is always should be zero content and zero size, it's an anchor to know the beginning
	TEST_ASSERT_EQUAL_PTR(NULL, node->content);
	TEST_ASSERT_EQUAL_INT64(0, node->content_size);
	TEST_ASSERT_EQUAL_STRING(str, node->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str), node->next->content_size);
	TEST_ASSERT_EQUAL_STRING(str, node->prev->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str), node->prev->content_size);

	ft_dlstpush_back(&node, ft_dlstnew(str2, sizeof(str2)));
	TEST_ASSERT_EQUAL_STRING(str, node->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str), node->next->content_size);
	TEST_ASSERT_EQUAL_STRING(str2, node->next->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str2), node->next->next->content_size);

	ft_dlstclear(&node);
}

void test_ft_dlstpop(void)
{
	char const str[] = "Hello World";
	char const str2[] = "Bye World";
	t_dlist	*node = NULL;

	ft_dlstpush(&node, ft_dlstnew(str, sizeof(str)));
	ft_dlstpush(&node, ft_dlstnew(str2, sizeof(str2)));

	TEST_ASSERT_EQUAL_STRING(str2, node->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str2), node->next->content_size);
	ft_dlstpop(node);
	TEST_ASSERT_EQUAL_STRING(str, node->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str), node->next->content_size);
	TEST_ASSERT_EQUAL_INT64(1, ft_dlstsize(node));
	ft_dlstclear(&node);
}

void test_ft_dlstpop_back(void)
{
	char const str[] = "Hello World";
	char const str2[] = "Bye World";
	t_dlist	*node = NULL;

	ft_dlstpush(&node, ft_dlstnew(str, sizeof(str)));
	ft_dlstpush(&node, ft_dlstnew(str2, sizeof(str2)));

	TEST_ASSERT_EQUAL_STRING(str2, node->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str2), node->next->content_size);
	ft_dlstpop_back(node);
	TEST_ASSERT_EQUAL_STRING(str2, node->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str2), node->next->content_size);
	TEST_ASSERT_EQUAL_INT64(1, ft_dlstsize(node));
	ft_dlstclear(&node);
}

void test_ft_dlstdelelem(void)
{
	char const str[] = "Hello World";
	t_dlist	*node = ft_dlstnew(str, sizeof(str));

	ft_dlstdelelem(&node);
	TEST_ASSERT_EQUAL_PTR(NULL, node);
}

void test_ft_dlstclear(void)
{
	// Run valgrind (or smth else) to detect memory leaks here
	t_dlist	*node = NULL;

	ft_dlstpush(&node, ft_dlstnew(NULL, 0));
	ft_dlstpush(&node, ft_dlstnew(NULL, 0));
	ft_dlstpush(&node, ft_dlstnew(NULL, 0));
	ft_dlstpush(&node, ft_dlstnew(NULL, 0));
	ft_dlstclear(&node);
	TEST_ASSERT_EQUAL_PTR(NULL, node);
}

void test_ft_dlstsize(void)
{
	t_dlist	*node = NULL;

	ft_dlstpush(&node, ft_dlstnew(NULL, 0));
	ft_dlstpush(&node, ft_dlstnew(NULL, 0));
	ft_dlstpush(&node, ft_dlstnew(NULL, 0));
	ft_dlstpush(&node, ft_dlstnew(NULL, 0));
	TEST_ASSERT_EQUAL_INT64(4, ft_dlstsize(node));
	ft_dlstpop(node);
	TEST_ASSERT_EQUAL_INT64(3, ft_dlstsize(node));
	ft_dlstpop_back(node);
	TEST_ASSERT_EQUAL_INT64(2, ft_dlstsize(node));
	ft_dlstclear(&node);
	TEST_ASSERT_EQUAL_INT64(0, ft_dlstsize(node));
}

void test_ft_exp(void)
{
	TEST_ASSERT_EQUAL_FLOAT(1.0, ft_exp(0));
	TEST_ASSERT_EQUAL_FLOAT(M_E, ft_exp(1));
	TEST_ASSERT_EQUAL_FLOAT(7.389056099, ft_exp(2));
	TEST_ASSERT_EQUAL_FLOAT(20.085536923, ft_exp(3));
	TEST_ASSERT_EQUAL_FLOAT(54.598150033, ft_exp(4));
}

void test_ft_get_fractional(void)
{
	TEST_ASSERT_EQUAL_FLOAT(0.0, ft_get_fractional(1234.0));
	TEST_ASSERT_EQUAL_FLOAT(0.1234, ft_get_fractional(0.1234));
	TEST_ASSERT_EQUAL_FLOAT(0.1234, ft_get_fractional(1234.1234));
}

void test_ft_get_next_line(void)
{
	char relative_test_path[] = "res/basic_file.txt";
	char absolute_test_path[2048 + sizeof(relative_test_path)];
	int its = 2000;
	int fd;
	char *str;

	snprintf(absolute_test_path, sizeof(absolute_test_path), "%s/%s", g_executable_path, relative_test_path);
	while (its-- > 0)
	{
		TEST_ASSERT_MESSAGE((fd = open(absolute_test_path, O_RDONLY)) != -1, "Can't open test file");
		TEST_ASSERT_EQUAL_INT(1, ft_get_next_line(fd, &str));
		TEST_ASSERT_EQUAL_STRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit,", str);
		free(str);
		TEST_ASSERT_EQUAL_INT(1, ft_get_next_line(fd, &str));
		TEST_ASSERT_EQUAL_STRING("sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.", str);
		free(str);
		TEST_ASSERT_EQUAL_INT(1, ft_get_next_line(fd, &str));
		TEST_ASSERT_EQUAL_STRING("Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris", str);
		free(str);
		TEST_ASSERT_EQUAL_INT(1, ft_get_next_line(fd, &str));
		TEST_ASSERT_EQUAL_STRING("nisi ut aliquip ex ea commodo consequat.", str);
		free(str);
		TEST_ASSERT_EQUAL_INT(1, ft_get_next_line(fd, &str));
		TEST_ASSERT_EQUAL_STRING("", str);
		free(str);
		TEST_ASSERT_EQUAL_INT(1, ft_get_next_line(fd, &str));
		TEST_ASSERT_EQUAL_STRING("Hello World", str);
		free(str);
		TEST_ASSERT_EQUAL_INT(0, ft_get_next_line(fd, &str));
		TEST_ASSERT_EQUAL_STRING("", str);
		free(str);
		TEST_ASSERT_EQUAL_INT(0, ft_get_next_line(fd, &str));
		TEST_ASSERT_EQUAL_STRING(NULL, str);
		free(str);
		close(fd);
		usleep(10);
	}
	int invalid_file_descr = 42;

	TEST_ASSERT_EQUAL_INT(-1, ft_get_next_line(-1, &str));
	TEST_ASSERT_EQUAL_INT(-1, ft_get_next_line(1, NULL));
	TEST_ASSERT_EQUAL_INT(-1, ft_get_next_line(invalid_file_descr, &str));
}

void test_ft_hexlen(void)
{
	TEST_ASSERT_EQUAL_INT64(1, ft_hexlen(0x0));
	TEST_ASSERT_EQUAL_INT64(1, ft_hexlen(0xF));
	TEST_ASSERT_EQUAL_INT64(2, ft_hexlen(0xFF));
	TEST_ASSERT_EQUAL_INT64(4, ft_hexlen(0xFFFF));
	TEST_ASSERT_EQUAL_INT64(4, ft_hexlen(0x1234));
	TEST_ASSERT_EQUAL_INT64(8, ft_hexlen(0xFFFFFFFF));
}

void test_ft_lhexlen(void)
{
	TEST_ASSERT_EQUAL_INT64(1, ft_lhexlen(0x0));
	TEST_ASSERT_EQUAL_INT64(1, ft_lhexlen(0xF));
	TEST_ASSERT_EQUAL_INT64(2, ft_lhexlen(0xFF));
	TEST_ASSERT_EQUAL_INT64(4, ft_lhexlen(0xFFFF));
	TEST_ASSERT_EQUAL_INT64(4, ft_lhexlen(0x1234));
	TEST_ASSERT_EQUAL_INT64(8, ft_lhexlen(0xFFFFFFFF));
	TEST_ASSERT_EQUAL_INT64(16, ft_lhexlen(0xFFFFFFFFFFFFFFFF));
}

void test_ft_isalnum(void)
{
	char buff[8];
	unsigned char symb = 0;

	while (symb < 255)
	{
		snprintf(buff, sizeof(buff), "%#X", symb);
		if ((symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z') || (symb >= '0' && symb <= '9')) {
			TEST_ASSERT_MESSAGE(ft_isalnum(symb), buff);
		} else {
			TEST_ASSERT_MESSAGE(!ft_isalnum(symb), buff);
		}
		symb++;
	}
	TEST_ASSERT_MESSAGE(!ft_isalnum(0xFF), "0xFF");
}

void test_ft_isalpha(void)
{
	char buff[8];
	unsigned char symb = 0;

	while (symb < 255)
	{
		snprintf(buff, sizeof(buff), "%#X", symb);
		if ((symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z')) {
			TEST_ASSERT_MESSAGE(ft_isalpha(symb), buff);
		} else {
			TEST_ASSERT_MESSAGE(!ft_isalpha(symb), buff);
		}
		symb++;
	}
	TEST_ASSERT_MESSAGE(!ft_isalpha(0xFF), "0xFF");
}

void test_ft_isascii(void)
{
	char buff[8];
	int symb = 0;

	TEST_ASSERT_MESSAGE(ft_isascii(0), "0x0");
	while (++symb <= 127)
	{
		snprintf(buff, sizeof(buff), "%#X", symb);
		TEST_ASSERT_MESSAGE(ft_isascii(symb), buff);
		snprintf(buff, sizeof(buff), "%d", -symb);
		TEST_ASSERT_MESSAGE(!ft_isascii(-symb), buff);
	}
	TEST_ASSERT_MESSAGE(!ft_isascii(-128), "-128");
}

void test_ft_isdigit(void)
{
	char buff[8];
	unsigned char symb = 0;

	while (symb < 255)
	{
		snprintf(buff, sizeof(buff), "%#X", symb);
		if (symb >= '0' && symb <= '9') {
			TEST_ASSERT_MESSAGE(ft_isdigit(symb), buff);
		} else {
			TEST_ASSERT_MESSAGE(!ft_isdigit(symb), buff);
		}
		symb++;
	}
	TEST_ASSERT_MESSAGE(!ft_isdigit(0xFF), "0xFF");
}

void test_ft_isprint(void)
{
	char buff[8];
	unsigned char symb = 0;

	while (symb < 255)
	{
		snprintf(buff, sizeof(buff), "%#X", symb);
		if (symb >= ' ' && symb <= 126) {
			TEST_ASSERT_MESSAGE(ft_isprint(symb), buff);
		} else {
			TEST_ASSERT_MESSAGE(!ft_isprint(symb), buff);
		}
		symb++;
	}
	TEST_ASSERT_MESSAGE(!ft_isprint(0xFF), "0xFF");
}

void test_ft_itoa(void)
{
	char *str;

	TEST_ASSERT_EQUAL_STRING("0", (str = ft_itoa(0)));
	free(str);
	TEST_ASSERT_EQUAL_STRING("2147483647", (str = ft_itoa(INT_MAX)));
	free(str);
	TEST_ASSERT_EQUAL_STRING("-2147483648", (str = ft_itoa(INT_MIN)));
	free(str);
	TEST_ASSERT_EQUAL_STRING("1", (str = ft_itoa(1)));
	free(str);
	TEST_ASSERT_EQUAL_STRING("65535", (str = ft_itoa(UINT16_MAX)));
	free(str);
	TEST_ASSERT_EQUAL_STRING("32767", (str = ft_itoa(INT16_MAX)));
	free(str);
}

/* t_lst utillity functions [START]*/

void util_lst_deleter(void *data, size_t content_size)
{
	free(data);
	(void)content_size;
}

void util_lst_iterator(t_list * node)
{
	free(node->content);
	node->content = malloc(8);
	snprintf(node->content, 8, "SUCCESS");
	node->content_size = 1337;
}

t_list *util_lst_map_malloc(t_list * node)
{
	t_list *tmp = ft_lstnew(NULL, 0);

	tmp->content_size = node->content_size + 1;
	tmp->content = malloc(tmp->content_size);
	snprintf(tmp->content, tmp->content_size, "%s+", (char *)node->content);
	tmp->next = node->next;
	return (tmp);
}

t_list *util_lst_map_mreuse(t_list * node)
{
	char *tmp = node->content;

	node->content_size++;
	node->content = malloc(node->content_size);
	snprintf(node->content, node->content_size, "%s+", (char *)tmp);
	free(tmp);
	return (node);
}

/* t_lst utillity functions [END]*/

void test_ft_lstnew(void)
{
	{
		t_list	*node = ft_lstnew(NULL, 0);

		TEST_ASSERT_MESSAGE(node->next == NULL, "The list is wrong linked");
		TEST_ASSERT_EQUAL_PTR(NULL, node->content);
		TEST_ASSERT_EQUAL_INT64(0, node->content_size);
		ft_lstdelone(&node, NULL);
	}
	{
		char const str[] = "Hello World";
		t_list	*node = ft_lstnew(str, sizeof(str));

		TEST_ASSERT_EQUAL_STRING(str, node->content);
		TEST_ASSERT_EQUAL_INT64(sizeof(str), node->content_size);
		ft_lstdelone(&node, &util_lst_deleter);
	}
}

void test_ft_lstadd(void)
{
	char const str[] = "Hello World";
	char const str2[] = "Bye World";
	t_list	*node = NULL;

	ft_lstadd(&node, ft_lstnew(str, sizeof(str)));
	TEST_ASSERT_EQUAL_STRING(str, node->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str), node->content_size);
	TEST_ASSERT_EQUAL_PTR(NULL, node->next);

	ft_lstadd(&node, ft_lstnew(str2, sizeof(str2)));
	TEST_ASSERT_EQUAL_STRING(str2, node->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str2), node->content_size);
	TEST_ASSERT_EQUAL_STRING(str, node->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str), node->next->content_size);
	TEST_ASSERT_EQUAL_PTR(NULL, node->next->next);

	ft_lstdel(&node, &util_lst_deleter);
}

void test_ft_lstadd_back(void)
{
	char const str[] = "Hello World";
	char const str2[] = "Bye World";
	t_list	*node = NULL;

	ft_lstadd_back(&node, ft_lstnew(str, sizeof(str)));
	TEST_ASSERT_EQUAL_STRING(str, node->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str), node->content_size);
	TEST_ASSERT_EQUAL_PTR(NULL, node->next);

	ft_lstadd_back(&node, ft_lstnew(str2, sizeof(str2)));
	TEST_ASSERT_EQUAL_STRING(str, node->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str), node->content_size);
	TEST_ASSERT_EQUAL_STRING(str2, node->next->content);
	TEST_ASSERT_EQUAL_INT64(sizeof(str2), node->next->content_size);
	TEST_ASSERT_EQUAL_PTR(NULL, node->next->next);

	ft_lstdel(&node, &util_lst_deleter);
}

void test_ft_lstdel(void)
{
	// Run valgrind (or smth else) to detect memory leaks here
	t_list	*node = NULL;

	ft_lstadd(&node, ft_lstnew(NULL, 0));
	ft_lstadd(&node, ft_lstnew(NULL, 0));
	ft_lstadd(&node, ft_lstnew(NULL, 0));
	ft_lstadd(&node, ft_lstnew(NULL, 0));
	ft_lstdel(&node, NULL);
	TEST_ASSERT_EQUAL_PTR(NULL, node);
}

void test_ft_lstdelone(void)
{
	char const str[] = "Hello World";
	t_list	*node = ft_lstnew(str, sizeof(str));

	ft_lstdelone(&node, &util_lst_deleter);
	TEST_ASSERT_EQUAL_PTR(NULL, node);
}

void test_ft_lstiter(void)
{
	t_list	*node = NULL;
	t_list	*sp = NULL;

	ft_lstadd(&node, ft_lstnew("124jl1", 7));
	ft_lstadd(&node, ft_lstnew("JGJ41S", 7));
	ft_lstadd(&node, ft_lstnew("Aadq2f", 7));
	ft_lstadd(&node, ft_lstnew("AF21RD", 7));
	ft_lstiter(node, &util_lst_iterator);
	sp = node;
	while (node)
	{
		TEST_ASSERT_EQUAL_STRING("SUCCESS", node->content);
		TEST_ASSERT_EQUAL_INT64(1337, node->content_size);
		node = node->next;
	}
	ft_lstdel(&sp, &util_lst_deleter);
}

void test_ft_lstmap(void)
{
	t_list *(*func[2])(t_list *elem);

	func[0] = &util_lst_map_malloc;
	func[1] = &util_lst_map_mreuse;
	for (uint i = 0; i < sizeof(func) / sizeof(*func); i++)
	{
		t_list	*sp = NULL;
		t_list	*new_sp = NULL;
		t_list *list = NULL;
		t_list *new_list = NULL;

		ft_lstadd(&list, ft_lstnew("SUCCESS", 8));
		ft_lstadd(&list, ft_lstnew("SUCCESS", 8));
		ft_lstadd(&list, ft_lstnew("SUCCESS", 8));
		ft_lstadd(&list, ft_lstnew("SUCCESS", 8));
		new_list = ft_lstmap(list, func[i]);
		sp = list;
		new_sp = new_list;
		while (list)
		{
			TEST_ASSERT_EQUAL_STRING("SUCCESS", list->content);
			TEST_ASSERT_EQUAL_INT64(8, list->content_size);

			TEST_ASSERT_EQUAL_STRING("SUCCESS+", new_list->content);
			TEST_ASSERT_EQUAL_INT64(9, new_list->content_size);

			list = list->next;
			new_list = new_list->next;
		}
		ft_lstdel(&sp, &util_lst_deleter);
		ft_lstdel(&new_sp, &util_lst_deleter);
	}
}

void test_ft_memalloc(void)
{
	void *data = ft_memalloc(1024);

	TEST_ASSERT_EACH_EQUAL_INT8(0, data, 1024);
	free(data);
}

void test_ft_memccpy(void)
{
	uint8_t *my_data = malloc(16);
	uint8_t *sys_data = malloc(16);

	{
		char const *s = "Hello\0W0rld";

		memset(my_data, 0, 16);
		memset(sys_data, 0, 16);
		TEST_ASSERT_NOT_EQUAL(NULL, memccpy(sys_data, s, '0', 13));
		TEST_ASSERT_NOT_EQUAL(NULL, ft_memccpy(my_data, s, '0', 13));
		TEST_ASSERT_EQUAL_MEMORY(sys_data, my_data, 16);
	}
	{
		char const *s = "Hello World Man";

		memset(my_data, 0, 16);
		memset(sys_data, 0, 16);
		TEST_ASSERT_EQUAL_PTR(memccpy(sys_data, s, 'z', 16), ft_memccpy(my_data, s, 'z', 16));
		TEST_ASSERT_EQUAL_MEMORY(sys_data, my_data, 16);
	}
	{
		char const *s = "";

		memset(my_data, 0, 16);
		memset(sys_data, 0, 16);
		TEST_ASSERT_EQUAL_PTR(memccpy(sys_data, s, 'q', 1), ft_memccpy(my_data, s, 'q', 1));
		TEST_ASSERT_EQUAL_MEMORY(sys_data, my_data, 16);
	}
	free(sys_data);
	free(my_data);
}

void test_ft_memchr(void)
{
	{
		char s[] = "Example string";
		TEST_ASSERT_EQUAL_PTR(memchr(s, 'p', sizeof(s)), ft_memchr(s, 'p', sizeof(s)));
	}
	{
		char const *s = "";
		TEST_ASSERT_EQUAL_PTR(memchr(s, 'x', strlen(s) + 1), ft_memchr(s, 'x', strlen(s) + 1));
	}
	{
		char const *s = "abcdefabcdef";
		TEST_ASSERT_EQUAL_PTR(memchr(s, 'y', strlen(s) + 1), ft_memchr(s, 'y', strlen(s) + 1));
	}
	{
		char const *s = "11111111111111111111";
		TEST_ASSERT_EQUAL_PTR(memchr(s, '1', strlen(s) + 1), ft_memchr(s, '1', strlen(s) + 1));
	}
}

void test_ft_memcmp(void)
{
	{
		char s1[] = "DWgaOtP12df0";
		char s2[] = "DWgaOtP12DF0i";

		TEST_ASSERT_EQUAL_INT(memcmp(s1, s2, sizeof(s1)), ft_memcmp(s1, s2, sizeof(s1)));
		TEST_ASSERT_EQUAL_INT(memcmp(s1, s2, 9), ft_memcmp(s1, s2, 9));
	}
	{
		char s1[] = "lox mydak";
		char s2[] = "lox mydaki";

		TEST_ASSERT_EQUAL_INT(memcmp(s1, s2, sizeof(s1) - 1), ft_memcmp(s1, s2, sizeof(s1) - 1));
		TEST_ASSERT_EQUAL_INT(memcmp(s1, s2, sizeof(s1)), ft_memcmp(s1, s2, sizeof(s1)));
		TEST_ASSERT_EQUAL_INT(memcmp(s1, s2, sizeof(s2)), ft_memcmp(s1, s2, sizeof(s2)));
	}
}

void test_ft_memcpy(void)
{
	char my_data[16] = {0};
	char sys_data[16] = {0};
	char s[16] = "Hello World";

	TEST_ASSERT_EQUAL_MEMORY(memcpy(sys_data, s, 12), ft_memcpy(my_data, s, 12), sizeof(sys_data));
	TEST_ASSERT_EQUAL_MEMORY(memcpy(sys_data, s, sizeof(s)), ft_memcpy(my_data, s, sizeof(s)), sizeof(sys_data));
}

void test_ft_memdel(void)
{
	void *data = malloc(8);

	ft_memdel(&data);
	TEST_ASSERT_EQUAL_PTR(NULL, data);
}

void test_ft_memmove(void)
{
	char	my_data[128] = "OKOKO World!";
	char	sys_data[128] = "OKOKO World!";

	{
		char const *s = "Hello";
		TEST_ASSERT_EQUAL_MEMORY(memmove(sys_data, s, strlen(s)), ft_memmove(my_data, s, strlen(s)), sizeof(sys_data));
	}
	{
		char const *s = "H\0llo";
		TEST_ASSERT_EQUAL_MEMORY(memmove(sys_data, s, 5), ft_memmove(my_data, s, 5), sizeof(sys_data));
	}
	{
		char const *s = "It's Perfect!!!";
		memset(sys_data, 0, sizeof(sys_data));
		memset(my_data, 0, sizeof(my_data));
		snprintf(sys_data, sizeof(sys_data), "OKOKO World!");
		snprintf(my_data, sizeof(my_data), "OKOKO World!");
		TEST_ASSERT_EQUAL_MEMORY(memmove(sys_data, s, strlen(s) + 1), ft_memmove(my_data, s, strlen(s) + 1), sizeof(sys_data));
	}
	{
		char const *s = "It's Perfect!!!";
		memset(sys_data, 0, sizeof(sys_data));
		memset(my_data, 0, sizeof(my_data));
		snprintf(sys_data, sizeof(sys_data), "%s", s);
		snprintf(my_data, sizeof(my_data), "%s", s);
		memmove(sys_data + 15, sys_data + 4, 11);
		ft_memmove(my_data + 15, my_data + 4, 11);
		TEST_ASSERT_EQUAL_MEMORY(sys_data, my_data, sizeof(sys_data));
	}
}

void test_ft_memset(void)
{
	char	my_data[16] = "OKOKO World!";
	char	sys_data[16] = "OKOKO World!";

	TEST_ASSERT_EQUAL_MEMORY(memset(sys_data, 2, 3), ft_memset(my_data, 2, 3), sizeof(sys_data));
	TEST_ASSERT_EQUAL_MEMORY(memset(sys_data, 4, 12), ft_memset(my_data, 4, 12), sizeof(sys_data));
	TEST_ASSERT_EQUAL_MEMORY(memset(sys_data, 'x', sizeof(sys_data)), ft_memset(my_data, 'x', sizeof(my_data)), sizeof(sys_data));
}

void test_ft_nbrblen(void)
{
	TEST_ASSERT_EQUAL_INT8(1, ft_nbrblen(0));
	TEST_ASSERT_EQUAL_INT8(1, ft_nbrblen(1));
	TEST_ASSERT_EQUAL_INT8(2, ft_nbrblen(2));
	TEST_ASSERT_EQUAL_INT8(13, ft_nbrblen(0x1555));
	TEST_ASSERT_EQUAL_INT8(63, ft_nbrblen(LONG_MAX));
	TEST_ASSERT_EQUAL_INT8(64, ft_nbrblen(LONG_MIN));
}

void test_ft_nbrlen(void)
{
	TEST_ASSERT_EQUAL_INT8(3, ft_nbrlen(123));
	TEST_ASSERT_EQUAL_INT8(1, ft_nbrlen(1));
	TEST_ASSERT_EQUAL_INT8(2, ft_nbrlen(-1));
	TEST_ASSERT_EQUAL_INT8(1, ft_nbrlen(0));
	TEST_ASSERT_EQUAL_INT8(10, ft_nbrlen(INT_MAX));
	TEST_ASSERT_EQUAL_INT8(11, ft_nbrlen(INT_MIN));
}

void test_ft_nbrllen(void)
{
	TEST_ASSERT_EQUAL_INT8(3, ft_nbrllen(123));
	TEST_ASSERT_EQUAL_INT8(1, ft_nbrllen(1));
	TEST_ASSERT_EQUAL_INT8(2, ft_nbrllen(-1));
	TEST_ASSERT_EQUAL_INT8(1, ft_nbrllen(0));
	TEST_ASSERT_EQUAL_INT8(10, ft_nbrllen(INT_MAX));
	TEST_ASSERT_EQUAL_INT8(11, ft_nbrllen(INT_MIN));
	TEST_ASSERT_EQUAL_INT8(19, ft_nbrllen(LONG_MAX));
	TEST_ASSERT_EQUAL_INT8(20, ft_nbrllen(LONG_MIN));
}

void test_ft_nbrulen(void)
{
	TEST_ASSERT_EQUAL_INT8(3, ft_nbrulen(123));
	TEST_ASSERT_EQUAL_INT8(1, ft_nbrulen(1));
	TEST_ASSERT_EQUAL_INT8(10, ft_nbrulen(-1));
	TEST_ASSERT_EQUAL_INT8(1, ft_nbrulen(0));
	TEST_ASSERT_EQUAL_INT8(10, ft_nbrulen(INT_MAX));
	TEST_ASSERT_EQUAL_INT8(10, ft_nbrulen(INT_MIN));
}

void test_ft_nbrullen(void)
{
	TEST_ASSERT_EQUAL_INT8(3, ft_nbrullen(123));
	TEST_ASSERT_EQUAL_INT8(1, ft_nbrullen(1));
	TEST_ASSERT_EQUAL_INT8(20, ft_nbrullen(-1));
	TEST_ASSERT_EQUAL_INT8(1, ft_nbrullen(0));
	TEST_ASSERT_EQUAL_INT8(10, ft_nbrullen(INT_MAX));
	TEST_ASSERT_EQUAL_INT8(20, ft_nbrullen(INT_MIN));
	TEST_ASSERT_EQUAL_INT8(19, ft_nbrullen(LONG_MAX));
	TEST_ASSERT_EQUAL_INT8(20, ft_nbrullen(ULONG_MAX));
}

void test_ft_nbrflen(void)
{
	TEST_ASSERT_EQUAL_INT8(6, ft_nbrflen(123.0, 2));
	TEST_ASSERT_EQUAL_INT8(4, ft_nbrflen(1.0, 2));
}

void test_ft_nbrlflen(void)
{
	TEST_ASSERT_EQUAL_INT8(6, ft_nbrlflen(123.0L, 2));
	TEST_ASSERT_EQUAL_INT8(4, ft_nbrlflen(1.0L, 2));
}

void test_ft_nbrelen(void)
{
	TEST_ASSERT_EQUAL_INT8(8, ft_nbrelen(123.0, 2));
	TEST_ASSERT_EQUAL_INT8(8, ft_nbrelen(1.0, 2));
}

void test_ft_nbrellen(void)
{
	TEST_ASSERT_EQUAL_INT8(8, ft_nbrellen(123.0L, 2));
	TEST_ASSERT_EQUAL_INT8(8, ft_nbrellen(1.0L, 2));
}

void test_ft_octlen(void)
{
	TEST_ASSERT_EQUAL_INT64(1, ft_octlen(00));
	TEST_ASSERT_EQUAL_INT64(1, ft_octlen(07));
	TEST_ASSERT_EQUAL_INT64(2, ft_octlen(077));
	TEST_ASSERT_EQUAL_INT64(4, ft_octlen(07777));
	TEST_ASSERT_EQUAL_INT64(4, ft_octlen(01234));
	TEST_ASSERT_EQUAL_INT64(8, ft_octlen(077777777));
}

void test_ft_loctlen(void)
{
	TEST_ASSERT_EQUAL_INT64(1, ft_loctlen(00));
	TEST_ASSERT_EQUAL_INT64(1, ft_loctlen(07));
	TEST_ASSERT_EQUAL_INT64(2, ft_loctlen(077));
	TEST_ASSERT_EQUAL_INT64(4, ft_loctlen(07777));
	TEST_ASSERT_EQUAL_INT64(4, ft_loctlen(01234));
	TEST_ASSERT_EQUAL_INT64(8, ft_loctlen(077777777));
	TEST_ASSERT_EQUAL_INT64(21, ft_loctlen(0777777777777777777777));
}

void test_ft_pow(void)
{
	TEST_ASSERT_EQUAL_FLOAT(1337, ft_pow(1337, 1));
	TEST_ASSERT_EQUAL_FLOAT(1, ft_pow(1337, 0));
	TEST_ASSERT_EQUAL_FLOAT(4, ft_pow(2, 2));
	TEST_ASSERT_EQUAL_FLOAT(INT8_MAX, ft_pow(2, 7) - 1);
	TEST_ASSERT_EQUAL_FLOAT(UINT8_MAX, ft_pow(2, 8) - 1);
	TEST_ASSERT_EQUAL_FLOAT(INT16_MAX, ft_pow(2, 15) - 1);
	TEST_ASSERT_EQUAL_FLOAT(UINT16_MAX, ft_pow(2, 16) - 1);
	TEST_ASSERT_EQUAL_FLOAT(INT32_MAX, ft_pow(2, 31) - 1);
	TEST_ASSERT_EQUAL_FLOAT(UINT32_MAX, ft_pow(2, 32) - 1);
	TEST_ASSERT_EQUAL_FLOAT(INT64_MAX, ft_pow(2, 63) - 1);
	TEST_ASSERT_EQUAL_FLOAT(UINT64_MAX, ft_pow(2, 64) - 1);
}

void test_ft_skipdigits(void)
{
	TEST_ASSERT_EQUAL_INT64(3, ft_skipdigits("132adfas"));
	TEST_ASSERT_EQUAL_INT64(3, ft_skipdigits("132"));
	TEST_ASSERT_EQUAL_INT64(0, ft_skipdigits("abc132"));
	TEST_ASSERT_EQUAL_INT64(0, ft_skipdigits(""));
	TEST_ASSERT_EQUAL_INT64(0, ft_skipdigits("abc"));
}

void test_ft_strcat(void)
{
	char my_data[128];
	char sys_data[128];

	char const * part1 = "These ";
	char const * part2 = " strings are ";
	char const * part3 = "concatenated.";

	strcpy(my_data, part1);
	strcpy(sys_data, part1);
	strcat(my_data, part2);
	ft_strcat(sys_data, part2);
	strcat(my_data, part3);
	ft_strcat(sys_data, part3);
	TEST_ASSERT_EQUAL_STRING(sys_data, my_data);
}

void test_ft_strchr(void)
{
	char const * seed = "AbCREDFjlfa123";

	TEST_ASSERT_EQUAL_PTR(strchr(seed, 'C'), ft_strchr(seed, 'C'));
	TEST_ASSERT_EQUAL_PTR(strchr(seed, 'Q'), ft_strchr(seed, 'Q'));
	TEST_ASSERT_EQUAL_PTR(strchr(seed, '3'), ft_strchr(seed, '3'));
	TEST_ASSERT_EQUAL_PTR(strchr(seed, 'A'), ft_strchr(seed, 'A'));
	TEST_ASSERT_EQUAL_PTR(strchr(seed, '\0'), ft_strchr(seed, '\0'));
	TEST_ASSERT_EQUAL_PTR(strchr("", '\0'), ft_strchr("", '\0'));
	TEST_ASSERT_EQUAL_PTR(strchr("", 'Q'), ft_strchr("", 'Q'));
}

void test_ft_strclen(void)
{
	char const * seed = "AbCREDFjlfa123";

	TEST_ASSERT_EQUAL_INT64(strchr(seed, 'C') - seed, ft_strclen(seed, 'C'));
	TEST_ASSERT_EQUAL_INT64(strlen(seed), ft_strclen(seed, 'Q'));
	TEST_ASSERT_EQUAL_INT64(strchr(seed, '3') - seed, ft_strclen(seed, '3'));
	TEST_ASSERT_EQUAL_INT64(strchr(seed, 'A') - seed, ft_strclen(seed, 'A'));
	TEST_ASSERT_EQUAL_INT64(strchr(seed, '\0') - seed, ft_strclen(seed, '\0'));
	TEST_ASSERT_EQUAL_INT64(0, ft_strclen("", '\0'));
	TEST_ASSERT_EQUAL_INT64(0, ft_strclen("", 'Q'));
}

void test_ft_strclr(void)
{
	char str[] = "Hello Wolrd!";

	ft_strclr(str);
	TEST_ASSERT_EACH_EQUAL_INT8(0, str, sizeof(str));
}

void test_ft_strcmp(void)
{
	{
		char s1[] = "Hello Wolrd";
		char s2[] = "Hello Wolrd";

		TEST_ASSERT_EQUAL_INT8(0, ft_strcmp(s1, s2));
	}
	{
		char s1[] = "Hello\0Wolrd";
		char s2[] = "Hello\0Man";

		TEST_ASSERT_EQUAL_INT8(0, ft_strcmp(s1, s2));
	}
	{
		char s1[] = "Hello W0lrd";
		char s2[] = "Hello Wolrd";

		TEST_ASSERT_EQUAL_INT8('0' - 'o', ft_strcmp(s1, s2));
	}
	TEST_ASSERT_EQUAL_INT8(0, ft_strcmp("", ""));
}

void test_ft_strcpy(void)
{
	char my_data[32];
	char sys_data[32];

	{
		char const *s = "Hello Wolrd";
		TEST_ASSERT_EQUAL_STRING(strcpy(sys_data, s), ft_strcpy(my_data, s));
	}
	{
		char const *s = "Hello Wolrd, Man";
		TEST_ASSERT_EQUAL_STRING(strcpy(sys_data, s), ft_strcpy(my_data, s));
	}
	{
		char const *s = "Hey?";
		TEST_ASSERT_EQUAL_STRING(strcpy(sys_data, s), ft_strcpy(my_data, s));
	}
	TEST_ASSERT_EQUAL_STRING(strcpy(sys_data, ""), ft_strcpy(my_data, ""));
}

void test_ft_strequ(void)
{
	char empty_string[] = "";
	TEST_ASSERT_MESSAGE(ft_strequ(empty_string, empty_string) == 1, "Empty strings are equal");
	empty_string[0] = 'A';
	TEST_ASSERT_MESSAGE(ft_strequ(empty_string, empty_string) == 1, "Empty strings are equal");

	TEST_ASSERT_MESSAGE(ft_strequ("Hello World", "Hello World") == 1, "Strings are equal");
	TEST_ASSERT_MESSAGE(ft_strequ("Hello World", "Hello World!") == 0, "Strings are not equal");
	TEST_ASSERT_MESSAGE(ft_strequ("Hello World?", "Hello World!") == 0, "Strings are not equal");
}

void test_ft_strnequ(void)
{
	{
		char const s1[] = "Hello Wolrd";
		char const s2[] = "Hello W0lrd";
		TEST_ASSERT_MESSAGE(ft_strnequ(s1, s2, 7) == 1, "Till 7-th byte strings are equal");
		TEST_ASSERT_MESSAGE(ft_strnequ(s1, s2, sizeof(s2)) == 0, "Full strings are not equal");
	}
	{
		char const s1[] = "Hello World!";
		char const s2[] = "Hello World";
		TEST_ASSERT_MESSAGE(ft_strnequ(s1, s2, sizeof(s2) - 1) == 1, "Part till '!' are equal");
		TEST_ASSERT_MESSAGE(ft_strnequ(s1, s2, sizeof(s1) - 1) == 0, "Full strings are not equal");
		TEST_ASSERT_MESSAGE(ft_strnequ(s1, s2, sizeof(s1)) == 0, "Full strings are not equal");
	}
	char empty_string[] = "";
	TEST_ASSERT_MESSAGE(ft_strnequ(empty_string, empty_string, 1) == 1, "Empty strings are equal");
	empty_string[0] = 'A';
	TEST_ASSERT_MESSAGE(ft_strnequ(empty_string, empty_string, 1) == 1, "Empty strings are equal");
}

int main(int ac, char **argv)
{
	(void)ac;
	g_executable_path = dirname(argv[0]);

	UNITY_BEGIN();

	RUN_TEST(test_ft_abs);
	RUN_TEST(test_ft_atoi);
	RUN_TEST(test_ft_atoll);
	RUN_TEST(test_ft_atol_base);
	RUN_TEST(test_ft_bzero);
	RUN_TEST(test_ft_degtorad);

	/* Double Linked List Tests [START]*/
	RUN_TEST(test_ft_dlstnew);
	RUN_TEST(test_ft_dlstpush);
	RUN_TEST(test_ft_dlstpush_back);
	RUN_TEST(test_ft_dlstpop);
	RUN_TEST(test_ft_dlstpop_back);
	RUN_TEST(test_ft_dlstdelelem);
	RUN_TEST(test_ft_dlstclear);
	RUN_TEST(test_ft_dlstsize);
	/* Double Linked List Tests [END]*/

	RUN_TEST(test_ft_exp);
	RUN_TEST(test_ft_get_fractional);
	RUN_TEST(test_ft_get_next_line);
	RUN_TEST(test_ft_hexlen);
	RUN_TEST(test_ft_lhexlen);
	RUN_TEST(test_ft_isalnum);
	RUN_TEST(test_ft_isalpha);
	RUN_TEST(test_ft_isascii);
	RUN_TEST(test_ft_isdigit);
	RUN_TEST(test_ft_isprint);
	RUN_TEST(test_ft_itoa);

	/* Linked List Tests [START]*/
	RUN_TEST(test_ft_lstnew);
	RUN_TEST(test_ft_lstadd);
	RUN_TEST(test_ft_lstadd_back);
	RUN_TEST(test_ft_lstdel);
	RUN_TEST(test_ft_lstdelone);
	RUN_TEST(test_ft_lstiter);
	RUN_TEST(test_ft_lstmap);
	/* Linked List Tests [END]*/

	RUN_TEST(test_ft_memalloc);
	RUN_TEST(test_ft_memccpy);
	RUN_TEST(test_ft_memchr);
	RUN_TEST(test_ft_memcmp);
	RUN_TEST(test_ft_memcpy);
	RUN_TEST(test_ft_memdel);
	RUN_TEST(test_ft_memmove);
	RUN_TEST(test_ft_memset);
	RUN_TEST(test_ft_nbrblen);
	RUN_TEST(test_ft_nbrlen);
	RUN_TEST(test_ft_nbrllen);
	RUN_TEST(test_ft_nbrulen);
	RUN_TEST(test_ft_nbrullen);
	RUN_TEST(test_ft_nbrflen);
	RUN_TEST(test_ft_nbrlflen);
	RUN_TEST(test_ft_nbrelen);
	RUN_TEST(test_ft_nbrellen);
	RUN_TEST(test_ft_octlen);
	RUN_TEST(test_ft_loctlen);
	RUN_TEST(test_ft_pow);
	RUN_TEST(test_ft_skipdigits);
	RUN_TEST(test_ft_strcat);
	RUN_TEST(test_ft_strchr);
	RUN_TEST(test_ft_strclen);
	RUN_TEST(test_ft_strclr);
	RUN_TEST(test_ft_strcmp);
	RUN_TEST(test_ft_strcpy);
	RUN_TEST(test_ft_strequ);
	RUN_TEST(test_ft_strnequ);
	return (UNITY_END());
}
