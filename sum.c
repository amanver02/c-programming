
#include <stdio.h>

int main() {
    int a;
    int b;

    printf("Enter two numbers: ");  // Added colon after "numbers" for better formatting
    scanf("%d %d", &a, &b);        // Added spaces around `%d` for clarity

    printf("Total output is: %d\n", a + b);  // Calculated and printed the sum

    return 0;
}
