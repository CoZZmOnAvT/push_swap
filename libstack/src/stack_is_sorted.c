/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stack_is_sorted.c                                                        */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/13 12:40:19 by cozzmonavt                               */
/*   Updated: 2019/01/13 12:40:39 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int     stack_is_sorted(t_dlist *stack, int asc)
{
    t_dlist *it;

    if (stack->next->next == stack)
        return (1);
    it = stack;
    while ((it = it->next) != stack && it->next != stack)
        if (asc && *(int *)it->content > *(int *)it->next->content)
            return (0);
        else if (!asc && *(int *)it->content < *(int *)it->next->content)
            return (0);
    return (1);
}
