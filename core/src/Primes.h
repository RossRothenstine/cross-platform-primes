#pragma once

#include <vector>
#include <string>

namespace primes {

// ParseNumbers will find the numbers within a given string.
// TODO: Unicode support? wstring? Maybe our string impl is already aware, or our platform char is not a simple byte.
// If there was ever a way to be given invalid input, returning std::optional might be the play with nullopt.
[[nodiscard]] std::vector<int> ParseNumbers(const std::string_view& input) noexcept;

// Given an array of prime indices (e.g., 1, 2, 3), return an array of those prime numbers.
// E.g., 1, 3, 5.
void GetPrimes(std::vector<int>& indicies) noexcept;

// Return the given Prime at index. This isn't necessary to be exposed via header, but for the sake of testing
// it is exposed.
[[nodiscard]] constexpr int FindPrimeAt(int index) noexcept;

}
