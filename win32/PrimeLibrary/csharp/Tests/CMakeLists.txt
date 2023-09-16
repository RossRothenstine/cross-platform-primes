
include( CSharpUtilities )

add_executable(
    ${PROJECT_NAME}Tests

    TestSuite.cs
    LibraryTest.cs
)

set_target_properties(
    ${PROJECT_NAME}Tests
    PROPERTIES
    VS_GLOBAL_ROOTNAMESPACE ${PROJECT_NAME}
    VS_DOTNET_REFERENCES "System;System.Runtime"
    VS_PACKAGE_REFERENCES "NUnit_3.13.3;NUnitLite_3.13.3"
)

target_link_libraries(
    ${PROJECT_NAME}Tests
    PUBLIC
    ${PROJECT_NAME}
)