#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int tamano){
    int i, j;
    bool swapped;
    for (i = 0; i < tamano - 1; i++){
        swapped = false;
        for (j = 0; j < tamano - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void printArray(int arr[], int tamano){
    int i;
    for (i = 0; i < tamano; i++)
        cout << " " << arr[i];
}

int main(){
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int tamano = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, tamano);
    cout << "Arreglo ordenado: \n";
    printArray(arr, tamano);
    return 0;
}