/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sort.c                                                                   */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/13 13:19:09 by cozzmonavt                               */
/*   Updated: 2019/01/15 21:14:56 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stack.h>

t_dlist *partition(t_dlist *lo, t_dlist *hi)
{
	t_dlist *pivot = hi;
	t_dlist *it = lo;

	for (t_dlist *j = lo; j->index < hi->index; j = j->next)
	{
		if (*(int *)j->content < *(int *)pivot->content)
		{
			if (it->index != j->index)
			{
				ft_printf("SWAP stack[%zd]=%d with stack[%zd]=%d\n", it->index, *(int *)it->content, j->index, *(int *)j->content);
				ft_dlstswap_content(it, j);
			}
			it = it->next;
		}
	}
	if (it->index != hi->index)
	{
		ft_printf("SWAP stack[%zd]=%d with stack[%zd]=%d\n", it->index, *(int *)it->content, hi->index, *(int *)pivot->content);
		ft_dlstswap_content(it, pivot);
	}
	return (it);
}

void quicksort(t_dlist *lo, t_dlist *hi)
{
	if (lo->index < hi->index)
	{
		t_dlist *p = partition(lo, hi);

		if (p->index != -1 && p->prev->index != -1)
			quicksort(lo, p->prev);
		if (p->index != -1 && p->next->index != -1)
			quicksort(p->next, hi);
	}
}
