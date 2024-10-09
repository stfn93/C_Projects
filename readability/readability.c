#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int grade(string s);

int main(void)
{

    printf("Text: ");
    string text = get_string("\n");
    int g = grade(text);

    if (g < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (g >= 1 && g < 16)
    {
        printf("Grade %i\n", g);
    }
    else if (g >= 16)
    {
        printf("Grade 16+\n");
    }
}

int grade(string s)
{
    float letter = 0;
    float space = 0;
    float punctuation = 0;

    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(s[i]))
        {
            letter++;
        }
        else if (isblank(s[i]))
        {
            space++;
        }
        else if ((s[i] == 21) || (s[i] == 46) || (s[i] == 63))
        {
            punctuation++;
        }
    }
    float words = space + 1;
    float L = (letter / words) * 100;
    float S = (punctuation / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int g = round(index);
    return g;
}
