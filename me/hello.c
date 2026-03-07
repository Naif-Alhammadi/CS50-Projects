#include <cs50.h>
#include <stdio.h>

int main()
{
    string mess;
    // taking inputs from the user
    mess = get_string("enter your name ");
    printf("hello, %s\n", mess);
}
