#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;

    std::unordered_map<int, int> keyboard;
    keyboard.reserve(n);

    std::vector<int> indexes(n);
    for (size_t i = 0; i != n; ++i) {
        std::cin >> indexes[i];
    }

    for (size_t i = 0; i != n; ++i) {
        std::cin >> keyboard[indexes[i]];
    }

    size_t k;
    std::cin >> k;

    int pos;
    int result = 0;
    for (size_t i = 0; i != k; ++i) {
        size_t input;
        std::cin >> input;
        if (i != 0 && pos != keyboard[input]) {
            ++result;
        }
        pos = keyboard[input];
    }

    std::cout << result << std::endl;

    return 0;
}