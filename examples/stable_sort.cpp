// Let's show that MergeSort is stable

#include <iostream>

#include "../mergesort.hpp"

class Pair {
private:
    int value;
    int number;
public:
    Pair(int value=0, int number=0) {this->value = value; this->number = number;}
    bool operator<(const Pair& other) const {
        return value < other.value;
    }

    friend std::ostream& operator<<(std::ostream& os, const Pair& obj);
};

std::ostream& operator<<(std::ostream& os, const Pair& obj) {
    os << "Pair(" << obj.value << ", " << obj.number << ")";
    return os;
}

int main() {
    const int length = 20;
    Pair arr0[length] = {Pair(0, 1), Pair(1, 2), Pair(2, 3), Pair(0, 4), Pair(1, 5), Pair(2, 6), Pair(0, 7), Pair(1, 8), Pair(2, 9), Pair(0, 10), Pair(1, 11), Pair(2, 12),
        Pair(0, 13), Pair(1, 14), Pair(2, 15), Pair(0, 16), Pair(1, 17), Pair(2, 18), Pair(0, 19), Pair(1, 20)};
    Pair arr1[length] = {Pair(0, 1), Pair(1, 2), Pair(2, 3), Pair(0, 4), Pair(1, 5), Pair(2, 6), Pair(0, 7), Pair(1, 8), Pair(2, 9), Pair(0, 10), Pair(1, 11), Pair(2, 12),
        Pair(0, 13), Pair(1, 14), Pair(2, 15), Pair(0, 16), Pair(1, 17), Pair(2, 18), Pair(0, 19), Pair(1, 20)};
    //for (int i = 0; i < length; ++i) std::cout << dqs(arr, length, i + 1) << ' ';
    //std::cout << std::endl << std::endl;
    mergesort<Pair>(arr1, length);
    for (int i = 0; i < length; ++i) std::cout << arr1[i] << ' ';
    std::cout << std::endl << std::endl;
    return 0;
}
