#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    bool digit_test = only_digits(argv[1]);
    if (digit_test == false)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    int key = atoi(argv[1]);
    string text = get_string("plaintext:  ");
    int length = strlen(text);
    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        char h = text[i];
        char g = rotate(h, key);
        printf("%c", g);
    }

    printf("\n");
}

bool only_digits(string s)
{
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    int b = 0;
    if (isupper(c))
    {
        char a = c - 65;
        b = (a + n) % 26;
        b += 65;
    }
    else if (islower(c))
    {
        char a = c - 97;
        b = (a + n) % 26;
        b += 97;
    }
    else
    {
        b = c;
    }
    return (char) b;
}
