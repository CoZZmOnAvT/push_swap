/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cmds2.c                                                                  */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/13 12:50:26 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void stack_sa(t_dlist **a, t_dlist **b, int verbose)
{
	int	tmp;

	FT_IGNORE(b);
	if (*a == NULL || (*a)->next->next == *a)
		return ;
	tmp = *(int *)(*a)->next->content;
	*(int *)(*a)->next->content = *(int *)(*a)->next->next->content;
	*(int *)(*a)->next->next->content = tmp;
	verbose ? ft_putendl("sa") : 0;
}

void stack_sb(t_dlist **a, t_dlist **b, int verbose)
{
	int	tmp;

	FT_IGNORE(a);
	if (*b == NULL || (*b)->next->next == *b)
		return ;
	tmp = *(int *)(*b)->next->content;
	*(int *)(*b)->next->content = *(int *)(*b)->next->next->content;
	*(int *)(*b)->next->next->content = tmp;
	verbose ? ft_putendl("sb") : 0;
}

void stack_ss(t_dlist **a, t_dlist **b, int verbose)
{
	stack_sa(a, b, verbose);
	stack_sb(a, b, verbose);
	verbose ? ft_putendl("ss") : 0;
}

void stack_pa(t_dlist **a, t_dlist **b, int verbose)
{
	if (*b == NULL || (*b)->next == *b)
		return ;
	ft_dlstpush(a, ft_dlstnew((*b)->next->content, (*b)->next->content_size));
	ft_dlstpop(*b);
	verbose ? ft_putendl("pa") : 0;
}

void stack_pb(t_dlist **a, t_dlist **b, int verbose)
{
	if (*a == NULL || (*a)->next == *a)
		return ;
	ft_dlstpush(b, ft_dlstnew((*a)->next->content, (*a)->next->content_size));
	ft_dlstpop(*a);
	verbose ? ft_putendl("pb") : 0;
}
