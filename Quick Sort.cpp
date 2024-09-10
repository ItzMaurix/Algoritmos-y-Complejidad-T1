#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int bajo, int alto) {
    int pivote = arr[alto];
    int i = bajo - 1;
    for (int j = bajo; j <= alto - 1; j++) {
        if (arr[j] < pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[alto]);  
    return i + 1;
}

void quickSort(vector<int>& arr, int bajo, int alto) {
    if (bajo < alto) {
        int pivote = partition(arr, bajo, alto);
        quickSort(arr, bajo, pivote - 1);
        quickSort(arr, pivote + 1, alto);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    cout << "Sorted Array\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}