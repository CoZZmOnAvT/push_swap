/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cmds1.c                                                                  */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/13 12:50:48 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "stack.h"

void stack_rrr(t_dlist **a, t_dlist **b, int verbose)
{
    stack_rra(a, b, verbose);
    stack_rrb(a, b, verbose);
    verbose ? ft_putendl("rrr") : 0;
}

int apply_instruction(t_dlist **main_stack, t_dlist **support_stack,
						char const *instruction, int verbose)
{
	char		*trimmed_instruction;
	uint		it;
	char const	*names[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	void		(*callbacks[])(t_dlist **, t_dlist **, int) = {
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
			callbacks[it](main_stack, support_stack, verbose);
			return (1);
		}
	free(trimmed_instruction);
	return (0);
}
