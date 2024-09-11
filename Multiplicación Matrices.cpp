#include <bits/stdc++.h>
using namespace std;

#define F1 2 // Número de filas en matriz-1
#define C1 2 // Número de columnas en matriz-1
#define F2 2 // Número de filas en matriz-2
#define C2 2 // Número de columnas en matriz-2

void mulMat(int mat1[][C1], int mat2[][C2]){
    int rslt[F1][C2];

    cout << "La multiplicación de dos matrices dadas es:\n";

    for (int i = 0; i < F1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < F2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }

            cout << rslt[i][j] << "\t";
        }

        cout << endl;
    }
}

int main(){
    int mat1[F1][C1] = { { 1, 1 },
                         { 2, 2 } };

    int mat2[F2][C2] = { { 1, 1 },
                         { 2, 2 } };

    if (C1 != F2) {
        cout << "El número de columnas en la matriz 1 debe "
                "ser igual al número de filas en "
                "la matriz-2" << endl;
        cout << "Por favor, actualiza las MACROs de acuerdo al tamaño "
                "de tu arreglo en la sección #define" << endl;

        exit(EXIT_FAILURE);
    }
    mulMat(mat1, mat2);
    return 0;
}