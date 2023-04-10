NAME = pipex
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
CC = cc

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = pipex_bonus.c utils_bonus.c exec_utils_bonus.c free_utils_bonus.c file_utils_bonus.c
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
