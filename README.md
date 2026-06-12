*This project has been created as part of the 42 curriculum by tjulya-c*

## Description

**ft_printf** is a custom C library that reimplements the standard C library `printf` function. 

The goal of this project is to deepen understanding of fundamental C programming concepts, including:
- Variadic functions and argument lists
- Modular code structure using helper functions
- Formatted output and type conversions

## Instructions

To use this library in your projects, you need to compile the source files and link them. Generally, this is done via a `Makefile` that compiles the `.c` files into a static library named `libftprintf.a`.

### Compilation

To compile the library:

```bash
make
```

This will generate `libftprintf.a` in the root directory.

### Cleanup

- Remove object files: `make clean`
- Remove object files and library: `make fclean`
- Recompile everything: `make re`

### Usage in your projects

Include the header in your C files:

```c
#include "ft_printf.h"
```

Compile with the library:

```bash
cc main.c -L. -lftprintf -o my_program
```

## Supported Conversions

| Specifier | Description |
|--------|-----------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a `void *` pointer argument in hexadecimal format |
| `%d` | Prints a base 10 signed integer |
| `%i` | Prints a base 10 signed integer |
| `%u` | Prints a base 10 unsigned integer |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format |
| `%%` | Prints a literal percentage sign |

## Technical Choices

- **Variadic Functions**: Implemented using `va_list`, `va_start`, `va_arg`, and `va_end` to handle an unknown number of arguments dynamically.
- **Modularity**: Separated logic into specific files like `ft_putnbr.c`, `ft_puthexa.c`, and `ft_putchar.c`.
- **Standard Compliance**: Returns the total number of characters printed, matching original `printf` behavior.
## Resources

### Documentation

- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [man 3 stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [42 Norminette Documentation](https://github.com/42School/norminette)

### AI Usage

For this project, AI was used in the following ways:
- Code review to identify edge cases
- Debugging off-by-one errors
- Assistance with README structure

## Author

Thaís Fuzita - tjulya-c