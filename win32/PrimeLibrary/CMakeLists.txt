# TODO: maybe make a PrimesApp as a Win32 application that uses PrimeLibrary.
cmake_minimum_required( VERSION 3.22.1 )

project( 
    PrimeLibrary
    LANGUAGES
        CXX
        CSharp
    VERSION
        1.0.0
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib 
    CACHE PATH "Output directory for static libraries.")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    CACHE PATH "Output directory for shared libraries.")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    CACHE PATH "Output directory for executables and DLL's.")

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
option( WITH_TESTS "Build tests" OFF )

add_subdirectory( "../../core" core )
add_subdirectory( "cpp" )
add_subdirectory( "csharp" )