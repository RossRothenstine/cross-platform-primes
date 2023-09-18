cmake_minimum_required( VERSION 3.22.1 )

project (
    "CrossPlatformPrimes"
    LANGUAGES
        CXX
    VERSION
        1.0.0
)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib 
    CACHE PATH "Output directory for static libraries.")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    CACHE PATH "Output directory for shared libraries.")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    CACHE PATH "Output directory for executables and DLL's.")

option( WITH_TESTS "Build tests" OFF )

# Add paths to modules
list( APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/" )

add_subdirectory( src )

if ( PROJECT_IS_TOP_LEVEL AND WITH_TESTS )
    enable_testing()
    add_subdirectory( test ) 
endif()