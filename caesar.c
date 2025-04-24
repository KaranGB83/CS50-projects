#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // else
    //     return 0;

    // Make sure every character in argv[1] is a digit
    // if (only_digits(argv[1]) == false)
    // {
    //     printf("Usage: ./caesar key\n");
    //     return 1;
    // }
    // else
    //     return 0;

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    int len = strlen(plaintext);

    printf("ciphertext: ");
    // For each character in the plaintext:
    for (int k = 0; k < len; k++)
    {
        // Rotate the character if it's a letter
        printf("%c", rotate(plaintext[k], key));
    }
    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    int len = strlen(s);
    for (int j = 0; j < len; j++)
    {
        if (!isdigit(s[j]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            return 'A' + (c - 'A' + n) % 26;
        }
        else if (islower(c))
        {
            return 'a' + (c - 'a' + n) % 26;
        }
    }
    return c;
}
