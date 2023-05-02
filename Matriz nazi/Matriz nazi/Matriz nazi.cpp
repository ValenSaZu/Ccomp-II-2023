#include <iostream>

using namespace std;

int A[3][3][3] = { {{1,2,3},{4,5,6},{7,8,9}},{{10,11,12},{13,14,15},{16,17,18}},{{0,0,0},{0,0,0},{0,0,0}} };

void multiplicarMatriz(int A[3][3][3]) {
    int(*M1)[3] = &A[0][0];
    int(*M2)[3] = &A[1][0];
    int(*M3)[3] = &A[2][0];
    for (int i{ 0 }, j{ 0 }; i <= 8; i++, j++) {
        int a = (*M1)[i];
        int b = (*M2)[j * 3];
        int c = (*M2)[(j * 3) + 1];
        int d = (*M2)[(j * 3) + 2];
        if (i <= 2) {
            (*M3)[0] += (a * b);
            (*M3)[1] += (a * c);
            (*M3)[2] += (a * d);
        }
        if (i <= 5 && i>=3) {
            (*M3)[3] += (a * b);
            (*M3)[4] += (a * c);
            (*M3)[5] += (a * d);
        }
        if (i <= 8 && i >= 6) {
            (*M3)[6] += (a * b);
            (*M3)[7] += (a * c);
            (*M3)[8] += (a * d);
        }
        if (j == 2) {
            j = -1;
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