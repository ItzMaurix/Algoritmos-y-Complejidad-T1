#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int tamano){
    for (int i = 0; i < tamano - 1; i++){
        int elemento_minimo = i;
        for (int j = i + 1; j < tamano; j++){
            if (arr[j] < arr[elemento_minimo])
                elemento_minimo = j;
        }
        if (elemento_minimo != i)
            swap(arr[elemento_minimo], arr[i]);
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {64, 25, 12, 22, 11, 500, 20, 14, 17, 245, 114};
    int tamano = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, tamano);
    cout << "Sorted array: \n";
    printArray(arr, tamano);
    return 0;
}