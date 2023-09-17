package com.yuki.prime.lib;

public class Primes {
    static {
        System.loadLibrary("PrimesAndroid");
    }

    public static native int[] getPrimes(String numberString);
}
