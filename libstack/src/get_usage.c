/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   get_usage.c                                                              */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/15 15:11:30 by phrytsenko                               */
/*   Updated: 2019/01/15 15:12:50 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char const  *get_usage(char const *program_name)
{
    static char u[512];

    ft_bzero(u, sizeof(u));
    ft_strlcat(u, program_name, sizeof(u));
    ft_strlcat(u, ": Invalid number of instructions\n\nUsage: \n  ", sizeof(u));
    ft_strlcat(u, program_name, sizeof(u));
    ft_strlcat(u, " {SET_OF_NUMBERS_IN_RANGE [-2147483648..2147483647]}"
                , sizeof(u));
    return (u);
}
