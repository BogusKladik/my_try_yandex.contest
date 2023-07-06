#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    const std::string alphabets = "abcdefghijklmnopqrstuvwxyz";
    int n, k;
    std::cin >> n >> k;

    std::string spells;
    std::cin >> spells;
    if (spells.size() != n) {
        return 1;
    }

    std::vector<int> next_char(n);
    for (int i = 0; i != n; ++i) {
        std::cin >> next_char[i];
    }

    std::vector<int> shift(n);
    for (int i = 0; i != n; ++i) {
        std::cin >> shift[i];
    }

    long result = 0;
    for (int i = 0; i != n; ++i) {
        std::unordered_map<char, int> unique;
        int next_symbol = i;
        char symbol = spells[i];
        for (int j = 0; j != k; ++j) {
            ++unique[symbol];
            if (unique[symbol] != 1) {
                char from_alphabets = alphabets[(alphabets.find(symbol) + (unique[symbol] - 1) * shift[next_symbol]) % 26];
                if (from_alphabets != symbol) {
                    ++unique[from_alphabets];
                }
            }
            next_symbol = next_char[next_symbol] - 1;
            symbol = spells[next_symbol];
            result += unique.size();
        }
    }

    std::cout << result << std::endl;

    return 0;
}