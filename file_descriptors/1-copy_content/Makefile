CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
EXEC_FILE = 1-copy_content
C_FILES = 1-copy_content.c
OBJECTS	:= $(C_FILES:.c=.o)

$(EXEC_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECTS): $(C_FILES)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f $(EXEC_FILE)
