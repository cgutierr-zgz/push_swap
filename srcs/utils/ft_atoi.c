/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:57:29 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/25 17:35:16 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	return_value(const char *str, t_push_swap *ps, long x, int isneg)
{
	if (*str != '\0')
		print_error(ps, "There should be no content after the number");
	if (x * isneg > INT_MAX || x * isneg < INT_MIN)
		print_error(ps, "Value is bigger or smaller than INT_MAX or INT_MIN");
	return (x * isneg);
}

int	ft_atoi(const char *str, t_push_swap *ps)
{
	long	x;
	int		isneg;

	x = 0;
	isneg = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		isneg *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '\0' || *str < '0' || *str > '9')
		print_error(ps, "Invalid value");
	while (*str >= '0' && *str <= '9')
	{
		x = x * 10 + (*str - '0');
		str++;
	}
	return (return_value(str, ps, x, isneg));
}
