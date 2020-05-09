#include <stdio.h>
#include <string.h> /* I prefer to use standard C instead of cs50.h library */

int main(void)
{
    char name[20];
    printf("What's your name: ");
//    scanf("%s", name);
    fgets(name, sizeof(name), stdin);
    /* strcspn counts the number of characters until it hits a '\r' or a '\n' (in other words, it finds the first '\r' or '\n'). If it doesn't hit anything, it stops at the '\0' (returning the length of the string). */
    name[strcspn(name, "\r\n")] = 0;
    printf("Hello, %s!\n", name);
    return 0;
}
