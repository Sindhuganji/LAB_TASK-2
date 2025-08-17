#include <stdio.h>
#include <math.h>
int sum_series_iterative(int x, int n) {
    int sum = 0;
    int term = 1;   

    for (int i = 0; i <= n; i++) {
        sum += term;      
        term *= x;       
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

    printf("Sum of series 1 + x + x^2 + ... + x^%d = %d\n", n, result);

    return 0;
}
