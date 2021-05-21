/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:57:29 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 21:40:17 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_atoi(const char *str, t_push_swap *ps)
{
	int	x;
	int	isnegative;

	x = 0;
	isnegative = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		isnegative *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '\0' || *str < '0' || *str > '9')
		print_error(ps, "Single \"-\"/\"+\" must be followed by a number");	
	while (*str >= '0' && *str <= '9')
	{
		x = x * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		print_error(ps, "There should be no content after the number");
	return (x * isnegative);
	// FIXME: Check if 00001 returns 1
}
