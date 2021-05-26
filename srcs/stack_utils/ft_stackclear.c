/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:34:52 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/26 14:42:25 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_stackclear(t_stack **lst)
{
	t_stack	*ptr;

	if (lst && *lst)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			ft_stackdelone(*lst);
			*lst = ptr;
		}
	}
}
