// guess the random number between 1 and 10
// code by Ryuya Hirota

#include <iostream>
#include <chrono>
#include <random>
#include <limits>

int main() {
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count(); // get current time
    std::default_random_engine generator(seed); // create random number generator with current time as a seed
    std::uniform_int_distribution<int> distribution(1, 10); // with a uniform distribution of type int between 1 and 10
    
    int number = distribution(generator); // get random number
    int guess = -999;
    std::cout << "Guess the number between 1 and 10: " << std::endl;
    std::cin >> guess;
    
    while (guess != number) {
        std::cout << "Wrong number, guess again:" << std::endl;
        std::cin >> guess;
        
        // CLEAR THE BUFFER IN CASE INPUT ISN'T AN INT
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    
    std::cout << "You guessed the secret number!" << std::endl;
    
    return 0;
}
