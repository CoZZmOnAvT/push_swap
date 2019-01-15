/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stack.h                                                                  */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/09 15:28:27 by phrytsenko                               */
/*   Updated: 2019/01/15 15:12:00 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTACK_INCLUDE_STACK_H_
# define LIBSTACK_INCLUDE_STACK_H_

# include <libft.h>

typedef struct  s_slowest
{
    size_t  index;
    size_t  size;
    t_dlist *node;
}               t_slowest;

int apply_instruction(t_dlist **main_stack, t_dlist **support_stack,
						char const *instruction, int verbose);

void stack_sa(t_dlist **a, t_dlist **b, int verbose);
void stack_sb(t_dlist **a, t_dlist **b, int verbose);
void stack_ss(t_dlist **a, t_dlist **b, int verbose);

void stack_pa(t_dlist **a, t_dlist **b, int verbose);
void stack_pb(t_dlist **a, t_dlist **b, int verbose);

void stack_ra(t_dlist **a, t_dlist **b, int verbose);
void stack_rb(t_dlist **a, t_dlist **b, int verbose);
void stack_rr(t_dlist **a, t_dlist **b, int verbose);

void stack_rra(t_dlist **a, t_dlist **b, int verbose);
void stack_rrb(t_dlist **a, t_dlist **b, int verbose);
void stack_rrr(t_dlist **a, t_dlist **b, int verbose);

t_dlist     *stack_from_array(int arr_size, char **arr);

t_dlist	    *value_present_in_stack(t_dlist *stack, int val);

int         stack_is_sorted(t_dlist *stack, int asc);

t_slowest   find_stack_lowest(t_dlist *stack);

char const  *get_usage(char const *program_name);

#endif  // LIBSTACK_INCLUDE_STACK_H_
