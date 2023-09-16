package com.yuki.prime.lib;

public class Primes {
    static {
        System.loadLibrary("libPrimes");
    }

    public static native int[] getPrimes(String numberString);
}
