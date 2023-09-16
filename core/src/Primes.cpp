#include "Primes.h"
#include <algorithm>
#include <array>
#include <thread>

namespace primes {

[[nodiscard]] constexpr bool IsPrime(int number) noexcept {
    if (number == 0 || number == 1) {
        return false;
    }

    // There is no point in going past the square root of the number.
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

// TODO: Do we cache these primes for later use? Could the primeness of a previously calculated number be used
// when called with the index in the future?
// Compile time optimization: generate N primes and store them in a lookup array. e.g., (1, 2), (2, 3), (3, 5), (4, 7), etc.
// if index is < max primes, use lookup table. Otherwise, calculate the prime (starting from the end of the table).
[[nodiscard]] constexpr int FindPrimeAt(int index) noexcept {
    int number = 0;
    int count = 0;
    while (count < index) {
        ++number;
        if (IsPrime(number)) {
            ++count;
        }
    }
    return number;
}

std::vector<int> ParseNumbers(const std::string_view& input) noexcept {
    std::vector<int> output;

    constexpr char charZero = '0';
    constexpr char charNine = '9';
    constexpr char charDot = '.';

    int digit = 0;
    int number = 0;

    size_t length = input.length();
    bool decimalFlag = false;

    // This is a very crude lexing design. It could be improved
    // in the future if more tokens or states are added.

    for (int i = 0; i < length; ++i) {
        char c = input[i];

        if (c == charDot) {
            decimalFlag = true;
            continue;
        }

        if (c < charZero || c > charNine) {
            decimalFlag = false;
            if (digit > 0) {
                output.push_back(number);
                number = 0;
            }
            digit = 0;
            continue;
        }

        if (decimalFlag) {
            // skipping floats.
            continue;
        }

        number *= 10;
        number += c - charZero;
        ++digit;
    }

    if (digit > 0) {
        // reached end of line while processing, add the remaining number.
        output.push_back(number);
    }


    return output;
}

void GetPrimes(std::vector<int>& indicies) noexcept {
    std::vector<std::thread> threads;
    threads.reserve(indicies.size());

    for (int i = 0; i < indicies.size(); ++i) {
        int index = indicies[i];
        threads.emplace_back([&indicies, i, index]() {
            int prime = FindPrimeAt(index);
            indicies[i] = prime;
        });
    }

    // wait for the threads to finish.
    for (std::thread& thread : threads) {
        thread.join();
    }
}
}