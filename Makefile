# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Name of the executable
TARGET = minishell

# Source files
SRCS = minishell.c

# Object files
OBJS = $(SRCS:.c=.o)

# Path to libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include directories
INCLUDES = -I$(LIBFT_DIR)

# Default target
all: $(TARGET)

# Link the object files and libft to create the executable
$(TARGET): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -L$(LIBFT_DIR) -lft

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