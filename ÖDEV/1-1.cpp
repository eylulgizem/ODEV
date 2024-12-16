#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Rastgele ciro üretimi için sabitler
const int MIN_CIRO = 100;
const int MAX_CIRO = 5000;
const int AY_SAYISI = 12;
const int YIL_SAYISI = 5;

int main() {
    srand(time(0)); // Rastgele sayý üretimi için baþlangýç

    // Ciro verilerini tutan 2D vektör
    vector<vector<int>> ciro(YIL_SAYISI, vector<int>(AY_SAYISI));

    // Rastgele ciro verisi oluþturma
    for (int i = 0; i < YIL_SAYISI; i++) {
        for (int j = 0; j < AY_SAYISI; j++) {
            ciro[i][j] = MIN_CIRO + rand() % (MAX_CIRO - MIN_CIRO + 1);
        }
    }

    // Yýllýk ortalama cirolarý tutan vektör
    vector<double> ortciro(YIL_SAYISI, 0);

    // Yýllýk ortalama cirolarý hesaplama
    for (int i = 0; i < YIL_SAYISI; i++) {
        int toplam = 0;
        for (int j = 0; j < AY_SAYISI; j++) {
            toplam += ciro[i][j];
        }
        ortciro[i] = static_cast<double>(toplam) / AY_SAYISI;
    }

    // Kullanýcýdan yýl seçimi
    int yil;
    cout << "Lütfen 1 ile " << YIL_SAYISI << " arasýnda bir yýl seçin: ";
    cin >> yil;

    if (yil < 1 || yil > YIL_SAYISI) {
        cout << "Geçersiz yýl seçimi!" << endl;
        return 1;
    }

    yil--; // Dizilerde yýl 0 tabanlý olduðu için bir azaltýyoruz

    // Seçilen yýlýn ortalamasýndan yüksek olan aylarý yazdýrma
    cout << "\n" << (yil + 1) << ". yýlýn ortalamasýndan yüksek olan aylar:\n";
    for (int i = 0; i < AY_SAYISI; i++) {
        if (ciro[yil][i] > ortciro[yil]) {
            cout << "Ay " << (i + 1) << ": " << ciro[yil][i] << endl;
        }
    }

    // Seçilen yýlýn her çeyreðinin ortalamasýný hesaplama ve yazdýrma
    cout << "\n" << (yil + 1) << ". yýlýn çeyrek ortalamalarý:\n";
    for (int ceyrek = 0; ceyrek < 4; ceyrek++) {
        int toplam = 0;
        for (int ay = ceyrek * 3; ay < (ceyrek + 1) * 3; ay++) {
            toplam += ciro[yil][ay];
        }
        double ortalama = static_cast<double>(toplam) / 3;
        cout << (ceyrek + 1) << ". çeyrek: " << fixed << setprecision(2) << ortalama << endl;
    }

    return 0;
}

