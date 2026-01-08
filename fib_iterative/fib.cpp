#include <iostream>

int fibHelper(int n, int prev2, int prev1) {
    if (n == 0) {
        return prev2;
    }

    if (n == 1) {
        return prev1;
    }
    
    return fibHelper(n - 1, prev1, prev2 + prev1);
}

int fib(int n) {
    return fibHelper(n, 0, 1);
}

int main() {
    fib(300);
    return 0;
}