/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence. 
You must write an algorithm that runs in O(n) time.
Input Format: An integer array nums containing unsorted elements. 
Output Format: An integer representing the length of the longest consecutive elements sequence.

Sample Test Cases:
 Input: nums = [100,4,200,1,3,2],   Output: 4 

Constraints: 
0 <= nums.length <= 10^5 
-10^9 <= nums[i] <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
    int longestStreak = 0;

    for (int num : s) {
        if (!s.count(num - 1)) {  
            int currentNum = num;
            int currentStreak = 1;

            while (s.count(currentNum + 1)) {
                currentNum++;
                currentStreak++;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = longestSuccessiveElements(a);
    cout << ans << endl;
    return 0;
}