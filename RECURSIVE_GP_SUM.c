#include <stdio.h>
#include <math.h>
int gp_sum_recursive(int x, int n) {
    if (n == 0) {   
        return 1;   
    }
    return gp_sum_recursive(x, n - 1) + pow(x, n);
}

int main() {
    int x, n;
    printf("Enter value of x: ");
    scanf("%d", &x);
    printf("Enter number of terms (n): ");
    scanf("%d", &n);

    int sum = gp_sum_recursive(x, n);
    printf("Sum of series 1 + x + x^2 + ... + x^%d = %d\n", n, sum);

    return 0;
}
