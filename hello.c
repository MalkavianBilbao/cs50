#include <stdio.h>

int main(void)
{
    char name[20]; /* I prefer to use standard C instead of cs50.h library altought scanf is not considered secure without limiting it*/
    printf("What's your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
}