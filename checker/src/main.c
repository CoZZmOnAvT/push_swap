/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/13 12:57:38 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <errors.h>
#include <stack_error_codes.h>

void	display_stacks(t_dlist *a, t_dlist *b)
{
	t_dlist *it_a;
	t_dlist *it_b;

	ft_printf("%10cA:|%10cB:|\n", ' ', ' ');
	it_a = a ? a->next : NULL;
	it_b = b ? b->next : NULL;
	while (it_a != a || it_b != b)
		if (it_a != a && it_b != b)
		{
			ft_printf("%12d|%12d|\n", *(int *)it_a->content, *(int *)it_b->content);
			it_a = it_a->next;
			it_b = it_b->next;
		}
		else if (it_a != a)
		{
			ft_printf("%12d|%12c|\n", *(int *)it_a->content, ' ');
			it_a = it_a->next;
		}
		else if (it_b != b)
		{
			ft_printf("%12c|%12d|\n", ' ', *(int *)it_b->content);
			it_b = it_b->next;
		}
}

int	sort_stack(t_dlist **main_stack)
{
	t_dlist *support_stack;
	char	*instruction;

	support_stack = NULL;
	while (ft_get_next_line(0, &instruction) > 0)
		if (!apply_instruction(main_stack, &support_stack, instruction, 0))
		{
			free(instruction);
			ft_dlstclear(&support_stack);
			return (INVALID_INSTRUCTION);
		}
		else
		{
			free(instruction);
			display_stacks(*main_stack, support_stack);
		}
	ft_dlstclear(&support_stack);
	return (stack_is_sorted(*main_stack, 1) ? 0 : NOT_SORTED);
}

int	main(int argc, char *argv[])
{
	int		err;
	t_dlist	*main_stack;

	if ((main_stack = stack_from_array(argc, argv)) == NULL)
		return (e_print(INVALID_STACK, "Error"));
	err = sort_stack(&main_stack);
	ft_dlstclear(&main_stack);
	if (err == NOT_SORTED)
		return (e_print(err, "KO"));
	else if (err)
		return (e_print(err, "Error"));
	ft_putendl("OK");
	return (0);
}
