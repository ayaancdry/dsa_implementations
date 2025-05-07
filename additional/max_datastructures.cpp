/*
Given a string text, you want to use the characters of text to form as many instances of the word "datastructures" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

Hint: Use Hashmap

Example:
Input: "datastructuresdatastructures"
Expected Output: 2
Explanation: The input contains exactly two instances of "datastructures".

Input: "data"
Expected Output: 0
Explanation: The input contains no instances of "datastructures".

Constraints:
1 <= text.length <= 10^4
text consists of lower case English letters only.
*/

#include <bits/stdc++.h>

using namespace std;

int solution(string text) {
    unordered_map<char, int> char_count;
    for (char c : text) {
        char_count[c]++;
    }

    string target = "datastructures";
    unordered_map<char, int> target_count;
    for (char c : target) {
        target_count[c]++;
    }

    int min_instances = INT_MAX;
    for (auto& pair : target_count) {
        char c = pair.first;
        int count = pair.second;
        min_instances = min(min_instances, char_count[c] / count);
    }

    return min_instances;
}

int main() {
    string text;
    getline(cin, text); 

    int result = solution(text);
    cout << result << endl;

    return 0;
}