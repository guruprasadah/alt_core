cmake_minimum_required (VERSION 3.13)

project ("alt_core")

add_library(alt_core STATIC)

add_executable(alt_core_test)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET alt_core PROPERTY CXX_STANDARD 23)
  set_property(TARGET alt_core_test PROPERTY CXX_STANDARD 23)
endif()

add_subdirectory ("src")
add_subdirectory("test")
