/*
Problem Statement:
You are given a list of N employees, where each employee has a unique Employee ID and a Salary. Sort the employees in descending order of Salary using Quick Sort. If two employees have the same salary, sort them by ascending Employee ID.

Input Format:
An integer N  the number of employees.
The next N lines contain two space-separated integers:
Employee ID 
Salary 

Output Format:
Print N lines, each containing the Employee ID and Salary in sorted order.

Sample Input:
4  
201 50000  
202 70000  
203 70000  
204 60000  

Sample Output:
202 70000  
203 70000  
204 60000  
201 50000
*/

#include <iostream>
#include <vector>
using namespace std;
// Function to partition the array
int partition(vector<pair<int, int>> &employees, int low, int high) {
    int pivot = employees[high].second;  // Pivot salary
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (employees[j].second > pivot || (employees[j].second == pivot && employees[j].first < employees[high].first)) {
            i++;
            swap(employees[i], employees[j]);
        }
    }
    swap(employees[i + 1], employees[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<pair<int, int>> &employees, int low, int high) {
    if (low < high) {
        int pi = partition(employees, low, high);

        quickSort(employees, low, pi - 1);
        quickSort(employees, pi + 1, high);
    }
}

int main() {
    int N;
    cin >> N;  // Number of employees

    vector<pair<int, int>> employees(N);
    for (int i = 0; i < N; i++) {
        cin >> employees[i].first >> employees[i].second;  // Employee ID and Salary
    }

    // Call Quick Sort function
    quickSort(employees, 0, N - 1);

    // Output the sorted employees
    for (auto &emp : employees) {
        cout << emp.first << " " << emp.second << endl;
    }

    return 0;
}