CC=gcc
CFLAGS= -Wall -Werror -Wextra -pedantic -Wno-format -c
C_FILES = printf.c print_hex.c handlers.c additional_handlers.c print_handlers.c
OBJECTS	:= $(C_FILES:.c=.o)
LIB=libprintf.a

all: libprintf.a

$(OBJECTS): $(C_FILES)
	$(CC) $(CFLAGS) $(C_FILES)

libprintf.a: $(OBJECTS)
	ar -rc libprintf.a $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f $(LIB)

re: clean all
