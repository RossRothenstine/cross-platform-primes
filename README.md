# Cross Platform Primes

## Getting Started

### Required Software

 - [CMake](https://cmake.org/download/) (>= 3.21.0)
 - (Windows) [Visual Studio](https://visualstudio.microsoft.com/downloads/)
 - (Android) [Android Studio](https://developer.android.com/studio)

### Building


#### Win32

```powershell
cd win32\PrimeLibrary
mkdir build
cmake -B build -S .
cmake --build build --config Release
# Artifacts will be in build/bin
```

#### Android

```bash
cd android
./gradlew :nativelib:assembleRelease
```

### Unit Testing

All platforms support WITH_TESTS to build test executables except Android, whose tests are facilitated by the Android Studio test runner.

#### Win32

```powershell
cd win32\PrimeLibrary
mkdir build
cmake -B build -S . -DWITH_TESTS=ON
cmake --build build --config Debug
.\build\bin\PrimeLibraryTests.exe
```

#### Android

Android is tested via the Android Studio test runner, which uses emulated device testing.

```bash
cd android
./gradlew :nativelib:test
```

### Integration Testing

#### Win32

TBD. Needs a C# WPF app.

#### Android

To run on device testing.

```bash
cd android
./gradlew :nativelib:connectedAndroidTest
```

Also, check out the sample application under `android/app`.