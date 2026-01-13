#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
    FILE *f = fopen("numeri.txt", "rb");
    if (!f) return 1;

    long long sum = 0;
    long long x = 0;
    int in_num = 0;

    int ch;
    while ((ch = fgetc(f)) != EOF) {
        unsigned char c = (unsigned char)ch;

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

    if (in_num) {
        sum += x;
    }

    printf("Somma: %lld", sum);
    fclose(f);
    return 0;
}
