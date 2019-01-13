/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   find_stack_lowest.c                                                      */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/13 13:29:20 by cozzmonavt                               */
/*   Updated: 2019/01/13 13:40:02 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

t_slowest   find_stack_lowest(t_dlist *stack)
{
	size_t		index;
	t_slowest	min;
	t_dlist		*it;

	index = 0;
	ft_memset(&min, 0, sizeof(min));
	it = stack;
	while (it && (it = it->next) != stack && ++index)
		if (!min.node)
			min.node = it;
		else if (*(int *)it->content < *(int *)min.node->content)
		{
			min.node = it;
			min.index = index - 1;
		}
	min.size = index;
	return (min);
}
