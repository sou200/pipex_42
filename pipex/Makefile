NAME = pipex
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
CC = cc

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = pipex.c utils.c exec_utils.c free_utils.c file_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

%.o : %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	make -C $(LIBFT_DIR) $@
	$(RM) $(OBJS)
fclean : clean
	make -C $(LIBFT_DIR) $@
	$(RM) $(NAME)
re : fclean all
