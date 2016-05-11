CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
EXEC_FILE = 2-print_permissions
C_FILES = 2-print_permissions.c print_char.c
OBJECTS	:= $(C_FILES:.c=.o)

$(EXEC_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECTS): $(C_FILES)

clean:
	-rm -f $(OBJECTS)
	-rm -f $(EXEC_FILE)
