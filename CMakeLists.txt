cmake_minimum_required(VERSION 3.22)
project(ascii_renderer)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(includes/TermOx)

add_executable(
    ascii_renderer
    main.cpp
)

target_link_libraries(src TermOx)

target_link_libraries(ascii_renderer
    TermOx
    src
)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    Vector3_test
    tests/Vector3_test.cpp
)
target_link_libraries(Vector3_test
    src
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(Vector3_test)
