include_guard()

if(NOT DEFINED PROJECT_NAME)
  message(FATAL_ERROR "${CMAKE_CURRENT_LIST_FILE} need to be included inside a project")
endif()


include(CMake/StandardProjectSettings.cmake)
# include(CMake/Sanitizers.cmake)
# include(CMake/Fuzzer.cmake)

# macro(CODEeXERCISES_declare_options)
#   # Cmake options that are likely to be different for each projects.
#   # Common options that are unlikely to be changed are defined in CMake/StandardProjectSettings.cmake.
#   if(PROJECT_IS_TOP_LEVEL)
#     option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

#     option(PersonalWorks_BASIC_BUILD_MODE "Disable most of the nice to have build features." OFF)

#     cmake_dependent_option(PersonalWorks_ENABLE_CLANG_TIDY "Enable clang-tidy" ON "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)
#     cmake_dependent_option(PersonalWorks_ENABLE_CPPCHECK "Enable cpp-check analysis" OFF "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)

#     cmake_dependent_option(PersonalWorks_ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" ${SUPPORTS_ASAN} "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)
#     cmake_dependent_option(PersonalWorks_ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" ${SUPPORTS_UBSAN} "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)
#     cmake_dependent_option(PersonalWorks_ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)
#     cmake_dependent_option(PersonalWorks_ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)
#     cmake_dependent_option(PersonalWorks_ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)

#     cmake_dependent_option(PersonalWorks_ENABLE_IPO "Enable IPO/LTO" ON "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)
#     cmake_dependent_option(PersonalWorks_ENABLE_CACHE "Enable ccache" OFF "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)
#     cmake_dependent_option(PersonalWorks_ENABLE_UNITY_BUILD "Enable unity builds" OFF "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)
#     cmake_dependent_option(PersonalWorks_ENABLE_COVERAGE "Enable coverage reporting" OFF "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)
#     cmake_dependent_option(PersonalWorks_ENABLE_DOXYGEN "Enable Doxygen generation" OFF "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)

#     cmake_dependent_option(PersonalWorks_ENABLE_TARGET_CODE_HARDENING "Enable interface target code hardening" ON "NOT PersonalWorks_BASIC_BUILD_MODE" OFF)
#     cmake_dependent_option(PersonalWorks_ENABLE_GLOBAL_CODE_HARDENING "Enable global code hardening" ON "PersonalWorks_ENABLE_TARGET_CODE_HARDENING" OFF)
#   endif()

#   if(PersonalWorks_BASIC_BUILD_MODE)
#     message(AUTHOR_WARNING "Basic build mode enabled. All fancy build feature like checks, IPO/LTO are disabled.")
#   endif()

#   if(PersonalWorks_ENABLE_GLOBAL_CODE_HARDENING OR PersonalWorks_ENABLE_TARGET_CODE_HARDENING)
#     if(NOT SUPPORTS_UBSAN
#       OR PersonalWorks_ENABLE_SANITIZER_UNDEFINED
#       OR PersonalWorks_ENABLE_SANITIZER_ADDRESS
#       OR PersonalWorks_ENABLE_SANITIZER_THREAD
#       OR PersonalWorks_ENABLE_SANITIZER_LEAK)
#       set(ENABLE_UBSAN_MIN_RUNTIME FALSE)
#     else()
#       set(ENABLE_UBSAN_MIN_RUNTIME TRUE)
#     endif()

#     include(CMake/CodeHardening.cmake)
#     configure_code_hardening(${ENABLE_UBSAN_MIN_RUNTIME})
#   endif()

#   check_libfuzzer_support(LIBFUZZER_SUPPORTED)

#   if(LIBFUZZER_SUPPORTED AND(PersonalWorks_ENABLE_SANITIZER_ADDRESS OR PersonalWorks_ENABLE_SANITIZER_THREAD OR PersonalWorks_ENABLE_SANITIZER_UNDEFINED))
#     set(DEFAULT_FUZZER ON)
#   else()
#     set(DEFAULT_FUZZER OFF)
#   endif()

#   option(PersonalWorks_BUILD_TESTS "Builds the tests" ON)
#   option(PersonalWorks_BUILD_BENCHMARKS "Builds the benchmarks" ON)
#   option(PersonalWorks_BUILD_FUZZ_TESTS "Enable fuzz testing executable" ${DEFAULT_FUZZER})
# endmacro()

# macro(PersonalWorks_global_options)
#   if(PersonalWorks_ENABLE_IPO)
#     include(CMake/InterproceduralOptimization.cmake)
#   endif()

#   if(PersonalWorks_ENABLE_GLOBAL_CODE_HARDENING)
#     add_global_code_hardening()
#   endif()

#   if(PersonalWorks_ENABLE_CACHE)
#     include(CMake/Cache.cmake)
#   endif()

#   if(PersonalWorks_ENABLE_DOXYGEN)
#     include(CMake/Doxygen.cmake)
#     PersonalWorks_enable_doxygen("")
#   endif()

# endmacro()

# macro(PersonalWorks_target_options)
#   add_library(PersonalWorks_warnings INTERFACE)
#   add_library(PersonalWorks::PersonalWorks_warnings ALIAS PersonalWorks_warnings)

#   add_library(PersonalWorks_options INTERFACE)
#   add_library(PersonalWorks::PersonalWorks_options ALIAS PersonalWorks_options)

#   add_library(PersonalWorks_sanitizers INTERFACE)
#   add_library(PersonalWorks::PersonalWorks_sanitizers ALIAS PersonalWorks_sanitizers)

#   include(CMake/CompilerWarnings.cmake)
#   add_target_interface_warnings(PersonalWorks_warnings OFF)

#   target_compile_features(PersonalWorks_options INTERFACE cxx_std_${CMAKE_CXX_STANDARD})
#   set_target_properties(PersonalWorks_options PROPERTIES UNITY_BUILD ${PersonalWorks_ENABLE_UNITY_BUILD})

#   add_target_interface_sanitizers(
#     PersonalWorks_sanitizers
#     ${PersonalWorks_ENABLE_SANITIZER_ADDRESS}
#     ${PersonalWorks_ENABLE_SANITIZER_LEAK}
#     ${PersonalWorks_ENABLE_SANITIZER_UNDEFINED}
#     ${PersonalWorks_ENABLE_SANITIZER_THREAD}
#     ${PersonalWorks_ENABLE_SANITIZER_MEMORY}
#   )

#   include(CMake/StaticAnalyzers.cmake)

#   if(PersonalWorks_ENABLE_CPPCHECK)
#     PersonalWorks_enable_cppcheck(OFF, "")
#   endif()

#   if(PersonalWorks_ENABLE_CLANG_TIDY)
#     PersonalWorks_enable_clang_tidy(OFF)
#   endif()

#   if(PersonalWorks_ENABLE_TARGET_CODE_HARDENING)
#     add_target_interface_code_hardening(PersonalWorks_options)
#   endif()
# endmacro()
