#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H

#include "SearchingAlgorithm.h"

class JumpSearch : public SearchingAlgorithm {
public:
    using SearchingAlgorithm::SearchingAlgorithm;

    int search(std::vector<int> values, int element) override;
};

#endif
