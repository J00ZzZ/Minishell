NAME = libft.a
CC = gcc
AR = ar -rc
RM = rm -f
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isalnum.c \
			ft_isdigit.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			get_next_line.c ft_printf.c printfnumbers.c printfwords.c get_next_line_utils.c \
			ft_strjoin_free.c ft_strtok.c ft_arrfree.c ft_arrdup.c ft_strtok_r.c ft_strjoin_three.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
			
CFLAGS = -Wall -Wextra -Werror
OPTION = -I ./

OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS:.c=.o)

all: $(NAME) clear 

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

.c.o:
	@$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

clean: clear 
	@$(RM) $(OBJS) $(BOBJS)

fclean: clean clear1 
	@$(RM) $(NAME)

bonus: $(OBJS) $(BOBJS) clear 
	@$(AR) $(NAME) $(OBJS) $(BOBJS)

re: fclean all clear2 catR

RESET := \033[0m
BLUE := \033[0;34m
clear:
	clear
clear1:
	clear
clear2:
	clear