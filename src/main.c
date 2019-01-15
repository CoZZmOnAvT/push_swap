/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/15 21:05:29 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <stack_error_codes.h>
#include <errors.h>
#include "push_swap.h"

void    display_stacks(t_dlist *a, t_dlist *b)
{
    t_dlist *it_a;
    t_dlist *it_b;

    ft_printf("%10cA:|%10cB:|\n", ' ', ' ');
    it_a = a ? a->next : NULL;
    it_b = b ? b->next : NULL;
    while (it_a != a || it_b != b)
        if (it_a != a && it_b != b)
        {
            ft_printf("%12d|%12d|\n", *(int *)it_a->content, *(int *)it_b->content);
            it_a = it_a->next;
            it_b = it_b->next;
        }
        else if (it_a != a)
        {
            ft_printf("%12d|%12c|\n", *(int *)it_a->content, ' ');
            it_a = it_a->next;
        }
        else if (it_b != b)
        {
            ft_printf("%12c|%12d|\n", ' ', *(int *)it_b->content);
            it_b = it_b->next;
        }
}

int main(int argc, char *argv[])
{
    t_dlist *main_stack;
    // t_dlist *support_stack;

    // support_stack = NULL;
    if (argc <= 1)
        return (e_print(NO_INSTRUCTIONS, get_usage(argv[0])));
    else if ((main_stack = stack_from_array(argc, argv)) == NULL)
        return (e_print(INVALID_STACK, "Error"));
    ft_dlstupdate_indexes(main_stack);
    quicksort(main_stack->next, main_stack->prev);
    display_stacks(main_stack, NULL);
    if (stack_is_sorted(main_stack, 1))
        ft_printf("{green}SORTED!{nc}\n");
    else
        ft_printf("{red}NOT SORTED!{nc}\n");
    return (0);
}
