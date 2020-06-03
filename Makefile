# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 13:06:51 by nabboufe          #+#    #+#              #
#    Updated: 2019/07/15 14:00:38 by nabboufe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC_0		=		push_swap

EXEC_1		=		checker

LIBFT_A		=		libft.a

INCLUDES	=		-Iinclude

SRCS_0		=		srcs/push_swap.c			\
					srcs/ft_utilities.c			\
					srcs/check_insert.c			\
					srcs/ft_is_sort.c			\
					srcs/ft_pivot.c				\
					srcs/instr_pile_a.c			\
					srcs/instr_pile_b.c			\
					srcs/instr_pile_ab.c		\
					srcs/n_instructions.c		\
					srcs/print_lists.c			\
					srcs/q_sort.c

SRCS_1		=		srcs/checker.c				\
					srcs/ft_utilities.c			\
					srcs/check_insert.c			\
					srcs/ft_is_sort.c			\
					srcs/instr_pile_a.c			\
					srcs/instr_pile_b.c			\
					srcs/print_lists.c			\
					srcs/instr_pile_ab.c

OBJ_LIB 	= 		$(LIBFT:.c=.o)

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

OBJ_0		=		$(SRCS_0:.c=.o)

OBJ_1		=		$(SRCS_1:.c=.o)

DECHET		=		*.dSYM

all			:		$(LIBFT_A) $(EXEC_0) $(EXEC_1)
	@echo "push_swap and checker compilation are done !"

$(LIBFT_A)	:		
	@make -C libft/ all clean >/dev/null
	@echo "libft compilation is done !\n"
	@mv libft/libft.a .

$(EXEC_0)	:		$(OBJ_0) $(LIBFT_A)
	$(CC) $(CFLAGS) $(LIBFT_A) $(OBJ_0) $(INCLUDES) -o $(EXEC_0)
	@rm -rf $(DECHET)

$(EXEC_1)	:		$(OBJ_1) $(LIBFT_A)
	$(CC) $(CFLAGS) $(LIBFT_A) $(OBJ_1) $(INCLUDES) -o $(EXEC_1)
	@rm -rf $(DECHET)
	@echo ""

clean		:
	@rm -rf $(OBJ_0) $(OBJ_1) $(DECHET)
	@echo "clean completed !"

fclean		:		clean
	@rm -rf $(EXEC_0) $(EXEC_1) $(LIBFT_A) $(DECHET) &>/dev/null
	@echo "fclean completed !\n"

re			:		fclean all

.PHONY		:		fclean all
