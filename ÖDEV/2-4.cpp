#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL,"Turkish");
    const int x = 500;
    vector<int> numbers(x);

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < x; i++) 
	{
        numbers[i] = 10 + rand() % 26;
    }

    cout << "10-35 aras�nda rastgele olu�turulan say�lar:" << endl;
    for (int i = 0; i < x; i++) 
	{
        cout << numbers[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }

    double average = accumulate(numbers.begin(), numbers.end(), 0.0) / x;
    cout << "\nAritmetik ortalama: " << average << endl;

    int minVal = *min_element(numbers.begin(), numbers.end());
    int maxVal = *max_element(numbers.begin(), numbers.end());
    cout << "En k���k de�er: " << minVal << endl;
    cout << "En b�y�k de�er: " << maxVal << endl;

    map<int, int> frequency;
    for (int num : numbers) 
	{
        frequency[num]++;
    }

    cout << "\nFrekanslar:" << endl;
    for (const auto &pair : frequency)
	{
        cout << pair.first << "'den " << pair.second << " adet" << endl;
    }

    vector<int> evens, odds;
    for (int num : numbers) 
	{
        if (num % 2 == 0) 
		{
            evens.push_back(num);
        } 
		else 
		{
            odds.push_back(num);
        }
    }

    cout << "\n�ift say�lar:" << endl;
    for (int num : evens) 
	{
        cout << num << " ";
    }
    cout << "\n\nTek say�lar:" << endl;
    for (int num : odds) 
	{
        cout << num << " ";
    }

    vector<int> belowAverage, aboveAverage;
    for (int num : numbers) {
        if (num < average) {
            belowAverage.push_back(num);
        } else {
            aboveAverage.push_back(num);
        }
    }

    cout << "\n\nOrtalamadan k���k olanlar:" << endl;
    for (int num : belowAverage) {
        cout << num << " ";
    }
    cout << "\n\nOrtalamadan b�y�k veya e�it olanlar:" << endl;
    for (int num : aboveAverage) {
        cout << num << " ";
    }

    return 0;
}

