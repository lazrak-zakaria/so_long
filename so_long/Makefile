NAME = so_long
CC = cc 
CFLAGS = -Wall -Werror -Wextra

OBJS = check_map_path.o game_utils.o game.o get_lines.o libft.o libft2.o map.o so_long.o

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -l mlx  -framework OpenGL -framework Appkit -o ${NAME}

clean :
	rm -f ${OBJS}
fclean : clean
	rm -f ${NAME}
re : fclean all
.PHONY : clean all fclean re