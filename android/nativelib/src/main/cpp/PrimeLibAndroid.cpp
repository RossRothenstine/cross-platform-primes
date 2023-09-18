#include <jni.h>
#include "Primes.h"
#include "PrimeLibAndroid.h"
#include "PrimeLog.h"

using namespace primes::android;

extern "C"
JNIEXPORT jintArray
JNICALL
Java_com_yuki_prime_lib_Primes_getPrimes(JNIEnv* env, jclass clazz, jstring jniNumberString) {

    std::unique_ptr<JNIString> numberString = std::make_unique<JNIString>(env, jniNumberString);

    LOGI("Number string: %s", numberString->Get());
    std::vector<int> primes = primes::ParsePrimes(numberString->Get());
    LOGI("Parsed primes size: %d", int(primes.size()));

    jintArray result = env->NewIntArray(primes.size());
    env->SetIntArrayRegion(result, 0, primes.size(), primes.data());

    return result;
}