CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
EXEC_FILE = 1-copy_content

all: $(EXEC_FILE)

$(EXEC_FILE): 1-copy_content.c print_char.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(EXEC_FILE)
