#pragma once

#include <jni.h>

namespace primes {
namespace android {

// JNIString is a wrapper around a jstring that automatically releases the string when it goes out of scope.
class JNIString {
public:
    JNIString(JNIEnv* InEnv, jstring InJString) noexcept
        : Env(InEnv)
        , JString(InJString)
        , Chars(Env->GetStringUTFChars(JString, nullptr)) {}

    JNIString(JNIString&& Other) {
        Env = Other.Env;
        JString = Other.JString;
        Chars = Other.Chars;
        Other.Env = nullptr;
        Other.JString = nullptr;
        Other.Chars = nullptr;
    }

    ~JNIString() noexcept {
        Env->ReleaseStringUTFChars(JString, Chars);
    }

    const char* Get() const noexcept {
        return Chars;
    }

private:
    JNIEnv* Env;
    jstring JString;
    const char* Chars;
};

}
}