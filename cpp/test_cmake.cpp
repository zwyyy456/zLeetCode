#include <vector>
#include <iostream>

int test_sub() {
    std::vector<int> vec{1, 2, 3};
    int *ptr = nullptr;
    for (int num : vec) {
        std::cout << num << std::endl;
    }
    return 0;
}