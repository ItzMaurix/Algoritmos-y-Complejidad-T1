#include <iostream>
#include <vector>

using namespace std;

void addMatrix(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtractMatrix(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassenMultiplication(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    vector<int> inner(newSize); // Vector interno para las submatrices

    // Inicializar las submatrices
    vector<vector<int>> A11(newSize, inner), A12(newSize, inner), A21(newSize, inner), A22(newSize, inner);
    vector<vector<int>> B11(newSize, inner), B12(newSize, inner), B21(newSize, inner), B22(newSize, inner);
    vector<vector<int>> C11(newSize, inner), C12(newSize, inner), C21(newSize, inner), C22(newSize, inner);
    vector<vector<int>> M1(newSize, inner), M2(newSize, inner), M3(newSize, inner), M4(newSize, inner);
    vector<vector<int>> M5(newSize, inner), M6(newSize, inner), M7(newSize, inner);
    vector<vector<int>> tempA(newSize, inner), tempB(newSize, inner);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    addMatrix(A11, A22, tempA, newSize);
    addMatrix(B11, B22, tempB, newSize);
    strassenMultiplication(tempA, tempB, M1, newSize);

    // M2 = (A21 + A22) * B11
    addMatrix(A21, A22, tempA, newSize);
    strassenMultiplication(tempA, B11, M2, newSize);

    // M3 = A11 * (B12 - B22)
    subtractMatrix(B12, B22, tempB, newSize);
    strassenMultiplication(A11, tempB, M3, newSize);

    // M4 = A22 * (B21 - B11)
    subtractMatrix(B21, B11, tempB, newSize);
    strassenMultiplication(A22, tempB, M4, newSize);

    // M5 = (A11 + A12) * B22
    addMatrix(A11, A12, tempA, newSize);
    strassenMultiplication(tempA, B22, M5, newSize);

    // M6 = (A21 - A11) * (B11 + B12)
    subtractMatrix(A21, A11, tempA, newSize);
    addMatrix(B11, B12, tempB, newSize);
    strassenMultiplication(tempA, tempB, M6, newSize);

    // M7 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A12, A22, tempA, newSize);
    addMatrix(B21, B22, tempB, newSize);
    strassenMultiplication(tempA, tempB, M7, newSize);

    // C11 = M1 + M4 - M5 + M7
    addMatrix(M1, M4, tempA, newSize);
    subtractMatrix(tempA, M5, tempB, newSize);
    addMatrix(tempB, M7, C11, newSize);

    // C12 = M3 + M5
    addMatrix(M3, M5, C12, newSize);

    // C21 = M2 + M4
    addMatrix(M2, M4, C21, newSize);

    // C22 = M1 - M2 + M3 + M6
    subtractMatrix(M1, M2, tempA, newSize);
    addMatrix(tempA, M3, tempB, newSize);
    addMatrix(tempB, M6, C22, newSize);

    // Combinar las submatrices de C en la matriz resultante
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

void printMatrix(vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;  // Tamaño de la matriz (potencia de 2)
    
    vector<vector<int>> A = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
    vector<vector<int>> B = { {1, 0, 0, 1}, {0, 1, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 1} };
    vector<vector<int>> C(n, vector<int>(n));
    
    strassenMultiplication(A, B, C, n);
    
    cout << "Matriz Resultado:" << endl;
    printMatrix(C, n);
    
    return 0;
}
