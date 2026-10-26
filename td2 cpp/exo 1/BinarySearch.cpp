#include "BinarySearch.h"

int BinarySearch::search(std::vector<int> list, int target) {
    int comparisons = 0;
    int left = 0;
    int right = static_cast<int>(list.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        ++comparisons;

        if (list[mid] == target) {
            setNumberComparisons(comparisons);
            return mid;
        } else if (list[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    setNumberComparisons(comparisons);
    return -1;
}