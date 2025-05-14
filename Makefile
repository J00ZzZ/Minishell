# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Name of the executable
TARGET = minishell

# Source files
SRCS = main.c \
	 	src/execution/parse_input.c\
		src/execution/execute_command.c\
		src/execution/execute_builtin.c\
		src/execution/is_builtin.c\
		src/builtin/builtin_echo.c \
		src/builtin/builtin_cd.c \
		src/builtin/builtin_cd_utils.c \
		src/builtin/builtin_pwd.c \
		src/builtin/builtin_exit.c \
		src/builtin/builtin_env.c \
		src/builtin/builtin_export.c \
		src/builtin/builtin_unset.c \
		src/parsing/env_signal.c \
		src/parsing/env_cpy.c \
		src/utils/utils1.c \
		src/tokenization/token_utils.c \
		src/tokenization/token_utils2.c \
		src/tokenization/tokenize.c \
		src/tokenization/tokentype.c \
		src/tokenization/ischar.c \
		src/tokenization/free_token.c \
		src/tokenization/ft_valid.c \
		src/tokenization/heredoc.c \
		src/utils/transit_utils.c \
		test.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Path to libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include directoriese
INCLUDES = -I$(LIBFT_DIR) -Iparsing -Iexecution -I/opt/homebrew/opt/readline/include

# Linker flags for readline
LDFLAGS = -L/opt/homebrew/opt/readline/lib
LDLIBS = -lreadline -lft

# Default target
all: $(TARGET)

# Link the object files, libft, and readline to create the executable
$(TARGET): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -L$(LIBFT_DIR) $(LDFLAGS) $(LDLIBS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean up build files
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

# Clean up everything
fclean: clean
	rm -f $(TARGET)
	make -C $(LIBFT_DIR) fclean

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re