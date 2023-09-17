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

    std::string_view number = numberString->Get();
    LOGI("Number string: %s", number.data());
    std::vector<int> indices = primes::ParseNumbers(number);
    LOGI("Parsed indices: %d", int(indices.size()));

    primes::GetPrimes(indices);

    jintArray result = env->NewIntArray(indices.size());
    env->SetIntArrayRegion(result, 0, indices.size(), indices.data());

    return result;
}