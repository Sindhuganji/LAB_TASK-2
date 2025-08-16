#include <stdio.h>
int gp_sum_iterative(int a, int r, int n) { // geometric progression sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a;
        a *= r; // Update a to the next term in the GP
    }
    return sum;
}
int main(){
    int a, r, n; // a is first term, r is common ratio, n is number of terms
    printf("Enter first term (a) and common ratio (r): ");
    scanf("%d %d", &a, &r);
    if (a <= 0 || r <= 0) {
        printf("Both first term and common ratio must be positive integers.\n");
        return 1;
    }
    printf("Enter number of terms (n): ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number of terms must be a positive integer.\n");
        return 1;
    }
    if (n == 1) {
        printf("Sum of GP with first term %d and common ratio %d for 1 term is: %d\n", a, r, a);
        return 0;
    }
    if (r == 1) {
        printf("Sum of GP with first term %d and common ratio %d for %d terms is: %d\n", a, r, n, a * n);
        return 0;
    }
    int sum = gp_sum_iterative(a, r, n);
    printf("Sum of GP for %d terms is: %d\n", n, sum);
    return 0;
}