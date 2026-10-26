#include "JumpSearch.h"
#include <algorithm>
#include <cmath>

int JumpSearch::search(std::vector<int> list, int target) {
    int comparisons = 0;
    size_t n = list.size();

    if (n == 0) {
        setNumberComparisons(0);
        return -1;
    }

    size_t step = static_cast<size_t>(sqrt(n));
    if (step == 0) {
        step = 1;
    }
    size_t prev = 0;

    while (list[std::min(step, n) - 1] < target) {
        ++comparisons;
        prev = step;
        step += static_cast<size_t>(sqrt(n));

        if (prev >= n) {
            setNumberComparisons(comparisons);
            return -1;
        }
    }

    for (size_t i = prev; i < std::min(step, n); ++i) {
        ++comparisons;

        if (list[i] == target) {
            setNumberComparisons(comparisons);
            return static_cast<int>(i);
        }
    }

    setNumberComparisons(comparisons);
    return -1;
}