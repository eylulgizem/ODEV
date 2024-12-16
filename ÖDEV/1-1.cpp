#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Rastgele ciro �retimi i�in sabitler
const int MIN_CIRO = 100;
const int MAX_CIRO = 5000;
const int AY_SAYISI = 12;
const int YIL_SAYISI = 5;

int main() {
    srand(time(0)); // Rastgele say� �retimi i�in ba�lang��

    // Ciro verilerini tutan 2D vekt�r
    vector<vector<int>> ciro(YIL_SAYISI, vector<int>(AY_SAYISI));

    // Rastgele ciro verisi olu�turma
    for (int i = 0; i < YIL_SAYISI; i++) {
        for (int j = 0; j < AY_SAYISI; j++) {
            ciro[i][j] = MIN_CIRO + rand() % (MAX_CIRO - MIN_CIRO + 1);
        }
    }

    // Y�ll�k ortalama cirolar� tutan vekt�r
    vector<double> ortciro(YIL_SAYISI, 0);

    // Y�ll�k ortalama cirolar� hesaplama
    for (int i = 0; i < YIL_SAYISI; i++) {
        int toplam = 0;
        for (int j = 0; j < AY_SAYISI; j++) {
            toplam += ciro[i][j];
        }
        ortciro[i] = static_cast<double>(toplam) / AY_SAYISI;
    }

    // Kullan�c�dan y�l se�imi
    int yil;
    cout << "L�tfen 1 ile " << YIL_SAYISI << " aras�nda bir y�l se�in: ";
    cin >> yil;

    if (yil < 1 || yil > YIL_SAYISI) {
        cout << "Ge�ersiz y�l se�imi!" << endl;
        return 1;
    }

    yil--; // Dizilerde y�l 0 tabanl� oldu�u i�in bir azalt�yoruz

    // Se�ilen y�l�n ortalamas�ndan y�ksek olan aylar� yazd�rma
    cout << "\n" << (yil + 1) << ". y�l�n ortalamas�ndan y�ksek olan aylar:\n";
    for (int i = 0; i < AY_SAYISI; i++) {
        if (ciro[yil][i] > ortciro[yil]) {
            cout << "Ay " << (i + 1) << ": " << ciro[yil][i] << endl;
        }
    }

    // Se�ilen y�l�n her �eyre�inin ortalamas�n� hesaplama ve yazd�rma
    cout << "\n" << (yil + 1) << ". y�l�n �eyrek ortalamalar�:\n";
    for (int ceyrek = 0; ceyrek < 4; ceyrek++) {
        int toplam = 0;
        for (int ay = ceyrek * 3; ay < (ceyrek + 1) * 3; ay++) {
            toplam += ciro[yil][ay];
        }
        double ortalama = static_cast<double>(toplam) / 3;
        cout << (ceyrek + 1) << ". �eyrek: " << fixed << setprecision(2) << ortalama << endl;
    }

    return 0;
}

