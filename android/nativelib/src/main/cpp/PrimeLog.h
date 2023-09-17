#pragma once

#include <android/log.h>

// From https://github.com/android/ndk-samples/blob/main/hello-jniCallback/app/src/main/cpp/hello-jnicallback.c#L23
// Android log function wrappers
static const char* kTAG = "Primes";
#define LOGI(...) \
  ((void)__android_log_print(ANDROID_LOG_INFO, kTAG, __VA_ARGS__))
#define LOGW(...) \
  ((void)__android_log_print(ANDROID_LOG_WARN, kTAG, __VA_ARGS__))
#define LOGE(...) \
  ((void)__android_log_print(ANDROID_LOG_ERROR, kTAG, __VA_ARGS__))
