/*
Given a string, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
Return the sorted string.
*/
#include <iostream>
using namespace std;

string frequencySort(string s) {
    int freq[256] = {0};
    for (char c : s) {
        freq[c]++;
    }

    string result;
    while (true) {
        int maxFreq = 0;
        char maxChar;
        for (int i = 0; i < 256; ++i) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }
        if (maxFreq == 0) break;
        result.append(maxFreq, maxChar);
        freq[maxChar] = 0;
    }

    return result;
}

int main() {
    string s;
    cin >> s;
    cout << frequencySort(s) << endl;
    return 0;
}