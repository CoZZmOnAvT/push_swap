/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stack.c                                                                  */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/02 15:45:07 by cozzmonavt                               */
/*   Updated: 2019/01/09 18:15:09 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stack.h>
#include "error_codes.h"

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

int		value_present_in_stack(t_dlist *stack, int val)
{
	t_dlist	*it;

	it = stack;
	while (it && (it = it->next) != stack)
		if (*(int *)it->content == val)
			return (1);
	return (0);
}

int		stack_is_sorted(t_dlist *stack)
{
	t_dlist *it;

	if (stack->next->next == stack)
		return (1);
	it = stack;
	while ((it = it->next) != stack && it->next != stack)
		if (*(int *)it->content > *(int *)it->next->content)
			return (0);
	return (1);
}

int			sort_stack(t_dlist **main_stack)
{
	t_dlist *support_stack;
	char	*instruction;

	support_stack = NULL;
	while (ft_get_next_line(0, &instruction) > 0)
		if (!apply_instruction(main_stack, &support_stack, instruction))
		{
			free(instruction);
			ft_dlstclear(&support_stack);
			return (INVALID_INSTRUCTION);
		}
		else
			free(instruction);
	ft_dlstclear(&support_stack);
	return (stack_is_sorted(*main_stack) ? 0 : NOT_SORTED);
}

static size_t	arg_is_a_num(char const *arg)
{
	int sign;
	size_t	len;

	sign = 0;
	len = 0;
	while (arg[len])
	{
		if ((arg[len] == '+' || arg[len] == '-') && sign++)
			return (-1);
		else if (arg[len] != '+' && arg[len] != '-' && !ft_isdigit(arg[len]))
			return (-1);
		len++;
	}
	return (len);
}

t_dlist		*stack_from_array(int arr_size, char **arr)
{
	t_dlist	*ret;
	int		it;
	int		temp_num;

	ret = NULL;
	it = 0;
	while (++it < arr_size)
	{
		temp_num = ft_atoi(arr[it]);
		if (arg_is_a_num(arr[it]) != ft_strlen(arr[it])
			|| value_present_in_stack(ret, temp_num)) {
			ft_dlstclear(&ret);
			return (NULL);
		}
		ft_dlstpush_back(&ret, ft_dlstnew(&temp_num, sizeof(temp_num)));
	}
	return (ret);
}
