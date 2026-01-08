int fib_iterative(int n) {
    if (n <= 1) {
        return n;
    }
    int prev1 = 1, prev2 = 0;
  	int curr;
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    fib_iterative(300);
    return 0;
}