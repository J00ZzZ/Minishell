# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Name of the executable
TARGET = minishell

# Source files
SRCS = main.c \
	   execution/parse_input.c\
	   execution/execute_command.c\
	   execution/execute_builtin.c\
	   builtin/builtin_echo.c \
	#    buildin/builtin_cd.c \
	#    buildin/builtin_pwd.c \
	#    buildin/builtin_export.c \
	#    buildin/builtin_unset.c \
	#    buildin/builtin_env.c \
	#    buildin/builtin_exit.c \

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