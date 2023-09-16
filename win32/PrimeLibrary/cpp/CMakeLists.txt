# Some people seem divided on whether to use GLOB or explicit file lists.
# GLOB was decided on for ease of extensibility, but we can discuss this.
file( GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp )

add_library( 
    ${PROJECT_NAME}DLL
    SHARED 
    ${SOURCES} 
)

target_link_libraries(
    ${PROJECT_NAME}DLL
    CrossPlatformPrimes
)

target_include_directories( 
    ${PROJECT_NAME}DLL 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)