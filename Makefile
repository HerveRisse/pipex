NAME		= pipex

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./
SRCS		= pipex.c \
		  pipex_init.c \
		  pipex_utils.c \
		  pipex_cmd.c \
		  pipex_cmd_utils.c \
		  pipex_exec.c \
		  pipex_split_utils.c \
		  pipex_str_utils1.c \
		  pipex_str_utils2.c

OBJ_DIR		= obj/
OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
