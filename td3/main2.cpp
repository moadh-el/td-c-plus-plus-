
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


////////////////exercice 2

vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {nums[i], nums[j]};
            }
        }
    }

    return {};
}

vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> numbers;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int complement = target - nums[i];
        if (numbers.find(complement) != numbers.end()) {
            return {nums[i], complement};
        }
        numbers[nums[i]] = i;
    }

    return {};
}


int main() {
    vector<int> nums= {2,7,11,15};
    int target=9;
    vector<int> indicebruteForce = twoSumBruteForce(nums,target);
    cout<<"Brute Force Solution: ["
        <<indicebruteForce[0]
        <<","
        <<indicebruteForce[1]
        <<"]"
        <<endl;

    vector<int> indiceOptimal = twoSumOptimal(nums,target);
        cout<<"Optimal Solution: ["
            <<indiceOptimal[0]
            <<","
            <<indiceOptimal[1]
            <<"]"
            <<endl;

    return 0;
}






