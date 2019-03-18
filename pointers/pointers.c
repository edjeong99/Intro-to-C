#include <stdio.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    while (*y != '\0'){
        x = y;
        x++;
        y++;
    }
    x++;
    *x = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    while(*str != "\0"){
        if(*str == c){
            return str
        }
        str++;
       
    }
     return &"\0";
}


/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    char *found_char;
    char *current_haystack;

    *found_char = find_char(haystack, *needle);

    while(*found_char != "\0"){
        current_haystack = found_char;
        while(*needle != "\0"){
            if (*found_char != *needle){
                break;
            }
            else{
                current_haystack++;
                needle++;
            }
            needle++;
        }
        if (*needle == "\0"){
           return current_haystack;
        }
        found_char = find_char(current_haystack, *needle);
    }

    
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
