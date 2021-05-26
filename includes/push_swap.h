/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:11:48 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/26 13:04:31 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // NULL
# include <stdlib.h> // malloc, free
# include <stdio.h> // printf
# include <limits.h> // MAX_INT

# define RESET				"\x1b[0m"
# define WHITE				"\x1b[1m"
# define W_B_WHITE			"\x1b[47m"
# define W_B_CYAN			"\x1b[46m"
# define W_B_PURPLE			"\x1b[45m"
# define W_B_BLUE			"\x1b[44m"
# define W_B_YELLOW			"\x1b[43m"
# define W_B_GREEN			"\x1b[42m"
# define W_B_RED			"\x1b[41m"
# define WH_B_CLEAR			"\x1b[40m"
# define INVISIBLE			"\x1b[8m"
# define WHITE_BOX			"\x1b[7m"
# define WHITE_SUB			"\x1b[4m"
# define WHITE_CURS			"\x1b[3m"
# define GRAY				"\x1b[2m"
# define BLACK				"\x1b[30m"
# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE				"\x1b[34m"
# define PURPLE				"\x1b[35m"
# define CYAN				"\x1b[36m"

// TODO: Maybe implementar doblemente enlazadas
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	// Main stacks
	t_stack	*a;
	t_stack	*b;

	/* Error managing */
	char	*argv;			// Current argv we are checking
	int		check_repeat;	// Checks the values
	int		num_movements;	// Comprobar la cantidad de movimientos que llevo
}	t_push_swap;

// Main functions
void	print_error(t_push_swap *ps, char *msg);
void	print_stacks(t_push_swap *ps);
void	start_push_swap(int argc, char **argv, t_push_swap *ps);

// Util functions
int		ft_atoi(const char *str, t_push_swap *ps);
char	**ft_split(char const *s, char c);

// Stack rules
void	rule_sx(t_push_swap *ps, char identifier);
void	rule_px(t_push_swap *ps, char identifier);
void	rule_rx_rrx(t_push_swap *ps, char identifier, int operation);

// Stack functions
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **alst, t_stack *new);
void	ft_stackclear(t_stack **lst, void (*del)(void *));
void	ft_stackdelone(t_stack *lst);
void	ft_stackiter(t_stack *lst, void (*f)(int));
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacknew(int num);
int		ft_stacksize(t_stack *lst);

#endif
