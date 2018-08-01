NAME = corewar

CC = gcc

FLAGS = -Wall -Wextra -Werror 

RM = rm -f

SRC = src/main_part/main.c src/parsing/manage_arguments.c src/parsing/parsing.c \
	src/main_part/manage_bot_list.c src/main_part/manage_pc_list.c src/parsing/parse_bot.c \
	src/parsing/parse_bot_id.c src/visualization/display_map.c src/parsing/get_bot_info.c \
	src/commands/parsing_commands.c src/commands/ft_get_int.c src/main_part/corewar.c src/commands/commands.c \
	src/main_part/manage_map.c src/main_part/end_game.c src/main_part/manage_pc_list2.c src/main_part/choose_winner.c \
	src/visualization/print_border.c src/visualization/print_right_window.c \
	src/commands/ft_and.c src/commands/ft_fork.c src/commands/ft_ldi.c src/commands/ft_lld.c \
	src/commands/ft_lldi.c src/commands/ft_load.c src/commands/ft_or.c src/commands/ft_st.c \
	src/commands/ft_sti_dir.c src/commands/ft_sti.c src/commands/ft_xor.c \
	src/commands/ft_xor_dir_ind.c src/commands/ft_or_dir_ind.c src/commands/ft_and_dir_ind.c \
	src/parsing/extra_flag.c

LIB_DIR = ../libft/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) all
	$(CC) $(FLAGS) $(OBJ) -o $@ -L$(LIB_DIR) -lft -lncurses
	@echo "corewar done."

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all
