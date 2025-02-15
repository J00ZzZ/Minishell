# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Name of the executable
TARGET = minishell

# Source files
SRCS = minishell.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS)

# Clean up everything
fclean: clean
	rm -f $(TARGET)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re