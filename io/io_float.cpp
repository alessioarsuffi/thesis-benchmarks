#include <fstream>
#include <vector>
#include <iostream>

int main() {
    std::ifstream file("numeri_float.txt", std::ios::binary);
    if (!file) return 1;

    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<unsigned char> data((size_t)size);
    if (size > 0) file.read(reinterpret_cast<char*>(data.data()), size);

    double sum = 0.0;

    double sign = 1.0;
    unsigned long long int_part = 0;
    unsigned long long frac_part = 0;
    double frac_div = 1.0;

    bool in_num = false;
    bool in_frac = false;

    for (unsigned char c : data) {
        if (c == '-' && !in_num) {
            sign = -1.0;
        }
        else if (c >= '0' && c <= '9') {
            in_num = true;
            unsigned digit = c - '0';
            if (!in_frac) {
                int_part = int_part * 10 + digit;
            } else {
                frac_part = frac_part * 10 + digit;
                frac_div *= 10.0;
            }
        }
        else if (c == '.' && in_num && !in_frac) {
            in_frac = true;
        }
        else {
            if (in_num) {
                double value =
                    sign * (double(int_part) + double(frac_part) / frac_div);
                sum += value;

                sign = 1.0;
                int_part = 0;
                frac_part = 0;
                frac_div = 1.0;
                in_num = false;
                in_frac = false;
            } else {
                sign = 1.0;
            }
        }
    }

    if (in_num) {
        double value =
            sign * (double(int_part) + double(frac_part) / frac_div);
        sum += value;
    }

    std::cout << std::fixed << std::setprecision(6)
              << "Somma: " << sum << '\n';
    return 0;
}
