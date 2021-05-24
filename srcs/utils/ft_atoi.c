/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:57:29 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/24 19:32:29 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_atoi(const char *str, t_push_swap *ps)
{
	long	x;
	int		isnegative;

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
		// Comparar tal con tal y si eso error
	if(x * isnegative > INT_MAX || x * isnegative < INT_MIN)
		print_error(ps, "Value is bigger or smaller than INT_MAX or INT_MIN");
	return (x * isnegative);
}
