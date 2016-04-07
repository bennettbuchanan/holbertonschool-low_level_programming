IDIR = ./inc
CFLAGS=-I$(IDIR)
DEPS = holbertonschool.h
FILES =  0-absolute 0-contact_strings 0-first_digit 0-lowercase 0-print_number 0-uppercase_string 1-cap_string 1-nconcat_strings 1-power 1-swap_int 1-uppercase 2-print_array 2-square_root 2-str_len 2-string_copy 3-is_prime_number 3-print_string 3-string_ncopy 4-positive_or_not 4-reverse_string 4-strings_compare 5-reverse_array 5-string_to_integer print_char
OUTSOURCES =  ./src/0-absolute.o ./src/0-contact_strings.o ./src/0-first_digit.o ./src/0-lowercase.o ./src/0-print_number.o ./src/0-uppercase_string.o ./src/1-cap_string.o ./src/1-nconcat_strings.o ./src/1-power.o ./src/1-swap_int.o ./src/1-uppercase.o ./src/2-print_array.o ./src/2-square_root.o ./src/2-str_len.o ./src/2-string_copy.o ./src/3-is_prime_number.o ./src/3-print_string.o ./src/3-string_ncopy.o ./src/4-positive_or_not.o ./src/4-reverse_string.o ./src/4-strings_compare.o ./src/5-reverse_array.o ./src/5-string_to_integer.o ./src/print_char.o
SOURCES = ./src/$(FILES)

all: libholberton.a clean re

.PHONY: clean re

$(SOURCES).o: $(SOURCES).c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

libholberton.a: $(OUTSOURCES)
	ar -rc libholberton.a $(OUTSOURCES)

clean:
	rm $(OUTSOURCES)

re: clean all
