#include <algorithm>
#include "Primes.h"

// TBH I don't really know what "every" part of this is, but what I could glean:
// extern "C" is a way to tell the compiler to use C linkage for the function.
// __declspec(dllexport) is a way to tell the compiler to expose the function into the DLL.
//      (In days of yore this was done by a linker file in link.exe?)
// __cdecl is a way to tell the compiler to use the C calling convention. The other is a fastcall or vectorcall?
#define PRIME_EXPORT(ReturnType) extern "C" __declspec(dllexport) ReturnType __cdecl

// Unsure if there's a better way to avoid symbol clashing than prefixing with "DLL".
PRIME_EXPORT(void) DLLGetPrimes(const char* str, int* outLen, int** outPrimes) {
    std::string_view input(str);
    std::vector<int> indices = primes::ParseNumbers(input);

    primes::GetPrimes(indices);
    *outPrimes = new int[indices.size()];
    *outLen = indices.size();
    std::copy(indices.begin(), indices.end(), *outPrimes);
}

// Unmanaged memory needs explicitly freed. Perhaps we can wrap the returned Ptr in an IDisposable to make it
// easily freed by the caller?
PRIME_EXPORT(void) DLLFreePrimes(int* primes) {
    delete[] primes;
}