cmake_minimum_required(VERSION 3.22)
project(ascii_renderer)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(engine)
add_subdirectory(external/TermOx)

add_executable(
    ascii_renderer
    main.cpp
)

target_link_libraries(engine TermOx)

target_link_libraries(ascii_renderer
    TermOx
    engine
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
    engine
    gtest_main
)

add_executable(
    Ray_test
    tests/Ray_test.cpp
)
target_link_libraries(Ray_test
    engine
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(Vector3_test)
gtest_discover_tests(Ray_test)
