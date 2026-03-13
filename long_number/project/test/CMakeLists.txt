add_executable(ttv_test tests.cpp)
include(GoogleTest)

target_link_libraries(ttv_test
    gtest_main
    ${LONG_NUMBER_LIB}
)

gtest_discover_tests(ttv_test)
