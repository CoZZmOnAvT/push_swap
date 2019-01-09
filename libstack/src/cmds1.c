/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cmds1.c                                                                  */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/09 17:38:04 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "stack.h"

void stack_rrr(t_dlist **a, t_dlist **b)
{
    stack_rra(a, b);
    stack_rrb(a, b);
}

int apply_instruction(t_dlist **main_stack, t_dlist **support_stack,
						char const *instruction)
{
	char		*trimmed_instruction;
	uint		it;
	char const	*names[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	void		(*callbacks[])(t_dlist **, t_dlist **) = {
		&stack_sa, &stack_sb, &stack_ss, &stack_pa, &stack_pb,
		&stack_ra, &stack_rb, &stack_rr, &stack_rra, &stack_rrb, &stack_rrr,
	};

	trimmed_instruction = ft_strtrim(instruction);
	if (ft_strlen(trimmed_instruction) <= 0)
		return (1);
	it = -1;
	while (++it < sizeof(names) / sizeof(*names))
		if (ft_strequ(instruction, names[it]))
		{
			free(trimmed_instruction);
			callbacks[it](main_stack, support_stack);
			return (1);
		}
	free(trimmed_instruction);
	return (0);
}
