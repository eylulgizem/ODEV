#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL,"Turkish");
    const int x = 500;
    vector<float> numbers(x);

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < x; i++) {
        numbers[i] = static_cast<float>(rand()) / RAND_MAX;
    }

    cout << "0-1 arasýnda rastgele oluþturulan sayýlar:" << endl;
    for (int i = 0; i < x; i++) {
        cout << fixed << setprecision(6) << numbers[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }

    return 0;
}

