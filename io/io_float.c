#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("numeri_float.txt", "rb");
    if (!f) return 1;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    unsigned char *data = malloc(size);
    if (!data) {
        fclose(f);
        return 1;
    }

    if (size > 0) fread(data, 1, size, f);
    fclose(f);

    double sum = 0.0;

    double sign = 1.0;
    unsigned long long int_part = 0;
    unsigned long long frac_part = 0;
    double frac_div = 1.0;

    int in_num = 0;
    int in_frac = 0;

    for (long i = 0; i < size; ++i) {
        unsigned char c = data[i];

        if (c == '-' && !in_num) {
            sign = -1.0;
        }
        else if (c >= '0' && c <= '9') {
            in_num = 1;
            unsigned digit = c - '0';
            if (!in_frac) {
                int_part = int_part * 10 + digit;
            } else {
                frac_part = frac_part * 10 + digit;
                frac_div *= 10.0;
            }
        }
        else if (c == '.' && in_num && !in_frac) {
            in_frac = 1;
        }
        else {
            if (in_num) {
                sum += sign *
                       ((double)int_part + (double)frac_part / frac_div);

                sign = 1.0;
                int_part = 0;
                frac_part = 0;
                frac_div = 1.0;
                in_num = 0;
                in_frac = 0;
            } else {
                sign = 1.0;
            }
        }
    }

    if (in_num) {
        sum += sign *
               ((double)int_part + (double)frac_part / frac_div);
    }

    free(data);

    printf("Somma: %.6f\n", sum);
    return 0;
}
