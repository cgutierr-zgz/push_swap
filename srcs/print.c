/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:05:43 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 19:24:36 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
static void	clear_content(t_list *lst)
{
	free(lst->content);
}
*/

void	print_error(t_stack *a, t_stack *b)
{
	printf("Error\n");
	//ft_lstclear(a, clear_content);
	//ft_lstclear(b, clear_content);
	exit(1);
}
