include( CSharpUtilities )

configure_file("${CMAKE_SOURCE_DIR}/csharp/Config/AssemblyInfo.cs.template" "${CMAKE_BINARY_DIR}/csharp/Config/${PROJECT_NAME}/AssemblyInfo.cs")

add_library(
    ${PROJECT_NAME}
    SHARED
    "${CMAKE_BINARY_DIR}/csharp/Config/${PROJECT_NAME}/AssemblyInfo.cs"
    Library.cs
)

set_target_properties(
    ${PROJECT_NAME} 
    PROPERTIES
    VS_DOTNET_REFERENCES "System;System.Core"
    VS_GLOBAL_ROOTNAMESPACE ${PROJECT_NAME}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${PROJECT_NAME}DLL
)

if ( PROJECT_IS_TOP_LEVEL AND WITH_TESTS )
    enable_testing()
    add_subdirectory( Tests )
endif()