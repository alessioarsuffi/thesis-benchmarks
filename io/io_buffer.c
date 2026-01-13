#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
    FILE *f = fopen("numeri.txt", "rb");
    if (!f) return 1;

    static char io_buf[1 << 20];
    setvbuf(f, io_buf, _IOFBF, sizeof(io_buf));

    char buf[1 << 20];
    size_t n;

    long long sum = 0;
    long long x = 0;
    int in_num = 0;

    while ((n = fread(buf, 1, sizeof(buf), f)) > 0) {
        for (size_t i = 0; i < n; ++i) {
            unsigned char c = (unsigned char)buf[i];
            if (c >= '0' && c <= '9') {
                x = x * 10 + (c - '0');
                in_num = 1;
            } else {
                if (in_num) {
                    sum += x;
                    x = 0;
                    in_num = 0;
                }
            }
        }
    }

    if (in_num) sum += x;

    printf("Somma: %lld", sum);
    fclose(f);
    return 0;
}