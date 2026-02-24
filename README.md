*This project has been created as part of the 42 curriculum by ohaponiu.*

## Description
**Libft** is a C library with reimplementations of some libc functions, and some additional functions. 

### Notable functions

* `ft_atoi`. `unsigned int` is used to prevent integer overflow in case of `INT_MIN`. It doesn't normally cause errors since most compilers wrap around value (e.g. `INT_MAX + 1` becomes `INT_MIN` which is exactly what we want in this case), but officially integer overflow is UB and we cannot depend on wraparound (read [here](https://www.airs.com/blog/archives/120) why). Compile with `-ftrapv` to check for overflows. Additionally, in the digit loop, we check for overflows, which isn't required since, according to [man](https://man7.org/linux/man-pages/man3/atoi.3.html), `atoi` doesn't detect errors, however, it is always good to ensure extra safety.
* `ft_strlcat`. Instead of just calculating `dst_len = ft_strlen(dst)`, we have a custom loop which will calculate length or stop upon traversing `dstsize` bytes. While not required, this is done since the whole idea behind `strlcat` returning `dstsize + ft_strlen(src)` in this case is so that we don't run off the end of `dst` (read [here](https://linux.die.net/man/3/strlcat)).
* `ft_strrchr`. We have a `while (1)` loop with a `break` inside since otherwise, `size_t i` would underflow and cause infinite loop.

## Instructions
Use makefile as usual.

## Resources

* `man`
* Piscine projects
* [libftTester](https://github.com/Tripouille/libftTester)

### AI Usage Disclosure

LLMs were used during this project for following purposes:

* Style guidelines for more idiomatic code

## Author

* **ohaponiu**
* **ohaponiuk**
