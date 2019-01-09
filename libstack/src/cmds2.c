/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cmds2.c                                                                  */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/09 17:18:01 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void stack_sa(t_dlist **a, t_dlist **b)
{
	int	tmp;

	FT_IGNORE(b);
	if (*a == NULL || (*a)->next->next == *a)
		return ;
	tmp = *(int *)(*a)->next->content;
	*(int *)(*a)->next->content = *(int *)(*a)->next->next->content;
	*(int *)(*a)->next->next->content = tmp;
}

void stack_sb(t_dlist **a, t_dlist **b)
{
	int	tmp;

	FT_IGNORE(a);
	if (*b == NULL || (*b)->next->next == *b)
		return ;
	tmp = *(int *)(*b)->next->content;
	*(int *)(*b)->next->content = *(int *)(*b)->next->next->content;
	*(int *)(*b)->next->next->content = tmp;
}

void stack_ss(t_dlist **a, t_dlist **b)
{
	stack_sa(a, b);
	stack_sb(a, b);
}

void stack_pa(t_dlist **a, t_dlist **b)
{
	if (*b == NULL || (*b)->next == *b)
		return ;
	ft_dlstpush(a, ft_dlstnew((*b)->next->content, (*b)->next->content_size));
	ft_dlstpop(*b);
}

void stack_pb(t_dlist **a, t_dlist **b)
{
	if (*a == NULL || (*a)->next == *a)
		return ;
	ft_dlstpush(b, ft_dlstnew((*a)->next->content, (*a)->next->content_size));
	ft_dlstpop(*a);
}
