NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc
RM = rm -f
FILES = ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr \
		ft_memcmp ft_strlen ft_strlcpy ft_strlcat ft_strchr \
		ft_strrchr ft_strnstr ft_strncmp ft_atoi ft_isalpha \
		ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper \
		ft_tolower ft_calloc ft_strdup ft_substr ft_strjoin \
		ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd \
		ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_striteri ft_lstnew \
	  	ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone \
	  	ft_lstclear ft_lstiter ft_lstmap \
		get_next_line_bonus get_next_line_utils_bonus\
		ft_printf ft_printf_util ft_hexas \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


.c.o:
	@$(CC) $(CFLAGS) -c $@ -o $<

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "\033[92m--Libft Compiled--\033[0m"

bonus: $(OBJS_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[92m--Libft Cleaned--\033[0m"

re: fclean all

.PHONY: all clean fclean re