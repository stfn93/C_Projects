#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char encrypt(char c, string n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    string key = argv[1];
    int length = strlen(key);
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < length; i++)
    {
        if (isalpha(key[i]))
        {
            for (int j = 0; j < i; j++)
            {
                if (key[i] == key[j])
                {
                    printf("Same character twice.\n");
                    return 1;
                }
            }
        }
        else if (isalpha(key[i]) != true)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    string plain_text = get_string("plaintext:  ");
    printf("ciphertext: ");

    for (int i = 0, text_length = strlen(plain_text); i < text_length; i++)
    {
        char h = plain_text[i];
        char g = encrypt(h, key);
        printf("%c", g);
    }
    printf("\n");
}

char encrypt(char c, string n)
{
    int b = 0;
    if (isupper(c))
    {
        int a = c - 65;
        b = n[a];
        b = toupper(b);
    }
    else if (islower(c))
    {
        int a = c - 97;
        b = n[a];
        b = tolower(b);
    }
    else
    {
        b = c;
    }
    return b;
}
