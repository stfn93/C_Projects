// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Variable to track number of words in dictionary
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word to obtain its hash value
    unsigned int index = hash(word);
    // Search the hash table at the location specified by the word’s hash value
    node *cursor = table[index];
    // Traverse the linked list
    while (cursor != NULL)
    {
        // Compare case-insensitively with strcasecmp
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Could not open file: %s\n", dictionary);
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(source, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(source);
            return false;
        }
        strcpy(n->word, word);
        // Hash the word int the node
        unsigned int index = hash(word);
        // Insert the node into the hash table (at the start of the linked list)
        n->next = table[index];
        table[index] = n;
        word_count++;
    }
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over each index in the hash table
    for (unsigned i = 0; i < N; i++)
    {
        node *cursor = table[i];
        // Free the linked list at each index
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
