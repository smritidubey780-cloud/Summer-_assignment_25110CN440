#include<stdio.h>

// Recursive function to find nth Fibonacci number
int sumOfProperDivisors(int n ,int i)
{
    if (i == 0)
        return 0;

     if (n % i == 0)
        return i + sumOfProperDivisors(n, i - 1);
    
        return  sumOfProperDivisors(n, i-1);
}
int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num == sumOfProperDivisors(num ,num/2))
        printf("%d is a perfect number.\n", num);
    else
        printf("%d is not a perfect number.\n", num);

    return 0;
}