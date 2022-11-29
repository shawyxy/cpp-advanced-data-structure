#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *caesar(const char *str, int offset)
{
    char *start = nullptr, *ret_str = nullptr;

    start = ret_str = (char *) malloc(strlen(str) + 1);
    for(; *str!='\0'; str++, ret_str++)
    {
        if(*str >= 'A' && *str <= 'Z')
            *ret_str = 'A' + (*str - 'A' + offset) % 26;
        else if(*str >= 'a' && *str <= 'z')
            *ret_str = 'a' + (*str - 'a' + offset) % 26;
        else
            *ret_str = *str;
    }

    *ret_str = '\0';
    return (char *) start;
}
int main(void)
{
    printf("%s\n", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    printf("%s\n", caesar("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3));
    return 0;
}