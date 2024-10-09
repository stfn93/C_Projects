#include <cs50.h>
#include <stdio.h>

void print_sign(int legth_space, string character);

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (9 < height || 0 >= height);
    for (int i = 0; i < height; i++)
    {
        print_sign(height - i - 1, " ");
        print_sign(i + 1, "#");
        printf("  ");
        print_sign(i + 1, "#");
        printf("\n");
    }
}

// prints spaces and hashes

void print_sign(int length_space, string character)
{
    for (int i = 0; i < length_space; i++)
    {
        printf("%s", character);
    }
}
