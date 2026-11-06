cmake_minimum_required(VERSION 3.25)
project(tutorial1 VERSION 0.1.0 LANGUAGES CXX)

# library configs
add_library(temperature src/temperature.cpp)
target_include_directories(temperature PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(temperature PUBLIC cxx_std_20)
target_compile_options(temperature PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->)

# executable configs
add_executable(repo1_app app/main.cpp)
target_link_libraries(repo1_app PRIVATE temperature)
target_compile_options(repo1_app PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->)

option(BUILD_TESTING "Build the unit tests" OFF)
include(CTest)  # adds BUILD_TESTING (ON by default) and enable_testing()
if(BUILD_TESTING)
  find_package(GTest REQUIRED)  # provided by Conan's CMakeDeps
  add_executable(repo1_tests tests/temperature_test.cpp)
  target_link_libraries(repo1_tests PRIVATE temperature GTest::gtest_main)
  include(GoogleTest)
  gtest_discover_tests(repo1_tests)
endif()

install(TARGETS repo1_app RUNTIME DESTINATION bin)