cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

# Enables the Standard module support. This needs to be done
# before selecting the languages.
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)

# Currently CMake requires extensions enabled when using import std.
# https://gitlab.kitware.com/cmake/cmake/-/issues/25916
# https://gitlab.kitware.com/cmake/cmake/-/issues/25539
set(CMAKE_CXX_EXTENSIONS ON)

include(CMakePrintHelpers)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
#set(VCPKG_INSTALLED_DIR ${CMAKE_BINARY_DIR}/../../vcpkg_installed)

if(NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 23)
  set(CMAKE_CXX_STANDARD_REQUIRED YES)
endif()

include(CheckCXXCompilerFlag)

include(CMake/PreventInSourceBuilds.cmake)
#include(CMake/ValidateVcpkgToolchain.cmake)
include(CMake/GetCPM.cmake)

project(CodeExercises
  VERSION 0.0.1
  DESCRIPTION ""
  HOMEPAGE_URL "https://github.com/monamimani/CodeExercises"
  LANGUAGES CXX C)

if (NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
  message(WARNING "CodeExercices only support Linux.")
  return()
endif()

if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  message(FATAL_ERROR, "Only Clang is supported. Current CMAKE_CXX_COMPILER_ID=${CMAKE_CXX_COMPILER_ID}")
endif()

include(CMakeProjectOptions.cmake)
option(FUZZTEST_FUZZING_MODE "Building the fuzztest in fuzzing mode." OFF)
set(FUZZTEST_COMPATIBILITY_MODE "" CACHE STRING "Compatibility mode. Available options: <empty>, libfuzzer")

CPMAddPackage(
  NAME fuzztest
  GITHUB_REPOSITORY google/fuzztest
  GIT_TAG "2025-02-14"
  OPTIONS
    "FUZZTEST_FUZZING_MODE ${FUZZTEST_FUZZING_MODE}"
    "FUZZTEST_COMPATIBILITY_MODE ${FUZZTEST_COMPATIBILITY_MODE}"
)
get_target_property(fuzztest_include_dirs fuzztest_fuzztest INTERFACE_INCLUDE_DIRECTORIES)
set_property(TARGET fuzztest_fuzztest APPEND PROPERTY INTERFACE_SYSTEM_INCLUDE_DIRECTORIES ${fuzztest_include_dirs})

# add_library(CodeExercises_FuzzTestSanitizers INTERFACE)
# add_library(CodeExercises::FuzzTestSanitizers ALIAS CodeExercises_FuzzTestSanitizers)
# target_compile_options(CodeExercises_FuzzTestSanitizers
#   INTERFACE
#     -fsanitize=address
#     -fsanitize-coverage=inline-8bit-counters
#     -fsanitize-coverage=trace-cmp
#     -DFUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION
#     -DADDRESS_SANITIZER
#     -UNDEBUG
# )
# target_link_options(CodeExercises_FuzzTestSanitizers INTERFACE "-fsanitize=address")

# target_link_libraries(fuzztest_init_fuzztest
#   PRIVATE
#   CodeExercises::FuzzTestSanitizers
# )

# target_link_libraries(fuzztest_fuzztest
#   INTERFACE
#   CodeExercises::FuzzTestSanitizers
# )

CPMAddPackage(
  NAME benchmark
  GITHUB_REPOSITORY google/benchmark
  GIT_TAG "v1.9.2"
  OPTIONS
    "BENCHMARK_ENABLE_TESTING Off"
    "BENCHMARK_USE_LIBCXX ON"
)


set(CLANG_WARNINGS
-Wall
-Wextra # reasonable and standard
-Wshadow # warn the user if a variable declaration shadows one from a parent context
-Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor. This helps
# catch hard to track down memory errors
-Wold-style-cast # warn for c-style casts
-Wcast-align # warn for potential performance problem casts
-Wunused # warn on anything being unused
-Woverloaded-virtual # warn if you overload (not override) a virtual function
-Wpedantic # warn if non-standard C++ is used
-Wconversion # warn on type conversions that may lose data
-Wsign-conversion # warn on sign conversions
-Wnull-dereference # warn if a null dereference is detected
-Wdouble-promotion # warn if float is implicit promoted to double
-Wformat=2 # warn on security issues around functions that format output (ie printf)
-Wimplicit-fallthrough # warn on statements that fallthrough without an explicit annotation
)
set(PROJECT_WARNINGS_CXX ${CLANG_WARNINGS})
add_library(CodeExercises_warnings INTERFACE)
add_library(CodeExercises::Warnings ALIAS CodeExercises_warnings)
target_compile_options(CodeExercises_warnings INTERFACE $<$<COMPILE_LANGUAGE:CXX>:${PROJECT_WARNINGS_CXX}>)

include(CMake/FuzzTestFlagSetup.cmake)
fuzztest_setup_fuzzing_flags()

if(fuzztest_ADDED)
  enable_testing()
endif()

add_subdirectory(CodeExercises)

execute_process(
  COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_SOURCE_DIR}/compile_commands.json
)
