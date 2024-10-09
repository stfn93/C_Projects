#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long number = get_long("Number: ");
    char str[20];
    sprintf(str, "%ld", number);
    int size = strlen(str); // size of array
    if (size < 13 || size > 16)
    {
        printf("INVALID\n");
        exit(1);
    }

    int array_size = 0;
    int array_sizel = 0;
    char char_array[20];
    char char_arrayl[20];

    // takes every second element starting from second to last
    for (int i = size - 2; i >= 0; i -= 2)
    {
        char_array[array_size] = str[i];
        array_size++;
    }

    // takes every second element starting from last
    for (int i = size - 1; i >= 0; i -= 2)
    {
        char_arrayl[array_sizel] = str[i];
        array_sizel++;
    }

    int digit_sum = 0;
    int num;

    // take thint_array[array_size];ese elements and multiply by 2
    for (int i = 0; i < array_size; i++)
    {
        num = (char_array[i] - '0') * 2;

        if (num >= 10)
        {
            int second_digit = num % 10;
            digit_sum = digit_sum + 1 + second_digit;
        }
        else
        {
            digit_sum = digit_sum + num;
        }
    }

    for (int i = 0; i < array_sizel; i++)
    {
        num = char_arrayl[i] - '0';
        digit_sum = digit_sum + num;
    }

    bool isValid = false;
    float num1 = digit_sum % 10;
    if (num1 == 0)
    {
        isValid = true;
    }

    if (isValid && size == 15 && str[0] - '0' == 3 && (str[1] - '0' == 4 || str[1] - '0' == 7))
    {
        printf("AMEX\n");
    }
    else if (isValid && size == 16 && str[0] - '0' == 5 &&
             (str[1] - '0' == 1 || str[1] - '0' == 2 || str[1] - '0' == 3 || str[1] - '0' == 4 ||
              str[1] - '0' == 5))
    {
        printf("MASTERCARD\n");
    }
    else if (isValid && (size == 13 || size == 16) && str[0] - '0' == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
