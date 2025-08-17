#include <stdio.h>
#include <math.h>

// Iterative method to calculate 1 + x + x^2 + ... + x^n
int sum_series_iterative(int x, int n) {
    int sum = 0;
    int term = 1;   // x^0 = 1

    for (int i = 0; i <= n; i++) {
        sum += term;      // add current power of x
        term *= x;        // move to next power
    }

    return sum;
}

int main() {
    int x, n;
    printf("Enter value of x: ");
    scanf("%d", &x);
    printf("Enter number of terms (n): ");
    scanf("%d", &n);

    int result = sum_series_iterative(x, n);

    printf("Sum of series 1 + x + x^2 + ... + x^%d = %lld\n", n, result);

    return 0;
}
