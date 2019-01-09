/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   e_print.c                                                                */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/09 15:59:11 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int e_print(int err_code, char const *err_msg)
{
	char	*complete_msg;

	complete_msg = ft_strjoin(err_msg, "\n");
    ft_putstr_fd(complete_msg, STDERR_FILENO);
	free(complete_msg);
	return (err_code);
}
