#include <stdio.h>

int main() {
    int num, count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num > 0) {
        count += num % 2;  // Add 1 if the last bit is set
        num /= 2;
    }

    printf("Number of set bits = %d\n", count);

    return 0;
}