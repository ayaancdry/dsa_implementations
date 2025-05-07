/*
Given a string s, find the length of the longest substring without duplicate 
Characters

 Input Format:
A single string s containing English letters, digits, symbols, and spaces.
The length of s is between 0 and 5 * 10^4.

Output Format:
A single integer representing the length of the longest substring of s that contains no duplicate characters.

Test Case 1
Input:
abcabcbb
Output:
3
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1); // Initialize last index of every character as -1
    int n = s.length();
    int maxLength = 0; // Result
    int start = 0; // Starting index of current window

    for (int end = 0; end < n; end++) {
        // Find the last index of s[end]
        // Update start (starting index of current window)
        if (lastIndex[s[end]] >= start) {
            start = lastIndex[s[end]] + 1;
        }

        // Update result if we get a larger window
        maxLength = max(maxLength, end - start + 1);

        // Update last index of current character
        lastIndex[s[end]] = end;
    }
    return maxLength;
}

int main() {
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}