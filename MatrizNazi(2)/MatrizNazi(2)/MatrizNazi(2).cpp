#include <iostream>

using namespace std;

int A[3][3][3] = { {{1,2,3},{4,5,6},{7,8,9}},{{10,11,12},{13,14,15},{16,17,18}},{{0,0,0},{0,0,0},{0,0,0}} };

void multiplicarMatriz(int A[3][3][3]) {
    int* M1 = &A[0][0][0];
    int* M2 = &A[1][0][0];
    int* M3 = &A[2][0][0];

    int(*Ini_M2)[3] = &A[1][0];
    int(*Ini_M3)[3] = &A[2][0];

    int* Fin_M1 = &A[0][0][2];


    for (; M1 < M2; M1++) {
        if (M1 <= Fin_M1) {
            *M3 += *M1 * *M2;
            *(M3 += 1) += *M1 * *(M2 += 1);
            *(M3 += 1) += *M1 * *(M2 += 1);
            M3 = (int*)Ini_M3;
            Ini_M2 += 1;
            M2 = (int*)Ini_M2;
        }
        if (M1 == Fin_M1) {
            Fin_M1 += 3;
            M2 = &A[1][0][0];
            Ini_M2 = &A[1][0];
            Ini_M3 += 1;
            M3 = (int*)Ini_M3;
        }
    }
}
void imprimirMatriz(int A[3][3][3]) {
    int* p = &A[0][0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << *(p + (i * 9) + (j * 3) + k) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
int main()
{
    multiplicarMatriz(A);
    imprimirMatriz(A);
}