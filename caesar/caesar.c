#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// for the letters count
#define ALPHANUMS 26

// functions prototypes
bool only_digits(string check);

int main(int argc, char *argv[])
{
    // check if the number of input is 2
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // checks numeric arguments
    if (!only_digits(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // converits string argument from string to int and make it smaller or equals to 26 letters
    int key = atoi(argv[1]) % ALPHANUMS;

    string plain_text = get_string("plaintext: ");

    // count the length of a plain text
    int len = strlen(plain_text) + 1;

    // to encode the plain text
    string cipher_text = malloc(len);

    // checking if something went wrong
    if (cipher_text == NULL)
    {
        return 1;
    }

    // converting process
    for (int i = 0; i < len; i++)
    {
        if (isupper(plain_text[i]))
        {
            cipher_text[i] = (plain_text[i] + key - 'A') % ALPHANUMS + 'A';
        }
        else if (islower(plain_text[i]))
        {
            cipher_text[i] = (plain_text[i] + key - 'a') % ALPHANUMS + 'a';
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
    // print ciphertext
    printf("ciphertext: %s\n", cipher_text);
    free(cipher_text);
    return 0;
}

// checks numeric arguments
bool only_digits(string check)
{
    bool c = true;
    for (int i = 0, n = strlen(check); i < n; i++)
    {
        if (!(check[i] >= '0' && check[i] <= '9'))
        {
            c = false;
            return c;
        }
    }
    return c;
}
