#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int word_score(string s);
int letter_scores[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                       1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string words[2];
    int score[2];
    for (int i = 0; i < 2; i++)
    {
        words[i] = get_string("Player %i: ", i + 1);
        score[i] = word_score(words[i]);
    }

    if (score[0] > score[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (score[0] < score[1])
    {
        printf("Player 2 wins!\n");
    }
    else if (score[0] == score[1])
    {
        printf("Tie!\n");
    }
    else
    {
        return 1;
    }
}

// Score
int word_score(string s)
{
    int score = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        char c = toupper(s[i]);
        // Check if character is a letter
        if (c >= 'A' && c <= 'Z')
        {
            score += letter_scores[c - 'A'];
        }
    }
    return score;
}
