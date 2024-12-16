#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>  

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<float> randomNumbers;

    for (int i = 0; i < 500; ++i) {
        float randomFloat = static_cast<float>(std::rand()) / RAND_MAX * 100.0f;
        randomNumbers.push_back(randomFloat);
    }

    std::cout << "Rastgele sayýlar :" << std::endl;
    for (const float& number : randomNumbers) {
        std::cout << number << " ";
    }

    std::cout << std::endl;

    return 0;
}

