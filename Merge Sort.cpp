#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr, int izquierda, int medio, int derecha){
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[izquierda + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[medio + 1 + j];
    int i = 0, j = 0;
    int k = izquierda;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int izquierda, int derecha){
    if (izquierda >= derecha)
        return;

    int medio = izquierda + (derecha - izquierda) / 2;
    mergeSort(arr, izquierda, medio);
    mergeSort(arr, medio + 1, derecha);
    merge(arr, izquierda, medio, derecha);
}

void printVector(vector<int>& arr){
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;
}