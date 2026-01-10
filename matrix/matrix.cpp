#include <iostream>
#include <vector>

static constexpr std::size_t N = 2500;

static inline std::size_t idx(std::size_t r, std::size_t c) {
    return r * N + c;
}

void matrix_product(const std::vector<double>& a,
                    const std::vector<double>& b,
                    std::vector<double>& c) {
    std::fill(c.begin(), c.end(), 0.0);

    for (std::size_t i = 0; i < N; i++) {
        for (std::size_t k = 0; k < N; k++) {
            double aik = a[idx(i, k)];
            std::size_t bk_row = k * N;
            std::size_t ci_row = i * N;

            for (std::size_t j = 0; j < N; j++) {
                c[ci_row + j] += aik * b[bk_row + j];
            }
        }
    }
}

int main() {
    std::vector<double> a(N * N);
    std::vector<double> b(N * N);
    std::vector<double> c(N * N);

    for (std::size_t i = 0; i < N; i++) {
        for (std::size_t j = 0; j < N; j++) {
            a[idx(i, j)] = static_cast<double>(i) + 0.01 * static_cast<double>(j);
            b[idx(i, j)] = static_cast<double>(j) - 0.02 * static_cast<double>(i);
        }
    }

    matrix_product(a, b, c);

    double c00 = c[idx(0, 0)];
    double c99 = c[idx(99, 99)];

    std::cout << "C[0,0]   = " << c00 << '\n';
    std::cout << "C[99,99] = " << c99 << '\n';

    return 0;
}
