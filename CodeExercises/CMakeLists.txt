include_guard()

get_filename_component(targetNameBase ${CMAKE_CURRENT_LIST_DIR} NAME)
set(targetName ${targetNameBase}Tests)


#add_subdirectory(TheAlgorithms)

add_executable(${targetName})

target_include_directories(${targetName}
  PUBLIC
      "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(${targetName}
  INTERFACE
  PUBLIC
  PRIVATE main.cpp
)

# target_compile_options(${targetName}
#   PRIVATE
# )

# #see https://github.com/google/googletest/issues/2157
target_link_libraries(${targetName}
  INTERFACE
  PUBLIC
  PRIVATE
  #TheAlgorithms
  #CodeExercises::FuzzTestSanitizers
  CodeExercises::Warnings
  GTest::gtest
  benchmark::benchmark
  fuzztest::init_fuzztest
  fuzztest::fuzztest
)

#gtest_discover_tests(${targetName})
