#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<int> randomNumbers;

    for (int i = 0; i < 500; ++i) {
        int randomNumber = 25 + (std::rand() % 11); 
        randomNumbers.push_back(randomNumber);
    }

    std::cout << "Rastgele say�lar =" << std::endl;
    for (const int& number : randomNumbers) {
        std::cout << number << " ";
    }

    std::cout << std::endl;

    return 0;
}

