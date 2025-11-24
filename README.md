cmake_minimum_required(VERSION 3.14)
project(Lab5_2_void)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Додаємо папку з кодом програми
add_library(arctan_lib src/functions.cpp)  # якщо ти розділиш код у functions.cpp / .h
# Якщо весь код в main.cpp, можна зробити інший підхід

add_executable(main_exec src/main.cpp)
target_link_libraries(main_exec PRIVATE arctan_lib)

# --- GoogleTest ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests tests/test_functions.cpp)
target_link_libraries(tests PRIVATE arctan_lib gtest_main)

# Для автоматичного відкриття тестів CTest
include(GoogleTest)
gtest_discover_tests(tests)

