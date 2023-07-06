#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int countries;
    std::cin >> countries;

    std::vector<unsigned int> payday(countries);
    for (int i = 0; i != countries; ++i) {
        std::cin >> payday[i];
    }
    // unsigned int* payday = new unsigned int[countries];
    // for (int i = 0; i != countries; ++i) {
    //     std::cin >> payday[i];
    // }

    std::vector<bool> higher(countries);
    // bool* higher = new bool[countries];
    for (int i = 0; i != countries; ++i) {
        int educational;
        std::cin >> educational;
        // (educational == 0) ? higher[i] = false : higher[i] = true;
        higher[i] = !!educational;
    }

    std::vector<bool> family(countries);
    // bool* family = new bool[countries];
    for (int i = 0; i != countries; ++i) {
        int permit;
        std::cin >> permit;
        (permit == 0) ? family[i] = false : family[i] = true;
        family[i] = !!permit;
    }

    int classmates;
    std::cin >> classmates;

    std::vector<unsigned int> classmate_payday(classmates);
    // unsigned int* classmate_payday = new unsigned int[classmates];
    for (int i = 0; i != classmates; ++i) {
        std::cin >> classmate_payday[i];
    }

    std::vector<unsigned int> classmate_higher(classmates);
    // unsigned int* classmate_higher = new unsigned int[classmates];
    for (int i = 0; i != classmates; ++i) {
        int educational;
        std::cin >> educational;
        (educational == 0) ? classmate_higher[i] = false : classmate_higher[i] = true;
    }

    std::vector<int> where_parents(classmates);
    // int* where_parents = new int[classmates];
    for (int i = 0; i != classmates; ++i) {
        std::cin >> where_parents[i];
    }

    for (int i = 0; i != classmates; ++i){
        int immigration = 0;
        
        for (int j = 0; j != countries; ++j) {
            if (family[j] == 1 && where_parents[i] == j + 1) {
                immigration = j + 1;
                break;
            } else if (higher[j] && classmate_higher[i] && classmate_payday[i] >= payday[j]) {
                immigration = j + 1;
                break;
            } else if (!higher[j] && classmate_payday[i] >= payday[j]) {
                immigration = j + 1;
                break;
            }
            // if ((family[j] == 1 && where_parents[i] == j + 1) || 
            //     (higher[j] && classmate_higher[i] && classmate_payday[i] >= payday[j]) ||
            //     (!higher[j] && classmate_payday[i] >= payday[j])) {
            //     immigration = j + 1;
            //     break;
            // }
        }
        if (i != 0) {
            std::cout << ' ' << immigration;
        } else {
            std::cout << immigration;
        }
    }
    std::cout << std::endl;

    return 0;
}