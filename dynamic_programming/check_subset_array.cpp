/*
Given two arrays a[] and b[] of size m and n respectively, the task is to determine whether b[] is a subset of a[]. Both arrays are not sorted, and elements are distinct.
Example: Input: a[] = [11, 1, 13, 21, 3, 7], b[] = [11, 3, 7, 1] 
Output: true

Input: a[]= [1, 2, 3, 4, 5, 6], b = [1, 2, 4] 
Output: true

Input: a[] = [10, 5, 2, 23, 19], b = [19, 5, 3] 
Output: false
*/

//Your code
#include <bits/stdc++.h>
using namespace std;

bool isSubset(vector<int>& a, vector<int>& b) {
    unordered_set<int> elements(a.begin(), a.end());

    for (int num : b) {
        if (elements.find(num) == elements.end()) {
            return false; // if any element of b[] is not found in a[]
        }
    }

    return true;
}


int main() {
    int m, n;

    
    
    cin >> m;
    vector<int> a(m);
    
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    // Taking input for the second array
    
    cin >> n;
    vector<int> b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Check if b[] is a subset of a[]
    if (isSubset(a, b)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}