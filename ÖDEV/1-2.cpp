#include <iostream>
#include <vector>
#include <iomanip>
#include <locale.h>
using namespace std;

const int x = 3;

void matrisToplam(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrisCarpim(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            C[i][j] = 0;
            for (int k = 0; k < x; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

double matrisDeterminant(const vector<vector<int>> &A) {
    return A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
         - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
         + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
}

void matrisYazdir(const vector<vector<int>> &M, const string &baslik) {
    cout << baslik << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << setw(5) << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> A(x, vector<int>(x));
    vector<vector<int>> B(x, vector<int>(x));
    vector<vector<int>> C(x, vector<int>(x));

    cout << "Matris A elemanlarini giriniz:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Matris B elemanlarini giriniz:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cin >> B[i][j];
        }
    }

    matrisToplam(A, B, C);
    matrisYazdir(C, "A + B Matrisinin Toplami:");

    matrisCarpim(A, B, C);
    matrisYazdir(C, "A x B Matrisinin Carpimi:");

    double detA = matrisDeterminant(A);
    cout << "Matris A'nin Determinanti: " << detA << endl;

    return 0;
}
