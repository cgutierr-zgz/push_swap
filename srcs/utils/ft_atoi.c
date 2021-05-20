/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:57:29 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 20:27:40 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
static void error()
{
	printf("Error\n");
	// TODO: FIXME: TODO:!!!!!y clear a las pilas limpiar pila [a]
	exit(1);
}

int	ft_atoi(const char *str)
{
	int	x;
	int	isnegative;

	x = 0;
	isnegative = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
	{
		isnegative *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if(*str == '\0')
		error();
	while (*str >= '0' && *str <= '9')
	{
		x = x * 10 + (*str - '0');
		str++;
	}
	return (x * isnegative);
}
