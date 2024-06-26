NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

EXISTING_LIB_DIR = srcs/libft
EXISTING_LIB = $(EXISTING_LIB_DIR)/libft.a
SRC_DIR = srcs

SRCS = \
	srcs/printf_utils1.c srcs/printf_utils2.c \
	srcs/printf_utils3.c srcs/ft_printf.c \



OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(EXISTING_LIB)
	cp $(EXISTING_LIB) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(EXISTING_LIB):
	make -C $(EXISTING_LIB_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(EXISTING_LIB)

re: fclean all

.PHONY: all clean fclean re