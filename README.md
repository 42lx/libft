*This project has been created as part of the 42 curriculum by ohaponiu.*

## Description
Libft is a custom C library that reimplements several standard libc functions and includes additional utility functions for working with strings, files, and linked lists. The output is a static library `libft.a` that can be linked into other C projects.

### Notable Functions

#### ft_atoi
Accumulates down to avoid integer overflow in case of `INT_MIN`. It doesn't normally cause errors since most compilers wrap around value (e.g. `INT_MAX + 1` becomes `INT_MIN` which is exactly the behavior needed), but integer overflow is officially UB, so wraparound cannot be depended on (read [here](https://www.airs.com/blog/archives/120) why). Compile with `-ftrapv` to check for overflows.
#### ft_strlcat
`dst` length is computed with a custom `ft_strnlen` that stops at `dstsize` bytes rather than walking the full string. This mirrors the intent of `strlcat` itself. If `dst` is already longer than `dstsize`, the function should return `dstsize + ft_strlen(src)` without reading past the buffer (read [here](https://linux.die.net/man/3/strlcat) more).
#### ft_strtrim
`p2` is initialized to the null terminator via `ft_strchr(s, '\0')` instead of end of the string (one before `\0`). This is because subtracting 1 would cause undefined behavior on an empty string. The pre-decrement isn't needed anyway since `ft_strchr(set, '\0')` is always true, so the loop skips past it. In the empty string case, `ft_substr` receives `len = 1` where `slen = 0`, but its bounds check handles this gracefully and returns `""`.
#### ft_strjoin
`ft_memcpy` is called with `len2 + 1` for the second string to carry over its null terminator, avoiding a separate null-termination step.
#### ft_lst*
No check for `if (!lst)`, but `if (!*lst)` is checked sometimes. Why? That's because `lst = NULL` is invalid use of the function. Same way none of the libc functions do `NULL` checks on arguments, because it's responsibility of the caller to not provide invalid values. At the same time, `*lst = NULL` is a valid case of an empty linked list which the functions need to handle.
#### ft_lstmap
A temporary variable is used to store `content` in case `f` uses `malloc` (then `del` should `free` it). `tail` tracks the last node to append in O(1) instead of traversing the list with `ft_lstlast` on every iteration.

## Instructions

### Makefile
Command | Description
--|--
`make`, `make all` | build library
`make clean` |  remove object files
`make fclean` | remove object files and static library
`make re` | run `fclean` then `all`

### Use in a Project
1. Clone the repository into your project root.
2. In the C files that use the library, add `#include "libft.h"`.
3. Run `make -C libft` to build.
4. Compile with `cc your_prg.c -Ilibft -Llibft -lft`.

> **clangd:** add `-Ilibft` to `compile_flags.txt` so the LSP can resolve the header.

## Resources

### References

* `man` pages.
* Peer discussions.

### AI Usage Disclosure

LLMs were used during this project for the following purposes:

* Style guidelines for more idiomatic code.
* Parts of this readme.
