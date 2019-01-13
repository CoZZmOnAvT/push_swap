/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sort.c                                                                   */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/13 13:19:09 by cozzmonavt                               */
/*   Updated: 2019/01/13 14:51:26 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stack.h>

static void    repeate_instruction(t_dlist **a, t_dlist **b,
                            char const * instruction, size_t n)
{
    while (n--)
        apply_instruction(a, b, instruction, 1);
}

void	sort(t_dlist **a, t_dlist **b)
{
	t_slowest	min;

	if ((*a)->next->next != *a &&
		*(int *)(*a)->next->content > *(int *)(*a)->next->next->content)
		stack_sa(a, b, 1);
	if (stack_is_sorted(*a, 1))
		return (repeate_instruction(a, b, "pa", ft_dlstsize(*b)));
	min = find_stack_lowest(*a);
	if (min.index > min.size - min.index)
		repeate_instruction(a, b, "rra", min.size - min.index);
	else
		repeate_instruction(a, b, "ra", min.index);
	if (stack_is_sorted(*a, 1))
		return (repeate_instruction(a, b, "pa", ft_dlstsize(*b)));
	stack_pb(a, b, 1);
	sort(a, b);
}
