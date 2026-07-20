*This activity has been created as part of the 42 curriculum by ttertrai*

**Description**

recode Libc functioins printf
new: variadic functions (va_list, va_start, va_arg, va_end).
A variadic function is a function that can take any number of arguments. When you call it, all the extra arguments are stored in memory one after the other. You use va_start to point to the beginning of those arguments, then each call to va_arg reads the next one and moves the pointer forward. You have to tell va_arg what type to read, otherwise it won't know how many bytes to grab. When you're done, va_end cleans everything up.

**Instructions**

Here are the requirements:
• Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository.
• Your header file must be named ft_printf.h and must contain the prototype of your
ft_printf() function.

You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.


**Resources**
https://linux.die.net/man/3/stdarg
https://www.youtube.com/watch?v=Hb2m7htiKWM&t=60s
https://learn.microsoft.com/fr-fr/cpp/cpp/integer-limits?view=msvc-170
https://www.ibm.com/docs/fr/i/7.5.0?topic=functions-printf-print-formatted-characters
https://www.agnosticdev.com/blog-entry/c/testing-and-converting-hexadecimal-data-c
https://www.geeksforgeeks.org/c/variadic-functions-in-c/
testeur: https://github.com/Tripouille/printfTester/blob/master/tests/p_test.cpp
