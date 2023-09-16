using System;
using System.Runtime.InteropServices;

namespace Primes {
    public class Library {

        private class Externs {
            [DllImport("PrimeLibraryDLL.dll")]
            public static extern void DLLGetPrimes(string input, out int length, out IntPtr nativePrimes);
            [DllImport("PrimeLibraryDLL.dll")]
            public static extern void DLLFreePrimes(IntPtr primeArray);
        }

        public static int[] GetPrimes(string input) {
            IntPtr nativePrimes;

            Externs.DLLGetPrimes(input, out int w, out nativePrimes);

            int[] returnPrimes = new int[w];
            Marshal.Copy(nativePrimes, returnPrimes, 0, w);
            Externs.DLLFreePrimes(nativePrimes);

            return returnPrimes;
        }
    }
}