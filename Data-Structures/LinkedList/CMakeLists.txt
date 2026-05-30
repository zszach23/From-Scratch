###############################################################################
# LinkedList: CMakeLists.txt
#
# CMake configuration for running unit tests for LinkedList
###############################################################################

cmake_minimum_required(VERSION 3.14)
project(LinkedList)

set(CMAKE_CXX_STANDARD 17)

###############################################################################
# Add GoogleTest
###############################################################################

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

###############################################################################
# Include Source Code and Test Directories
###############################################################################

include_directories(src)

enable_testing()
add_subdirectory(tests)