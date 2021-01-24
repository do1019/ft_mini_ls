CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBS := ar rcs
NAME := ft_mini_ls
NAME_LIBFT := libft.a
LIBFT_DIR := libft/

SRCS := \
	ft_mini_ls.c \
	ft_mini_ls_list.c \
	ft_mini_ls_sort.c \

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)$(NAME_LIBFT)

clean:
	rm -f $(OBJS) $(LIBFT_DIR)*.o

fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)$(NAME_LIBFT)

re: fclean all
 
.PHONY: all bonus clean fclean re