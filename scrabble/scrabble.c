#include "../cs50/cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// for the alphabetic
#define index 26

// functions prototype
void fill_array(char[]);
int check_win(string const word, char arr[], int array_points[]);

int main(int argc, char *argv[])
{
    char scrabble_letter[index];
    // for array points
    int arry_points[index] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                              1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // to fill the array with alphas
    fill_array(scrabble_letter);
    char *player1;
    int player1_points;
    int player2_points;
    char *player2;
    player1 = get_string("player1 enter the word: ");
    player2 = get_string("player2 enter the word: ");
    // player1 checking validation
    for (int i = 0; i < strlen(player1); i++)
    {
        if (isalpha(player1[i]))
            player1[i] = toupper(player1[i]);
        else
            continue;
    }
    // player2 checking validation
    for (int i = 0; i < strlen(player2); i++)
    {
        if (isalpha(player2[i]))
            player2[i] = toupper(player2[i]);
        else
            continue;
    }
    player1_points = check_win(player1, scrabble_letter, arry_points);
    player2_points = check_win(player2, scrabble_letter, arry_points);

    // checking who is the winner
    if (player1_points > player2_points)
    {
        printf("player 1 wins!\n");
    }
    else if (player1_points < player2_points)
    {
        printf("player 2 wins!\n");
    }
    else
        printf("Tie!\n");

    return 0;
}

void fill_array(char arr[])
{
    char fill_letters = 'A';
    // int fill_numbers=1;
    for (int i = 0; i < index; i++)
    {
        arr[i] = fill_letters;
        fill_letters++;
    }
}

int check_win(string const word, char arr[], int array_points[])
{
    // the count of points for each letter
    int total_points = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        for (int j = 0; j < index; j++)
        {
            if (word[i] == arr[j])
            {
                total_points += array_points[j];
                break;
            }
        }
    }
    return total_points;
}
