#include "LinearSearch.h"

int LinearSearch::search(std::vector<int> values, int element) {
    numberComparisons = 0;

    for (size_t i = 0; i < values.size(); ++i) {
        ++numberComparisons;

        if (values[i] == element) {
            setNumberComparisons(numberComparisons);
            return static_cast<int>(i);
        }
    }

    setNumberComparisons(numberComparisons);
    return -1;
}