include_guard()

get_filename_component(targetName ${CMAKE_CURRENT_LIST_DIR} NAME)

add_library(${targetName} INTERFACE)

target_include_directories(${targetName}
INTERFACE
      "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(${targetName}
  INTERFACE
  PUBLIC
  PRIVATE
    dynamic_programming/0_1_knapsack.cpp
)

# target_compile_options(${targetName}
#   PRIVATE
# )


