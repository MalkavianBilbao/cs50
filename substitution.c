/* Not using cs50.h prefer to use only standard headers */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool repetitionornoalpha(char key[26]);

int main(int argc, char *argv[])
{
    char plaintext[1000], ciphertext[1000];

    if (argc != 2 || strlen(argv[1]) != 26 || repetitionornoalpha(argv[1]))
    {
        printf("Usage: %ss KEY\n       KEY should be the 26 letters of the alphabet in your chosen order without repetition.\n", argv[0]);
        return 1;
    }
    else
    {
        printf("plaintext:  "); // Two spaces for alineation with next printf "ciphertext: "
        fgets(plaintext, sizeof plaintext, stdin);
        //Remove newline and carriage return from variable.
        plaintext[strcspn(plaintext, "\r\n")] = 0;
        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isalpha(plaintext[i]))
            {
                if (plaintext[i] > 90)
                {
                    // Lowcase letters are ASCII code 97 to 122. Substracting 97 we get the needed position in key from 0 to 25.
                    ciphertext[i] = tolower(argv[1][plaintext[i] - 97]);
                }
                else
                {
                    // Uppercase letters ASCII 65 to 90. Substracting 65 we get the needed position in key from 0 to 25.
                    ciphertext[i] = toupper(argv[1][plaintext[i] - 65]);
                }
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }
        printf("ciphertext: %s\n", ciphertext);

        return 0;
    }
}

bool repetitionornoalpha(char key[26])
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            return 1;
            break;
        }
        // We only need to compare each char with the next ones, since previous ones were already compared in previous iterations
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (key[i] == key[j])
            {
                return 1;
                break;
            }
        }
    }
    return 0;
}
