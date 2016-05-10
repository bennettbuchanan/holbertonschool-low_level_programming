CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
EXEC_FILE = 3-cat

all: $(EXEC_FILE)

$(EXEC_FILE): 3-cat.c print_char.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(EXEC_FILE)
