/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:05:36 by pgritsen          #+#    #+#             */
/*   Updated: 2018/01/09 17:35:58 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstpop_back(t_dlist *dlst)
{
	t_dlist *del;

	if (!dlst)
		return ;
	del = dlst->prev;
	ft_dlstdelelem(&del);
}
