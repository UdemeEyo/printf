#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int main(void);
int handle_string(va_list args);
int handle_char(va_list args);

#endif
