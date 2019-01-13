/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cmds3.c                                                                  */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/13 12:50:16 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "stack.h"

void stack_ra(t_dlist **a, t_dlist **b, int verbose)
{
    FT_IGNORE(b);
    if (*a == NULL || (*a)->next == *a)
        return ;
    ft_dlstpush_back(a, ft_dlstnew((*a)->next->content, (*a)->next->content_size));
    ft_dlstpop(*a);
    verbose ? ft_putendl("ra") : 0;
}

void stack_rb(t_dlist **a, t_dlist **b, int verbose)
{
    FT_IGNORE(a);
    if (*b == NULL || (*b)->next == *b)
        return ;
    ft_dlstpush_back(b, ft_dlstnew((*b)->next->content, (*b)->next->content_size));
    ft_dlstpop(*b);
    verbose ? ft_putendl("rb") : 0;
}

void stack_rr(t_dlist **a, t_dlist **b, int verbose)
{
    stack_ra(a, b, verbose);
    stack_rb(a, b, verbose);
    verbose ? ft_putendl("rr") : 0;
}

void stack_rra(t_dlist **a, t_dlist **b, int verbose)
{
    FT_IGNORE(b);
    if (*a == NULL || (*a)->next == *a)
        return ;
    ft_dlstpush(a, ft_dlstnew((*a)->prev->content, (*a)->prev->content_size));
    ft_dlstpop_back(*a);
    verbose ? ft_putendl("rra") : 0;
}

void stack_rrb(t_dlist **a, t_dlist **b, int verbose)
{
    FT_IGNORE(a);
    if (*b == NULL || (*b)->next == *b)
        return ;
    ft_dlstpush(b, ft_dlstnew((*b)->prev->content, (*b)->prev->content_size));
    ft_dlstpop_back(*b);
    verbose ? ft_putendl("rrb") : 0;
}
