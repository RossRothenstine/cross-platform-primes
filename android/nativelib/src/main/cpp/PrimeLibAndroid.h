#pragma once

#include <jni.h>

namespace primes {
namespace android {

// JNIString is a wrapper around a jstring that automatically releases the string when it goes out of scope.
class JNIString {
public:
    JNIString(JNIEnv* env_, jstring jString_) noexcept
        : env(env_)
        , jString(jString_)
        , chars(env->GetStringUTFChars(jString, nullptr)) {}

    JNIString(JNIString&& other) noexcept
        : env(other.env)
        , jString(other.jString)
        , chars(other.chars)
    {
        other.env = nullptr;
        other.jString = nullptr;
        other.chars = nullptr;
    }

    ~JNIString() noexcept {
        if (env && jString && chars) {
            env->ReleaseStringUTFChars(jString, chars);
        }
    }

    const char* Get() const noexcept {
        return chars;
    }

private:
    JNIEnv* env;
    jstring jString;
    const char* chars;
};

}
}