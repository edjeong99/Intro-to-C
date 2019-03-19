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
        *x = *y;
        x++;
        y++;
    }
   
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
   
    while(*str ){
      
        if(*str == c){
            return str;
        }
        str++;
       
    }
  
     return NULL;
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
    char *current_needle;

    found_char = find_char(haystack, *needle);

    while(*found_char){
        current_haystack = found_char;
        current_needle = needle;
        while(*current_needle ){
            
            if (*current_haystack != *current_needle){
                break;
            }
            else{
                current_haystack++;
                current_needle++;

             }
            if (*current_needle == '\0'){ 
            return found_char;
            }
            else if(*current_haystack == '\0'){
                return NULL;
            }
        }

        found_char = find_char(found_char+1, *needle);
    
   
    }
     return NULL;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'E');
    // char *found_string = find_string("world", "or");
  char *string = "hello, world";
    char empty[20];

    // string_copy(empty, string);
    // printf("string copy %s\n", empty);
    printf("Found char: %s\n", found_char);
    // printf("Found string: %s\n", found_string);

    return 0;
}
#endif
