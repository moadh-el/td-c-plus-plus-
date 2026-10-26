
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

////////////////exercice 1/////////////////////

void countFrequencyBruteForce(const vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        bool alreadyCounted = false;

        for (int j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                alreadyCounted = true;
            }
        }

        if (alreadyCounted) {
            continue;
        }

        int frequency = 0;
        for (int j = 0; j < numbers.size(); j++) {
            if (numbers[i] == numbers[j]) {
                frequency++;
            }
        }

        cout << numbers[i] << ": " << frequency << " times" << endl;
    }
}



map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    unordered_map<int, int> frequencies;

    for (int number : numbers) {
        frequencies[number] += 1;
    }

    return frequencies;
}

int main(){
    vector<int> numbers = {1,2,3,2,4,1,5,5,6};
    cout << "frequency(Brute Force):" <<endl;
    countFrequencyBruteForce(numbers);


    cout<< "\nFrequency (Optimal): "<< endl;
    map<int,int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal){
        cout << entry.first<< ":" << entry.second<<"times"<<endl;

    }
    return 0;
}


