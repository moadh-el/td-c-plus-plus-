#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include "SearchingAlgorithm.h"

class LinearSearch : public SearchingAlgorithm {
public:
    using SearchingAlgorithm::SearchingAlgorithm;

    int search(std::vector<int> values, int element) override;
};

#endif
