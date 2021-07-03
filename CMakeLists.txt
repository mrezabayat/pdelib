cmake_minimum_required(VERSION 3.0.0)
project(pdelib VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#Show info
message(STATUS "pdelib install directory: ${CMAKE_INSTALL_PREFIX}")

#Options and flags
option(COMPILE_TESTS "Compile pdelib Tests" ON)

#Set library
set(pdelib_libraries CACHE INTERNAL "pdelib_libraries")

#Set include directories
message(STATUS "Configuring pdelib modules")
set(PDELIB_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(PDELIB_LIBS_INSTALL ${CMAKE_INSTALL_PREFIX}/lib)
set(PDELIB_INCLUDE_INSTALL ${CMAKE_INSTALL_PREFIX}/include)
file(GLOB pdelib_inc_dirs ${PDELIB_SRC_DIR}/*)
include_directories(${pdelib_inc_dirs})

#Add subdirectory
add_subdirectory(${PDELIB_SRC_DIR}/geometry)

#Tests
if(COMPILE_TESTS)
  set(TESTS_INSTALL_DIR ${CMAKE_CURRENT_LIST_DIR}/bin/)
  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tests)
endif()
