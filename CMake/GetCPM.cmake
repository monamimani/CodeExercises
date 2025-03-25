
set(CPM_DOWNLOAD_VERSION 0.40.8)
set(CPM_HASH_SUM "78ba32abdf798bc616bab7c73aac32a17bbd7b06ad9e26a6add69de8f3ae4791")

set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/CMake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

set(CPM_SOURCE_CACHE ${CMAKE_BINARY_DIR}/../../cpm_sources)

# Expand relative path. This is important if the provided path contains a tilde (~)
get_filename_component(CPM_DOWNLOAD_LOCATION ${CPM_DOWNLOAD_LOCATION} ABSOLUTE)

# https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/CPM.cmake
file(DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
  ${CPM_DOWNLOAD_LOCATION} EXPECTED_HASH SHA256=${CPM_HASH_SUM}
)

include(${CPM_DOWNLOAD_LOCATION})

set(CPM_USE_LOCAL_PACKAGES TRUE)
set(CPM_USE_NAMED_CACHE_DIRECTORIES TRUE)
