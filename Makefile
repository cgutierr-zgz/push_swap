# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/09 14:13:26 by cgutierr          #+#    #+#              #
#    Updated: 2021/05/20 19:32:32 by cgutierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DAY		=	$(shell date +'%d/%m/%Y %H:%M')

NAME	=	libft.a

SRCS			=	srcs/push_swap.c \
					srcs/print.c \
					srcs/lists/ft_stackadd_back.c \
					srcs/lists/ft_stackadd_front.c \
					srcs/lists/ft_stackclear.c \
					srcs/lists/ft_stackdelone.c \
					srcs/lists/ft_stackiter.c \
					srcs/lists/ft_stacklast.c \
					srcs/lists/ft_stackmap.c \
					srcs/lists/ft_stacknew.c \
					srcs/lists/ft_stacksize.c \
					srcs/utils/ft_atoi.c

HEADER			=	libft.h
					
OBJS			=	$(SRCS:.c=.o)

CC				=	gcc

FLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f

all:			$(NAME)

$(NAME):
				@echo $(YELLOW)Compiling libft ... $(RESET)
				$(CC) $(FLAGS) -I $(HEADER) -c $(SRCS)
				ar -rc $(NAME) $(OBJS)
				ranlib $(NAME)

clean:
				@echo $(YELLOW)Cleaning ... $(RED)
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

BLACK		:="\033[0;30m"
RED			:="\033[0;31m"
GREEN		:="\033[0;32m"
BROWN		:="\033[0;33m"
BLUE		:="\033[0;34m"
PURPLE		:="\033[0;35m"
CYAN		:="\033[0;36m"
LIGHT_GRAY	:="\033[0;37m"
DARK_GRAY	:="\033[1;30m"
LIGHT_RED	:="\033[1;31m"
LIGHT_GREEN	:="\033[1;32m"
YELLOW		:="\033[1;33m"
LIGHT_BLUE	:="\033[1;34m"
LIGHT_PURPLE:="\033[1;35m"
LIGHT_CYAN	:="\033[1;36m"
WHITE		:="\033[1;37m"
RESET		:="\x1b[0m"

git:
				@echo $(YELLOW)Status:$(RESET)
				@git status || true 
				@echo $(YELLOW)GIT add ... $(RESET)
				@git add . || true 
				@echo $(YELLOW)GIT commit ... $(RESET)
				@git commit -m "$(DAY)" || true 
				@echo $(YELLOW)GIT push ... $(RESET)
				@git push -u origin master || true 

norminette:
				@echo $(YELLOW)Norminette...
				@echo $(GREEN)
				@norminette $(SRCS) $(HEADER) | grep "OK" || true 
				@echo $(RED)
				@norminette $(SRCS) $(HEADER) ./libft/*.c ./libft/*.h | grep 'Error!\|line:' || true
				
.PHONY:			all clean fclean re
