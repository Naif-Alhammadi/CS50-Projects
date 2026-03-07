#include <cs50.h>
#include <stdio.h>
// prototype
void print(int);

int main()
{
    int pyramidNums;
    do
    {
        // if the input is not valid
        pyramidNums = get_int("enter the number of pyramidNums : ");
    }
    while (pyramidNums <= 0);
    // if input is valid fuction call
    print(pyramidNums);
}
void print(int nums)
{
    int mNums = nums;
    for (int i = 0; i < nums; i++)
    {
        // sub 1 to delete the not wanting first line
        for (int spaces = (nums - i) - 1; spaces > 0; spaces--)
            printf(" ");
        for (int j = nums; j >= nums - i; j--)
            printf("#");
        printf("\n");
    }
}
