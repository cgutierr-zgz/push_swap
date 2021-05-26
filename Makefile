# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/09 14:13:26 by cgutierr          #+#    #+#              #
#    Updated: 2021/05/26 18:56:27 by cgutierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DAY				=	$(shell date +'%d/%m/%Y %H:%M')

NAME			=	push_swap

SRCS			=	srcs/push_swap.c \
					srcs/print.c \
					srcs/start_sorting.c \
					srcs/check_order.c \
					srcs/stack_utils/ft_stackadd_back.c \
					srcs/stack_utils/ft_stackadd_front.c \
					srcs/stack_utils/ft_stackclear.c \
					srcs/stack_utils/ft_stackdelone.c \
					srcs/stack_utils/ft_stackiter.c \
					srcs/stack_utils/ft_stacklast.c \
					srcs/stack_utils/ft_stacknew.c \
					srcs/stack_utils/ft_stacksize.c \
					srcs/utils/ft_atoi.c \
					srcs/utils/ft_split.c \
					srcs/stack_rules/rule_sx.c \
					srcs/stack_rules/rule_px.c \
					srcs/stack_rules/rule_rx_rrx.c

HEADER			=	includes/push_swap.h
					
OBJS			=	$(SRCS:.c=.o)

CC				=	gcc

FLAGS			=	-Wall -Werror -Wextra -O3#-g3 -fsanitize=address

RM				=	rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo $(YELLOW)Compiling push_swap ... $(RESET)
				$(CC) ${FLAGS} ${OBJS} -I $(HEADER) -o ${NAME}

clean:
				@echo $(YELLOW)Cleaning ... $(RED)
				$(RM) $(OBJS)

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

# ARG=$(seq -s ' ' 0 1000 | sort -R | tail -n 5)
ARG				=	$(shell seq 0 1000 | sort -R | tail -n 20)

exe:			$(NAME)
				./push_swap $(ARG)

check:			$(NAME)
				./push_swap $(ARG) | ./checker_Mac $(ARG)

# 582 937 46 538 | ./checker_Mac 377 585 746 224

# VALGRIND
#         --leak-check=full \ Each individual leak will be shown in detail
#         --show-leak-kinds=all \ Show all of "definite, indirect, possible, reachable" leak kinds in the "full" report.
#         --track-origins=yes \ Favor useful output over speed. This tracks the origins of uninitialized values, which could be very useful for memory errors. Consider turning off if Valgrind is unacceptably slow.
#         --verbose \ Can tell you about unusual behavior of your program. Repeat for more verbosity.
#         --log-file=valgrind-out.txt \ Write to a file. Useful when output exceeds terminal space.
#         ./executable exampleParam1
# @valgrind --leak-check=full --track-origins=yes --log-file=./resources/info/valgrind-out.txt ./cub3D resources/maps/map01.cub --save || true

valgrind:		$(NAME)
				valgrind --leak-check=full --track-origins=yes ./push_swap $(ARG)

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
				@norminette $(SRCS) $(HEADER) | grep 'Error!\|line:' || true
			
.PHONY:			all clean fclean re
