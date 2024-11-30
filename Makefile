NAME = minishell

CC = gcc

RM = rm -f

SRC = main.c \

CFLAGS = -Wall -Werror -Wextra

OPTION = -I ./

OBJS = $(SRC:.c=.o)

LIBFT_PATH = ./libft/

LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) $(OPTION) -o $(NAME)
	@echo "\033[92m--Minishell Compiled--\033[0m"


$(LIBFT):
	@make -C $(LIBFT_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean 
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo "\033[92m--Mhilo Cleaned--\033[0m"

re: fclean all

.PHONY: all clean fclean re