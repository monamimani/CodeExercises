include_guard()

get_filename_component(targetName ${CMAKE_CURRENT_LIST_DIR} NAME)

add_library(CodeExercises_${targetName} INTERFACE)
add_library(CodeExercises::${targetName} ALIAS CodeExercises_${targetName})


target_include_directories(CodeExercises_${targetName}
INTERFACE
      "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(CodeExercises_${targetName}
  INTERFACE
    vector.cpp
)
