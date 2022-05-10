NAME		=	so_long
SRCS		=	./srcs/so_long.c ./srcs/utils.c ./srcs/get_next_line.c \
				./srcs/line_checkers.c ./srcs/map_utils.c ./srcs/game.c

CC			=	@gcc
MLXFLAGS	= 	-framework OpenGL -framework AppKit
-- CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf


OBJS		=	$(SRCS:.c=.o)
LIBFT_DIR	=	Libft
LIBFT		=	${LIBFT_DIR}/libft.a
LIBMLX_DIR	=	mlx
LIBMLX		=	${LIBMLX_DIR}/libmlx.a

COMP		=	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(LIBMLX) $(MLXFLAGS) -o $(NAME)

$(NAME):	$(OBJS)
		@echo "---------   Compiling   -----------"
		@MAKE -sC ./Libft
		@MAKE -sC ./mlx
		@ar -rcs so_long.a $(OBJS)
		$(COMP)
		@echo "--------------DONE!!---------------"

all:		${NAME}

clean:
		@echo "-------      Cleaning       -------"
		@make -s -C $(LIBFT_DIR) clean
		@echo "-------      Cleaning       -------"
		@$(RM) $(OBJS)
		@echo "--------------DONE!!---------------"

fclean:	clean
		@echo "-------      Cleaning       -------"
		@make -s -C $(LIBFT_DIR) fclean
		@echo "-------      Cleaning       -------"
		@$(RM) $(NAME)
		@echo "--------------DONE!!---------------"

re:		fclean all

.PHONY:	all fclean clean re