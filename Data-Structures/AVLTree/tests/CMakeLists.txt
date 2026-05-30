###############################################################################
# AVL Tree Tests: CMakeLists.txt
#
# CMake configuration for running unit tests for AVL Tree
###############################################################################

###############################################################################
# Add Executables: Test Suites follow the naming convention of testsuite_XX.cpp
###############################################################################

include(GoogleTest)

set(NUM_TEST_SUITES 6) # UPDATE WITH NUMBER OF TEST CASES

foreach(i RANGE 1 ${NUM_TEST_SUITES})
    if(i LESS 10)
        set(TEST_NAME "testsuite_0${i}")
    else()
        set(TEST_NAME "testsuite_${i}")
    endif()

    add_executable(${TEST_NAME} ${TEST_NAME}.cpp)
    target_link_libraries(${TEST_NAME} GTest::gtest_main)
    gtest_discover_tests(${TEST_NAME})
endforeach()