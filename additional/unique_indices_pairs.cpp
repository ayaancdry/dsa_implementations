/*
Problem Statement : Given an array of integers nums and an integer target, find all unique pairs of indices (i, j) such that:
nums[i] + nums[j] = target
i not equal to j (each number can be used only once)
Return a list of all such index pairs. If no valid pairs exist, return an empty list
Input Format : 
An integer n representing the number of elements in the array.
A list of n space-separated integers representing the array nums.
An integer target representing the required sum.
Output Format : 
If valid pairs exist, print each pair of indices [i, j] where nums[i] + nums[j] = target.
If no valid pairs exist, print "No pairs found."
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> findPairs(vector<int>& nums, int target) {
    unordered_map<int, int> indexMap; // Stores element values and their indices
    vector<pair<int, int>> result;   // Stores result pairs

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // Check if complement exists in the map
        if (indexMap.find(complement) != indexMap.end()) {
            result.push_back({indexMap[complement], i});
        }

        // Store the current element in the map
        indexMap[nums[i]] = i;
    }

    return result;
}

int main() {
    int n, target;
    
    // Matching the expected output format
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " space-separated integers: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<pair<int, int>> pairs = findPairs(nums, target);

    if (pairs.empty()) {
        cout << "No pairs found." << endl;
    } else {
        for (auto& p : pairs) {
            cout << "[" << p.first << ", " << p.second << "]" << endl;
        }
    }

    return 0;
}
