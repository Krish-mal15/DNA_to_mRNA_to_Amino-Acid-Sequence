cmake_minimum_required(VERSION 3.0.0)
project(Cpp_Testing VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Cpp_Testing main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
