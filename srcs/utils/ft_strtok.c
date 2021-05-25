/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:57:29 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/25 19:06:06 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
/*
"SAOSAO\0SA\012" " "
sooaskkop 12 12 1 a a 
" " -> ' ' <- strchr " \n"


static char *str *1 \0
*/

char *ft_strtok(char *s, const char *delim)
{
	char *spanp;
	int c;
	int sc;
	char *tok;
	static char *last;

	if (s == NULL && (s = last) == NULL)
		return NULL;
cont:
	c = *s++;
	spanp = (char *)delim;
	while ((sc = *spanp++) != 0)
	{
		if (c == sc)
			goto cont;
	}
	if (c == 0)
	{
		last = NULL;
		return (NULL);
	}
	tok = s - 1;
	while (1)
	{
		c = *s++;
		spanp = (char *)delim;
		if ((sc = *spanp++) == c)
		{
			if (c == 0)
				s = NULL;
			else
				s[-1] = 0;
			last = s;
			return (tok);
		}
		while (sc != 0)
		{
			if ((sc = *spanp++) == c)
			{
				if (c == 0)
					s = NULL;
				else
					s[-1] = 0;
				last = s;
				return (tok);
			}
		}
	}
}
/*
char *ft_strtok(char *s, const char *delim)
{
	register char *spanp;
	register int c, sc;
	char *tok;
	static char *last;

	if (s == NULL && (s = last) == NULL)
		return (NULL);

cont:
	c = *s++;
	for (spanp = (char *)delim; (sc = *spanp++) != 0;)
	{
		if (c == sc)
			goto cont;
	}

	if (c == 0)
	{ 
		last = NULL;
		return (NULL);
	}
	tok = s - 1;

	for (;;)
	{
		c = *s++;
		spanp = (char *)delim;
		do
		{
			if ((sc = *spanp++) == c)
			{
				if (c == 0)
					s = NULL;
				else
					s[-1] = 0;
				last = s;
				return (tok);
			}
		} while (sc != 0);
	}
}
*/