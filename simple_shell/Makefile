CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
EXEC_FILE = shell
C_FILES = main.c print_char.c print_env.c concat_strings.c free_grid.c str_len.c grid_size.c print_prompt.c str_cmp.c int_to_string.c print_string.c find_path.c
OBJECTS	:= $(C_FILES:.c=.o)

$(EXEC_FILE): $(OBJECTS) libshell/libshell.a
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECTS): $(C_FILES)

clean:
	-rm -f $(OBJECTS)
	-rm -f $(EXEC_FILE)
