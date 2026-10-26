#include "SearchingAlgorithm.h"

#include <iomanip>
#include <ostream>

SearchingAlgorithm::SearchingAlgorithm()
    : numberComparisons(0) {}

void SearchingAlgorithm::displaySearchResults(
    std::ostream& output, int results, int target) {
    averageComparisons =
        totalSearch == 0
            ? 0.0
            : static_cast<double>(totalComparisons) /
                  static_cast<double>(totalSearch);

    output << "Target " << target;
    if (results >= 0) {
        output << " trouve a l'indice " << results << ".\n";
    } else {
        output << " non trouve.\n";
    }
    output << "Comparaisons pour cette recherche : "
           << numberComparisons << '\n'
           << "Nombre total de comparaisons : " << totalComparisons << '\n'
           << "Nombre total de recherches : " << totalSearch << '\n'
           << std::fixed << std::setprecision(2)
           << "Moyenne des comparaisons : " << averageComparisons << '\n';
}

int SearchingAlgorithm::getNumberComparisons() const {
    return numberComparisons;
}

long long SearchingAlgorithm::getTotalComparisons() {
    return totalComparisons;
}

long long SearchingAlgorithm::getTotalSearch() {
    return totalSearch;
}

double SearchingAlgorithm::getAverageComparisons() {
    return averageComparisons;
}

void SearchingAlgorithm::resetStatistics() {
    totalComparisons = 0;
    totalSearch = 0;
    averageComparisons = 0.0;
}

void SearchingAlgorithm::setNumberComparisons(int comparisons) {
    numberComparisons = comparisons;
    totalComparisons += numberComparisons;
    ++totalSearch;
    averageComparisons =
        static_cast<double>(totalComparisons) /
        static_cast<double>(totalSearch);
}

long long SearchingAlgorithm::totalComparisons = 0;
long long SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;
