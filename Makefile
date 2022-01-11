SRCS = get_next_line.c get_next_line_utils.c

SRCS_B = $(SRCS:.c=_bonus.c) 

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

HEADER = get_next_line.h

FLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42
CC = cc
RM = rm -f

all:	$(OBJS)
	$(CC) $(FLAGS) $(OBJS)
	./a.out


.c.o: ${HEADER}
	$(CC) $(FLAGS) -c $< -o $@ -I ${HEADER}

bonus:
	@make OBJS="$(OBJS_B)" all

clean:
	$(RM) $(OBJS) $(OBJS_B) 

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus