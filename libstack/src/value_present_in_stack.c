/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   value_present_in_stack.c                                                 */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/13 12:36:26 by cozzmonavt                               */
/*   Updated: 2019/01/13 12:38:21 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlist	*value_present_in_stack(t_dlist *stack, int val)
{
	t_dlist *it;

	it = stack;
	while (it && (it = it->next) != stack)
		if (*(int *)it->content == val)
			return (it);
	return (0);
}
