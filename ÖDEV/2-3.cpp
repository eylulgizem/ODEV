#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <locale.h>
using namespace std;

int main() {
    const int x = 500;
    vector<int> numbers(x);

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < x; i++) {
        numbers[i] = 10 + rand() % 26;
    }

    cout << "10-35 arasinda rastgele olusturulan sayýlar:" << endl;
    for (int i = 0; i < x; i++) {
        cout << numbers[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }

    return 0;
}
