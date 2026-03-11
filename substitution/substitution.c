#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// total sequence for letters
#define SEQ 26

// functions prototype
void message(string sequence, string user_word, char *ciphertext);
bool check_input(string check);

int main(int argc, char *argv[])
{
    // check if the number of input is 2
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // check alphabet arguments
    if (!check_input(argv[1]))
    {
        printf("Keys must be alphabetic.\n");
        return 1;
    }

    // check alphabet lengths
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // taking text from user
    string user = get_string("plaintext: ");

    // a string for encoding
    char *ciphertext = malloc(strlen(user) + 1);

    // if something went wrong
    if (ciphertext == NULL)
    {
        return 1;
    }

    // printing the message
    message(argv[1], user, ciphertext);

    // free memory from leaking
    free(ciphertext);
    return 0;
}

// converting from plain text to cipher text and printing it
void message(string sequence, string user_word, char *ciphertext)
{
    for (int i = 0, n = strlen(user_word) + 1; i < n; i++)
    {

        if (isupper(user_word[i]))
        {
            ciphertext[i] = toupper(sequence[user_word[i] - 'A']);
        }
        else if (islower(user_word[i]))
        {
            ciphertext[i] = tolower(sequence[user_word[i] - 'a']);
        }
        else
            ciphertext[i] = user_word[i];
    }
    printf("ciphertext: %s\n", ciphertext);
}

// check if input is just alphabetic
bool check_input(string check)
{
    for (int i = 0, n = strlen(check); i < n; i++)
    {
        if (!isalpha(check[i]))
        {
            return false;
        }
        // check for duplicate characters
        for (int j = i + 1; j < n - 1; j++)
        {
            if (toupper(check[i]) == toupper(check[j]))
            {
                return false;
            }
        }
    }
    return true;
}

// Problems: 1- a string is sotred in ROM which can not change, so you can not do char *word="naif"
// and then change it
// unlike malloc or get_string from cs50 where you can change them

// 2- when you have a sequence of elements in an array you can get them by just targeting the
// indexes

