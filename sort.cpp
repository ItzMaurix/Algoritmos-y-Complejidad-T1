#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    std::sort(arr.begin(), arr.end());

    for (int x : arr) {
        std::cout << x << " ";
    }
    return 0;
}
