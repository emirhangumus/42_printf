NAME = libftprintf.a
INCLUDE		= include/
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

SRC_FILES = ft_printf.c ft_printf_utils.c ft_printf_adress.c ft_puthex.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

EXE = ft_printf

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "Compiled $< successfully!"

clean:
	@$(RM) $(OBJ)
	@make clean -C $(LIBFT)
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo "Cleaned executable files"

re: fclean all

p: all
	@$(CC) $(CFLAGS) main.c -I $(INCLUDE) $(NAME) -o $(EXE)
	@echo "Executable file created"

.PHONY: all clean fclean re