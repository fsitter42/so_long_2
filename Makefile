NAME = so_long

SOURCE = 	check_and_find.c \
			check_path.c \
			game.c \
			gamehook.c \
			input_and_all.c \
			mapstuff.c \
			moves.c \
			so_long.c

HEADER = so_long.h

CFLAGS = -Wall -Wextra -Werror -g -Iminilibx-linux

MINIFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

OBJECTS = $(SOURCE:.c=.o)

LIBFT = libft/libft.a

MINILIB = minilibx-linux/libmlx.a

CC = cc

RM = rm -f


%.o: %.c ${HEADER}
	${CC} ${CFLAGS} $ -c $< -o $@
${NAME}: ${OBJECTS}
	${CC} ${OBJECTS} libft/libft.a -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o ${NAME}
clean:	
	${RM} ${OBJECTS}
fclean:	clean
		${RM} ${NAME}
re:		fclean all
all:	${NAME}
make:	make all

.PHONY: clean fclean re all
