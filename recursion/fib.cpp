#include <stdint.h>

uint64_t fib_iterative(int n) {
    if (n <= 1) return n;
    
    uint64_t a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    fib_iterative(300);
    return 0;
}