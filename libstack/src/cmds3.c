/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cmds3.c                                                                  */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/09 17:37:16 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "stack.h"

void stack_ra(t_dlist **a, t_dlist **b)
{
    FT_IGNORE(b);
    if (*a == NULL || (*a)->next == *a)
        return ;
    ft_dlstpush_back(a, ft_dlstnew((*a)->next->content, (*a)->next->content_size));
    ft_dlstpop(*a);
}

void stack_rb(t_dlist **a, t_dlist **b)
{
    FT_IGNORE(a);
    if (*b == NULL || (*b)->next == *b)
        return ;
    ft_dlstpush_back(b, ft_dlstnew((*b)->next->content, (*b)->next->content_size));
    ft_dlstpop(*b);
}

void stack_rr(t_dlist **a, t_dlist **b)
{
    stack_ra(a, b);
    stack_rb(a, b);
}

void stack_rra(t_dlist **a, t_dlist **b)
{
    FT_IGNORE(b);
    if (*a == NULL || (*a)->next == *a)
        return ;
    ft_dlstpush(a, ft_dlstnew((*a)->prev->content, (*a)->prev->content_size));
    ft_dlstpop_back(*a);
}

void stack_rrb(t_dlist **a, t_dlist **b)
{
    FT_IGNORE(a);
    if (*b == NULL || (*b)->next == *b)
        return ;
    ft_dlstpush(b, ft_dlstnew((*b)->prev->content, (*b)->prev->content_size));
    ft_dlstpop_back(*b);
}
