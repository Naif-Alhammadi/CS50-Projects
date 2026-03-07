#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// prototype
void pyramidsCount(int);

int main()
{
    int pyramids;
    do
    {
        // if input is not between 1 to 8
        pyramids = get_int("enter the count of mario pyramids\n");
    }
    while (!(pyramids > 0 && pyramids < 9));
    // if input is valid call the function
    pyramidsCount(pyramids);
}

void pyramidsCount(int count)
{
    for (int i = 0; i < count; i++)
    {
        // for the space
        for (int space = count - i; space > 1; space--)
            printf(" ");
        for (int j = count; j >= count - i; j--)
            printf("#");
        // for the second #
        printf("  ");
        for (int j2 = count; j2 >= count - i; j2--)
            printf("#");
        printf("\n");
    }
}
