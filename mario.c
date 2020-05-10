/* Not using cs50.h prefer to learn the hard way xD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char heightstring[10], *end;
    int height, i, j;
    do
    {
        printf("Height (between 1 and 8): ");
        if (!fgets(heightstring, sizeof heightstring, stdin))
        {
            height = 0;
        }
        else
        {
            heightstring[strcspn(heightstring, "\r\n")] = 0;
            height = strtol(heightstring, &end, 10);
        }
    }
    while (end != heightstring + strlen(heightstring) || height < 1 || height > 8);

    // i for files, j fpr columns
    for (i = height; i > 0; i--)
    {
        for (j = i - 1; j > 0; j--)
        {
            printf(" ");
        }
        for (j = height - i + 1; j > 0; j--)
        {
            printf("#");
        }
        printf("  ");
        for (j = height - i + 1; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}