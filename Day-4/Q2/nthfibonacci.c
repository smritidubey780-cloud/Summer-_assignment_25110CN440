#include <stdio.h>

int main()
{
    int n, t1 = 0, t2 = 1, nextTerm;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n == 1)
    {
        printf("The %dst Fibonacci term is %d\n", n, t1);
    }
    else if (n == 2)
    {
        printf("The %dnd Fibonacci term is %d\n", n, t2);
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
        }

        printf("The %dth Fibonacci term is %d\n", n, t2);
    }

    return 0;
}