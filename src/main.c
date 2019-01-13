/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/13 14:07:58 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <stack_error_codes.h>
#include <errors.h>
#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_dlist *main_stack;
    t_dlist *support_stack;

    support_stack = NULL;
    if ((main_stack = stack_from_array(argc, argv)) == NULL)
        return (e_print(INVALID_STACK, "Error"));
    sort(&main_stack, &support_stack);
    return (0);
}
