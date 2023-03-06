set(tests
    cc_playground_test.cpp
)

foreach(test ${tests})
    string(REPLACE _test.cpp _test target ${test})
    add_executable(${target} ${test} factory.cpp main.cpp)
    add_test(${target} ${target})
    target_link_libraries(${target} PRIVATE GTest::gtest GTest::gtest_main SystemC::systemc cc_playground)
endforeach()
