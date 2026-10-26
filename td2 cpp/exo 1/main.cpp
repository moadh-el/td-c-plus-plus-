#include "LinearSearch.h"
#include "BinarySearch.h"
#include <iostream>
#include "JumpSearch.h"

int main(){
    std::vector<int> list = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 13;

    SearchingAlgorithm::resetStatistics();

    LinearSearch linear;
    JumpSearch jump;
    BinarySearch binary;

    const int linearResult = linear.search(list, target);
    linear.displaySearchResults(std::cout, linearResult, target);

    const int jumpResult = jump.search(list, target);
    jump.displaySearchResults(std::cout, jumpResult, target);

    const int binaryResult = binary.search(list, target);
    binary.displaySearchResults(std::cout, binaryResult, target);

}