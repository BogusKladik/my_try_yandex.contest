#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, t;
    std::cin >> n >> x >> t;

    std::vector<std::pair<int, int>> statues(n);
    for (size_t i = 0; i != n; ++i) {
        statues[i].first = i + 1;
        std::cin >> statues[i].second;
    }

    for (auto& statue : statues) {
        // statue.second = abs(statue.second - x);
        statue.second = abs(x - statue.second);
    }

    std::sort(statues.begin(), statues.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    std::vector<int> perfect_statues;
    for (const auto& statue : statues) {
        t -= statue.second;
        if (t < 0) {
            break;
        }
        // if (t >= statue.second) {
        //     perfect_statues.push_back(statue.first);
        //     t -= statue.second;
        // } else {
        //     break;
        // }
        perfect_statues.push_back(statue.first);
    }

    if (perfect_statues.empty()) {
        std::cout << '0';
    } else {
        std::cout << perfect_statues.size() << std::endl;
        for (const auto& per : perfect_statues) {
            std::cout << per << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}