/* Not using cs50.h prefer to learn the hard way xD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//long is not enought in 32bit systems: https://en.wikibooks.org/wiki/C_Programming/limits.h
long long cardnumber;
char type[11], number[20];

void cardtype(void);

int main(void)
{
    char *end;
    int i, num, add = 0;
    do
    {
        printf("Number: ");
        if (!fgets(number, sizeof number, stdin))
        {
            continue;
        }
        else
        {
            //Remove newline and carriage return from variable. We could remove spaces so if the user keys the credit card number in groups of 4 as some does, it would still work, but not requested.
            number[strcspn(number, "\r\n")] = 0;
            // Convert string to long int in base 10.
            cardnumber = strtoll(number, &end, 10);
        }
    }
    while (end != number + strlen(number));

    cardtype();

    if (strcmp(type, "INVALID")) /* If type="INVALID" strcmp returns 0, so FALSE */
    {
        for (i = 0; i < strlen(number); i++)
        {
            num = cardnumber % 10;
            //If from right to left it is a pair digit... (what happens when i is odd)
            if (i % 2 == 1)
            {
                num *= 2;
                // At max, num could be 18 (9*2). If num > 10, substract 10 and add 1 is then equal to add his digits, wich is equal to substract 9 (10-1=9).
                if (num > 10)
                {
                    num -= 9;
                }
            }
            add += num;
            //One digit less
            cardnumber /= 10;
        }
        if (add % 10 != 0)
        {
            strcpy(type, "INVALID");
        }
    }
    printf("%s\n", type);
    return 0;
}

void cardtype(void)
{
// VISA: 13 or 16 digits. Starts with 4
// AMEX: 15 digits. Starts with 34 or 37
// MASTERCARD: 16 digits. Starts with 51, 52, 53, 54 or 55
// INVALID: Any other for this program
    switch (strlen(number))
    {
        case 13:
            if (cardnumber / 1000000000000 == 4) /* 12 digits less for evaluating digit 13 */
            {
                strcpy(type, "VISA");
            }
            else
            {
                strcpy(type, "INVALID");
            }
            break;
        case 15:
            if (cardnumber / 10000000000000 == 34 || cardnumber / 10000000000000 == 37) /* 13 digits less for evaluating digits 14 and 15 */
            {
                strcpy(type, "AMEX");
            }
            else
            {
                strcpy(type, "INVALID");
            }
            break;
        case 16:
            if (cardnumber / 100000000000000 > 50 && cardnumber / 100000000000000 < 56) /* 14 digits less for evaluating digits 15 and 16 */
            {
                strcpy(type, "MASTERCARD");
            }
            else
            {
                if (cardnumber / 1000000000000000 == 4) /* 15 digits less for evaluating digit 16 */
                {
                    strcpy(type, "VISA");
                }
                else
                {
                    strcpy(type, "INVALID");
                }
            }
            break;
        default:  /* If number lenght is 14 or < 13 or > 16 */
            strcpy(type, "INVALID");
    }
}