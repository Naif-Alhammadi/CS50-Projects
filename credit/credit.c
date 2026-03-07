#include <cs50.h>
#include <stdio.h>
// function prototypes
bool isValied(long long int, int, int *);
string checks(const int *);
// global varible to access and count the digits
int digitCounts = 0;
int main(void)
{
    // to take the last digit
    int rest = 10;
    int firstTwoDigits = 0;
    // to pass it to a function and change the original value
    int *ptrOfFirstTwoDigits = &firstTwoDigits;
    // to take long digits
    long long int creditNumber;
    creditNumber = get_long_long("Number: ");
    if (isValied(creditNumber, rest, ptrOfFirstTwoDigits))
    {

        printf("%s", checks(ptrOfFirstTwoDigits));
    }
    else
        printf("INVALID\n");
}
// functions
// to check validation
bool isValied(long long int num, int rest, int *firstDigits)
{
    int firstNums = 0;
    int secondNums = 0;
    long long temp = num;
    long long temp2 = num;
    while (num != 0)
    {
        firstNums += num % rest;
        num /= rest;
        // if number bigger than 9 while divide to two parts and sum them
        secondNums += (num % rest) * 2 <= 9 ? (num % rest) * 2 : ((num % rest) * 2) - 9;
        num /= rest;
    }
    // to take the first two digits
    while (temp >= 100)
    {
        temp /= 10;
    }
    // to count the the totoal digits
    while (temp2 > 0)
    {
        temp2 /= 10;
        digitCounts++;
    }
    // to change the actual value
    *firstDigits = temp;
    if ((firstNums + secondNums) % 10 == 0)
        return true;
    else
        return false;
}
// to check credits
string checks(const int *ptrchecks)
{
    switch (digitCounts)
    {
        case 15:
        {
            if (*ptrchecks == 34 || *ptrchecks == 37)
                return "AMEX\n";
            break;
        }
        case 13:
        {
            // divide by 10 to take only the first digit
            if (*ptrchecks / 10 == 4)
            {
                return "VISA\n";
            }
            break;
        }
        case 16:
        {
            if (*ptrchecks >= 51 && *ptrchecks <= 55)
                return "MASTERCARD\n";
            else if (*ptrchecks / 10 == 4)
                return "VISA\n";
            break;
        }
    }
    return "INVALID\n";
}
