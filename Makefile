NAME		=	so_long
SRCS		=	./srcs/so_long.c ./srcs/utils.c ./srcs/get_next_line.c \
				./srcs/line_checkers.c ./srcs/map_utils.c

CC			=	@gcc
-- CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf


OBJS		=	$(SRCS:.c=.o)
LIBFT_DIR	=	libft/
LIBFT		=	${LIBFT_DIR}libft.a

$(NAME):	$(LIBFT) $(OBJS)
		@echo "---------   Compiling   ----------"
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
		@echo "--------------DONE!!--------------"

$(LIBFT):
		@echo "---------   Compiling   ----------"
		@make -s -C $(LIBFT_DIR)
		@echo "--------------DONE!!--------------"

all:		${NAME}

clean:
		@echo "-------      Cleaning       -------"
		@make -s -C $(LIBFT_DIR) clean
		@echo "-------      Cleaning       -------"
		@$(RM) $(OBJS)
		@echo "--------------DONE!!--------------"

fclean:	clean
		@echo "-------      Cleaning       -------"
		@make -s -C $(LIBFT_DIR) fclean
		@echo "-------      Cleaning       -------"
		@$(RM) $(NAME)
		@echo "--------------DONE!!--------------"

re:		fclean all

.PHONY:	all fclean clean re