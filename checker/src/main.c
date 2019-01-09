/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/09 18:03:15 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <errors.h>
#include "error_codes.h"
#include "stack_op.h"

int main(int argc, char *argv[])
{
	int		err;
	t_dlist	*main_stack;

	if ((main_stack = stack_from_array(argc, argv)) == NULL)
		return (e_print(INVALID_STACK, "Error"));
	err = sort_stack(&main_stack);
	ft_dlstclear(&main_stack);
	if (err == NOT_SORTED)
		return (e_print(err, "KO"));
	else if (err)
		return (e_print(err, "Error"));
	ft_putendl("OK");
	return (0);
}
