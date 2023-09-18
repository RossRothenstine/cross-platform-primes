#include <algorithm>
#include "Primes.h"

#define PRIME_EXPORT(ReturnType) extern "C" __declspec(dllexport) ReturnType __cdecl

PRIME_EXPORT(void) DLLGetPrimes(const char* str, int* outLen, int** outPrimes) {
    std::vector<int> primes = primes::ParsePrimes(str);
    *outPrimes = new int[primes.size()];
    *outLen = primes.size();
    std::copy(primes.begin(), primes.end(), *outPrimes);
}

// Unmanaged memory needsexplicitly freed. Perhaps we can wrap the returned Ptr in an IDisposable to make it
// easily freed by the caller?
PRIME_EXPORT(void) DLLFreePrimes(int* primes) {
    delete[] primes;
}