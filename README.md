# ft_printf

## Score 110/100

## About
This project aims to send formatted output to stdout exactly like the C library function printf does.
Allowed functions to use: write, malloc, free, exit, the functions of man 3 stdarg.

## Requirements
Manage
* conversions: s, S, p, d, D, i, o, O, u, U, x, X, c & C
* %%
* flags #0-+ and space
* flags hh, h, l, ll, j, & z.
* minimum field-width
* precision


## Installation
```bash
git clone https://github.com/arinaspektor/ft_printf.git ftprintf
cd ftprintf
make
```

## Usage
To test you should create file with main function, include ft_printf.h and use just like printf.

### Example
main.c file includes the following code

```c
#include "ft_printf.h"

int main(void) {
    ft_printf("%.2f\n", 0.999);
    ft_printf("hello, %s!\n", "world");
    ft_printf("%-20s", "this is a test");
    ft_printf("%+d\n", 6);
    ft_printf("\xE2\x98\xA0"); // Unicode symbols as bonus

    return 0;
}
```

## Compiling
```bash
gcc -o main main.c libftprintf.a -I includes
./main
```
