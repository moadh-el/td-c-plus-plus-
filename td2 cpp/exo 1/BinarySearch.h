#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "SearchingAlgorithm.h"

class BinarySearch : public SearchingAlgorithm {
public:
    using SearchingAlgorithm::SearchingAlgorithm;

    int search(std::vector<int> values, int element) override;
};

#endif
