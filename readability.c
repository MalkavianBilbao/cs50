/* Not using cs50.h prefer to use only standard headers */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char text[1000];
    float grade;
    int letters = 0, words = 0, sentences = 0;

    printf("Text: ");
    fgets(text, sizeof text, stdin);
    //Remove newline and carriage return from variable. We could remove spaces so if the user keys the credit card number in groups of 4 as some does, it would still work, but not requested.
    text[strcspn(text, "\r\n")] = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // ASCII chars from a (97) to z (122) or A (65) to Z (90) (lowcase ones will be more frequent so we evaluate them first)
        //if ((text[i] > 96 && text[i] < 123) || (text[i] > 64 && text[i] < 91))
        if (isalpha(text[i]))
        {
            letters++;
        }
        else
            //Space = separator for words. Less frequent than letters, but more than senteces separators. As requested we assume there won't be two of more contiguous spaces.
            //if (text[i] = " ")
            if (isspace(text[i]))
            {
                words++;
            }
            else
                // Period, exclamation point, or question mark = Separation for sentences. The less frequent char we will find.
                // We assume all texts will end with period, exclamation point or question mark so the last word and sentence will be counted.
                // If not we could count the first sentence and word with the first letter of the text an go on.

                if (text[i] == '.' || text[i] == '!' || text[i] == '?')
                {
                    sentences++;
                    words++;
                    //There will be an space after the end of a sentence, so we ignore it pushing i forward by 1.
                    i++;
                }
    }       //Not more options. Other chars are ignored.

    //Readability index = 0.0588 * L - 0.296 * S - 15.8
    grade = 0.0588 * letters * 100 / words - 0.296 * sentences * 100 / words - 15.8;
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", grade);
    }

    return 0;
}