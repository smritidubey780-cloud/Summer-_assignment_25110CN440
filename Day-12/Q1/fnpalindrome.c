int Palindrome(int num)
{ 
    int reversed = 0, original = num;

    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return (original == reversed);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (Palindrome(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }

    return 0;





}