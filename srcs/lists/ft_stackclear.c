/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:34:52 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 19:26:55 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_stackclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*ptr;

	if (lst && del && *lst)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			ft_stackdelone(*lst, del);
			*lst = ptr;
		}
	}
}
