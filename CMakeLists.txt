cmake_minimum_required(VERSION 3.9)
project(Corewar)

set(CMAKE_CXX_STANDARD 11)

add_executable(Corewar
        VirtualMachine/src/commands/commands.c
        VirtualMachine/src/commands/ft_get_int.c
        VirtualMachine/src/commands/parsing_commands.c
        VirtualMachine/src/commands/ft_and.c
        VirtualMachine/src/commands/ft_fork.c
        VirtualMachine/src/commands/ft_ldi.c
        VirtualMachine/src/commands/ft_lldi.c
        VirtualMachine/src/commands/ft_lld.c
        VirtualMachine/src/commands/ft_load.c
        VirtualMachine/src/commands/ft_or.c
        VirtualMachine/src/commands/ft_st.c
        VirtualMachine/src/commands/ft_sti_dir.c
        VirtualMachine/src/commands/ft_sti.c
        VirtualMachine/src/commands/ft_xor.c
        VirtualMachine/src/main_part/choose_winner.c
        VirtualMachine/src/main_part/corewar.c
        VirtualMachine/src/main_part/end_game.c
        VirtualMachine/src/main_part/main.c
        VirtualMachine/src/main_part/manage_bot_list.c
        VirtualMachine/src/main_part/manage_pc_list.c
        VirtualMachine/src/main_part/manage_pc_list2.c
        VirtualMachine/src/main_part/manage_map.c
        VirtualMachine/src/parsing/get_bot_info.c
        VirtualMachine/src/parsing/manage_arguments.c
        VirtualMachine/src/parsing/parse_bot.c
        VirtualMachine/src/parsing/parse_bot_id.c
        VirtualMachine/src/parsing/parsing.c
        VirtualMachine/src/visualization/display_map.c
        VirtualMachine/src/visualization/print_border.c
        VirtualMachine/src/visualization/print_right_window.c
        VirtualMachine/src/commands/ft_and_dir_ind.c
        VirtualMachine/src/commands/ft_or_dir_ind.c
        VirtualMachine/src/commands/ft_xor_dir_ind.c
        VirtualMachine/src/parsing/extra_flag.c
        )

find_package(Curses REQUIRED)

target_link_libraries(Corewar ${CURSES_LIBRARIES})
include_directories(${CURSES_INCLUDE_DIR})
add_library(libft STATIC IMPORTED)
set_property(TARGET libft PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(Corewar libft)