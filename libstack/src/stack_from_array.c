/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stack_from_array.c                                                       */
/*                                                                            */
/*   By: cozzmonavt                                                           */
/*                                                                            */
/*   Created: 2019/01/13 12:33:57 by cozzmonavt                               */
/*   Updated: 2019/01/13 14:35:29 by cozzmonavt                               */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static size_t   arg_is_a_num(char const *arg)
{
    int     sign;
    size_t  len;

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

static int itarate_sub_arr(t_dlist **ret, t_dlist *sub_arr)
{
    t_dlist *it;
    int     temp_num;

    it = sub_arr;
    while (it && (it = it->prev) != sub_arr)
    {
        temp_num = ft_atoi(it->content);
        if (arg_is_a_num(it->content) != ft_strlen(it->content)
            || value_present_in_stack(*ret, temp_num)) {
            ft_dlstclear(&sub_arr);
            return (0);
        }
        ft_dlstpush_back(ret, ft_dlstnew(&temp_num, sizeof(temp_num)));
    }
    ft_dlstclear(&sub_arr);
    return (1);
}

t_dlist     *stack_from_array(int arr_size, char **arr)
{
    t_dlist *ret;
    int     it;

    ret = NULL;
    it = 0;
    while (++it < arr_size)
        if (!itarate_sub_arr(&ret, ft_strsplit_dlst(arr[it], ' ')))
        {
            ft_dlstclear(&ret);
            return (NULL);
        }
    return (ret);
}
