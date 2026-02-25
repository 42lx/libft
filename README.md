*This project has been created as part of the 42 curriculum by ohaponiu.*

## Description
**Libft** is a custom C library that reimplements several standard libc functions and includes additional utility functions for working with strings, files, and linked lists. The output is a static library `libft.a` that can be linked into other C projects.

### Notable functions

* `ft_atoi`. `unsigned int` is used to prevent integer overflow in case of `INT_MIN`. It doesn't normally cause errors since most compilers wrap around value (e.g. `INT_MAX + 1` becomes `INT_MIN` which is exactly what we want in this case), but officially integer overflow is UB and we cannot depend on wraparound (read [here](https://www.airs.com/blog/archives/120) why). Compile with `-ftrapv` to check for overflows. Additionally, in the digit loop, we check for overflows, which isn't required since, according to [man](https://man7.org/linux/man-pages/man3/atoi.3.html), `atoi` doesn't detect errors, however, it is always good to ensure extra safety.
* `ft_strlcat`. Instead of just calculating `dst_len = ft_strlen(dst)`, we have a custom loop which will calculate length or stop upon traversing `dst_size` bytes. While not required, this is done since the whole idea behind `strlcat` returning `dst_size + ft_strlen(src)` in this case is so that we don't run off the end of `dst` (read [here](https://linux.die.net/man/3/strlcat)).
* `ft_strrchr`. We have a `while (1)` loop with a `break` inside since otherwise, `size_t i` would underflow and cause infinite loop. `ft_strchr` also has a `while (1)` loop as it allows for a more concise style since we need to check for value of `\0` as well.
* `ft_strtrim`. We don't subtract 1 from length when assigning to end to prevent underflow in case length is 0. It's not required to subtract 1, since end = length will point at `\0`, which is fine for us, since `c = \0` always returns true for `ft_strchr`, so we'll just iterate over it.

## Instructions

### Makefile
Use `make` commands as usual (`all`, `clean`, `fclean`, `re`).

### Use in a project
```sh
cc -Wall -Wextra -Werror your_file.c -L. -lft
```
Make sure `libft.a` is in the same directory or adjust `-L` accordingly.

Include the header:
```c
#include "libft.h"
```

## Resources

### References

* `man` pages for libc.
* Piscine projects.
* Peer discussions.

### AI Usage Disclosure

LLMs were used during this project for the following purposes:

* Style guidelines for more idiomatic code.
