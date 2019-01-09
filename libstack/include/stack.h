/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stack.h                                                                  */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/09 15:28:27 by phrytsenko                               */
/*   Updated: 2019/01/09 17:37:36 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTACK_INCLUDE_STACK_H_
# define LIBSTACK_INCLUDE_STACK_H_

int apply_instruction(t_dlist **main_stack, t_dlist **support_stack,
                        char const *instruction);

void stack_sa(t_dlist **a, t_dlist **b);
void stack_sb(t_dlist **a, t_dlist **b);
void stack_ss(t_dlist **a, t_dlist **b);

void stack_pa(t_dlist **a, t_dlist **b);
void stack_pb(t_dlist **a, t_dlist **b);

void stack_ra(t_dlist **a, t_dlist **b);
void stack_rb(t_dlist **a, t_dlist **b);
void stack_rr(t_dlist **a, t_dlist **b);

void stack_rra(t_dlist **a, t_dlist **b);
void stack_rrb(t_dlist **a, t_dlist **b);
void stack_rrr(t_dlist **a, t_dlist **b);

#endif  // LIBSTACK_INCLUDE_STACK_H_
