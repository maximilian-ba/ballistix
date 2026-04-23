include(FetchContent)

# Download GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# GTest-Option to avoid conflicts with windows runtime
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# ---
# Test-Binary

add_executable(
    BallistixTests 
    InitializationTest.cpp
)

target_link_libraries(
    BallistixTests
    PRIVATE
    gtest_main
    Ballistix
)

include(GoogleTest)
gtest_discover_tests(BallistixTests)