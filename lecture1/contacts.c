# include <cs50.h>
# include <stdio.h>

int main (void)
{
    string name = get_string("What's your name? ");
    int age = get_int("What's your age? ");
    string phone_number = get_string("What's your phone number? ");

    printf("Hello, %s you are %i years old and your phone number is %s \n", name, age, phone_number);

}
