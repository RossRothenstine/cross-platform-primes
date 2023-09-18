#pragma once

#include <vector>
#include <string>

namespace primes {

// ParsePrimes will take a number string input and return an array of the prime indices.
// E.g., "Hello 2, 4, 7.5" will return {3, 7, 17}.
[[nodiscard]] std::vector<int> ParsePrimes(std::string_view input) noexcept;

// ParseNumbers will find the numbers within a given string.
// E.g., "1, Hello, 2, 3" will return {1, 2, 3}.
// TODO: Unicode support? wstring? Maybe our string impl is already aware, or our platform char is not a simple byte.
// If there was ever a way to be given invalid input, returning std::optional might be the play with nullopt.
[[nodiscard]] std::vector<int> ParseNumbers(std::string_view input) noexcept;

// Given an array of prime indices (e.g., 1, 2, 3), put the corresponding prime index into the array at
// the same location., e.g., (2, 3, 5).
void GetPrimes(std::vector<int>& indices) noexcept;

// Return the given Prime at index. This isn't necessary to be exposed via header, but for the sake of testing
// it is exposed.
[[nodiscard]] constexpr int FindPrimeAt(int index) noexcept;

}
