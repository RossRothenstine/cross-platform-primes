#include <jni.h>
#include <android/log.h>
#include "Primes.h"

// From https://github.com/android/ndk-samples/blob/main/hello-jniCallback/app/src/main/cpp/hello-jnicallback.c#L24
// Android log function wrappers
static const char* kTAG = "Primes";
#define LOGI(...) \
  ((void)__android_log_print(ANDROID_LOG_INFO, kTAG, __VA_ARGS__))
#define LOGW(...) \
  ((void)__android_log_print(ANDROID_LOG_WARN, kTAG, __VA_ARGS__))
#define LOGE(...) \
  ((void)__android_log_print(ANDROID_LOG_ERROR, kTAG, __VA_ARGS__))


extern "C"
JNIEXPORT jintArray
JNICALL
Java_com_yuki_prime_lib_Primes_getPrimes(JNIEnv* env, jclass clazz, jstring jniNumberString) {

    const char* numberChars = env->GetStringUTFChars(jniNumberString, nullptr);

    std::string_view number = numberChars;
    LOGI("Number string: %s", numberChars);
    std::vector<int> indices = primes::ParseNumbers(number);
    LOGI("Parsed indices: %d", int(indices.size()));

    primes::GetPrimes(indices);

    jintArray result = env->NewIntArray(indices.size());
    env->SetIntArrayRegion(result, 0, indices.size(), indices.data());

    env->ReleaseStringUTFChars(jniNumberString, numberChars);

    return result;
}