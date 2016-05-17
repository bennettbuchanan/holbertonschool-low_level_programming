#ifndef _LIBSHELL_H_
#define _LIBSHELL_H_

char **string_split(const char *str, char separator);
char *read_line(const int fd);

#endif
