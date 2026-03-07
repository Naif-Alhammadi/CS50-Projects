#include <cs50.h>
#include <stdio.h>
#define NUM 4
// prototype
int changesOwed(int arr[], int);

int main()
{
    // descending order to implement the greedy algorithm
    int cashArray[NUM] = {25, 10, 5, 1};
    int changes;
    do
    {
        // is a positive int
        changes = get_int("Change owed: ");
    }
    while (changes < 0);
    printf("%i", changesOwed(cashArray, changes));
    printf("\n");
}
// function implementation
int changesOwed(int arr[], int n)
{
    int changesCount = 0;
    for (int i = 0; i < NUM; i++)
    {
        if (n >= arr[i])
        {
            changesCount++;
            n = n - arr[i];
            // restart the count to 25 again
            i = -1;
        }
    }
    return changesCount;
}
