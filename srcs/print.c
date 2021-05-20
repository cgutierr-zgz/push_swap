/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:05:43 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 21:42:09 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(t_stack *a, t_stack *b, char *msg)
{
	printf("Error\n");
	if (1)
		printf("\t%s\n", msg);
	ft_stackclear(&a, free);
	ft_stackclear(&b, free);
	exit(1);
}
