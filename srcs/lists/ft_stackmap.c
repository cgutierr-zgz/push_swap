/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:28:17 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 19:28:20 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*ft_lstmap(t_stack *ls, void *(*f)(void *), void (*dl)(void *))
{
	t_stack	*new_lst;
	t_stack	*new_elem;

	if (!ls && !f)
		return (NULL);
	new_lst = NULL;
	while (ls)
	{
		new_elem = ft_stacknew(f(ls->num));
		if (!(new_elem))
		{
			ft_stackclear(&new_lst, dl);
			return (NULL);
		}
		ft_stackadd_back(&new_lst, new_elem);
		ls = ls->next;
	}
	return (new_lst);
}
