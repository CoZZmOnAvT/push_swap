/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stack_op.h                                                               */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/09 15:28:27 by phrytsenko                               */
/*   Updated: 2019/01/09 18:03:21 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_INCLUDE_STACK_OP_H_
# define CHECKER_INCLUDE_STACK_OP_H_

struct t_dlist;

int		sort_stack(t_dlist **main_stack);

t_dlist	*stack_from_array(int arr_size, char **arr);

#endif  // CHECKER_INCLUDE_STACK_OP_H_
