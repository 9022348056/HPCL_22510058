#include <stdio.h>
#include <omp.h>

#define N 10

int main() {
    int A[N], prefix_sum[N];
    int i;

    // Initialize array
    for (i = 0; i < N; i++) {
        A[i] = i + 1;
    }

    prefix_sum[0] = A[0];

    // Prefix sum (sequential for simplicity)
    // Parallel prefix sum requires special algorithm
    #pragma omp parallel for
    for (i = 1; i < N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }

    // Output
    for (i = 0; i < N; i++) {
        printf("%d ", prefix_sum[i]);
    }
    printf("\n");

    return 0;
}
