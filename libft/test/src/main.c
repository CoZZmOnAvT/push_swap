/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/02 16:17:55 by cozzmonavt                               */
/*   Updated: 2019/01/04 22:59:00 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unity.h>
#include <fcntl.h>
#include <libgen.h>
#include "libft.h"

#ifndef _G_BUFSIZ
# define _G_BUFSIZ 8192
#endif

char * g_stream_buffer;
int g_stream_save;

char * g_executable_path;

void capture_stream(FILE * stream)
{
	fflush(stream);
	g_stream_save = dup(fileno(stream));
	freopen("NUL", "a", stream);
	setvbuf(stream, g_stream_buffer, _IOFBF, _G_BUFSIZ);
}

void restore_stream(FILE * stream)
{
	freopen("NUL", "a", stream);
	dup2(g_stream_save, fileno(stream));
	setvbuf(stream, NULL, _IONBF, _G_BUFSIZ);
}

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

int main(int ac, char **argv)
{
	(void)ac;
	g_stream_buffer = malloc(_G_BUFSIZ + 1);
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
	return (UNITY_END());
}
