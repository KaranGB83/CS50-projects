#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        //input
        n = get_int("Height: ");
    }
    while(n<1);
    //generate brics
    for (int i=0; i < n; i++)
    {
        //print spaces
        for (int j=n-1; j > i; j--)
        {
            printf(" ");
        }
        //print brics
        for (int k=0; k <= i; k++)
        {
                printf("#");
        }
        printf("\n");
    }
}
