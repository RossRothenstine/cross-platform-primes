file( GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES true *.h *.cpp )
file( GLOB_RECURSE SOURCES LIST_DIRECTORIES true ../src/*.h ../src/*.cpp )

include( FindGoogleTest )
include( GoogleTest )

enable_testing()

add_executable( ${PROJECT_NAME}-test ${SOURCES} ${TEST_SOURCES} )
target_include_directories( ${PROJECT_NAME}-test PRIVATE ${PROJECT_SOURCE_DIR}/src )
target_link_libraries( ${PROJECT_NAME}-test gtest_main )

gtest_discover_tests( ${PROJECT_NAME}-test )