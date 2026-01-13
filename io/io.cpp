#include <fstream>
#include <vector>
#include <cassert>
#include <iostream>

int main() {
    std::ifstream file("numeri.txt", std::ios::binary);
    if (!file) return 1;

    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> data((size_t)size);
    if (size > 0) file.read(data.data(), size);

    long long sum = 0;
    long long x = 0;
    bool in_num = false;

    for (unsigned char c : data) {
        if (c >= '0' && c <= '9') {
            x = x * 10 + (c - '0');
            in_num = true;
        } else {
            if (in_num) {
                sum += x;
                x = 0;
                in_num = false;
            }
        }
    }
    if (in_num) sum += x;
    std::cout << "Somma: " << sum << '\n';
    return 0;
}
