SRCS	= srcs/so_long.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/check_valid_map.c srcs/parse.c srcs/map.c srcs/move.c srcs/draw.c srcs/utils.c

NAME = so_long

all:	${NAME}

${NAME}:
	gcc -Wall -Wextra -Werror -Lmlx -lmlx -Linc -framework OpenGL -framework AppKit ${SRCS} -o so_long

clean:
	rm -f so_long

fclean:	clean

re:	fclean all