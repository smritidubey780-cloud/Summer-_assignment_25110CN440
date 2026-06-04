#include <stdio.h>
 int main() {
    int num, originalNum, remainder, result = 0;

    // Input from user
    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Calculate the sum of the cubes of the digits
    while (originalNum != 0) {
        remainder = originalNum % 10; // Extract last digit
        result += remainder * remainder * remainder; // Add cube of digit to result
        originalNum /= 10; // Remove last digit
    }

    // Check if the number is an Armstrong number
    if (result == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}