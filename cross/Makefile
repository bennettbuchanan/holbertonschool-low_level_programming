CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -Wno-format -c
C_FILES = main.c handlers.c print_char.c str_to_int.c
OBJECTS	= $(C_FILES:.c=.o)

$(OBJECTS): $(C_FILES)
	$(CC) $(CFLAGS) $(C_FILES)

clean:
	rm -f $(OBJECTS)

re: clean all
