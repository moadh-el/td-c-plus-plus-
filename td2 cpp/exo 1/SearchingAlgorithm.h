#ifndef SEARCHING_ALGORITHM_H
#define SEARCHING_ALGORITHM_H

#include <iosfwd>
#include <vector>

class SearchingAlgorithm {
public:
    SearchingAlgorithm();
    virtual ~SearchingAlgorithm() = default;

    virtual int search(std::vector<int> values, int element) = 0;

    void displaySearchResults(std::ostream& output, int results, int target);

    int getNumberComparisons() const;
    static long long getTotalComparisons();
    static long long getTotalSearch();
    static double getAverageComparisons();
    static void resetStatistics();

    int numberComparisons;

    static long long totalComparisons;
    static long long totalSearch;
    static double averageComparisons;

protected:
    void setNumberComparisons(int comparisons);
};

#endif
