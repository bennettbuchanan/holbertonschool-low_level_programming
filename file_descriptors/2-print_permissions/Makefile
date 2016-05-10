CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
EXEC_FILE = 2-print_permissions

all: $(EXEC_FILE)

$(EXEC_FILE): 2-print_permissions.c print_char.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(EXEC_FILE)
