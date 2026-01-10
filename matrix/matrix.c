#include <stdio.h>
#include <stdlib.h>

#define N 2500

static inline size_t idx(size_t r, size_t c) {
    return r * N + c;
}

void matrix_product(const double *a,
                    const double *b,
                    double *c) {
    for (size_t i = 0; i < (size_t)N * N; i++) {
        c[i] = 0.0;
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t k = 0; k < N; k++) {
            double aik = a[idx(i, k)];
            size_t bk_row = k * N;
            size_t ci_row = i * N;

            for (size_t j = 0; j < N; j++) {
                c[ci_row + j] += aik * b[bk_row + j];
            }
        }
    }
}

int main(void) {
    double *a = malloc(sizeof(double) * N * N);
    double *b = malloc(sizeof(double) * N * N);
    double *c = malloc(sizeof(double) * N * N);

    if (!a || !b || !c) {
        return 1;
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            a[idx(i, j)] = (double)i + 0.01 * (double)j;
            b[idx(i, j)] = (double)j - 0.02 * (double)i;
        }
    }

    matrix_product(a, b, c);

    double c00 = c[idx(0, 0)];
    double c99 = c[idx(99, 99)];

    printf("C[0,0]   = %.10f\n", c00);
    printf("C[99,99] = %.10f\n", c99);

    free(a);
    free(b);
    free(c);
    return 0;
}
