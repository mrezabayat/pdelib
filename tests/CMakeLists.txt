file(GLOB TESTS_CPP *.cpp)

message(STATUS "Configuring tests")
foreach(testSrcFile ${TESTS_CPP})
    # cut off .cpp
    get_filename_component(testName ${testSrcFile} NAME)
    string(REPLACE ".cpp" "" testName ${testName})

    # show information
    message(STATUS "    ${testName}")

    # add executable
    add_executable(${testName} ${testSrcFile})

    # link library
    target_link_libraries(${testName} PUBLIC ${pdelib_libraries})
endforeach(testSrcFile ${TESTS_CPP})
