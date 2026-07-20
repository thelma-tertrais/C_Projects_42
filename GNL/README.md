*This activity has been created as part of the 42 curriculum by ttertrai*

## Description

get_next_line is a function that returns a line read from a file
descriptor. It requires the function read (<fcntl.h>).

New concepts: static variables, read function, buffer, free, timeout


## Instructions

Repeated calls (e.g., using a loop) to your get_next_line() function should let you read
the text file pointed to by the file descriptor, one line at a time.
• Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
• Make sure that your function works as expected both when reading a file and when reading
from the standard input.
• Please note that the returned line should include the terminating \n character, except if
the end of file was reached and does not end with a \n character.
• Your header file get_next_line.h must at least contain the prototype of the get_next_line()
function.
• Add all the helper functions you need in the get_next_line_utils.c file



## Documentations et ressources

https://unstop.com/blog/static-variable-in-c \
https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/#what-is-a-file-descriptor \
https://www.educative.io/answers/read-data-from-a-file-using-read-in-c \
https://www.geeksforgeeks.org/c/free-function-in-c-library-with-examples/

Claude AI helped to understand how to handle timeouts

