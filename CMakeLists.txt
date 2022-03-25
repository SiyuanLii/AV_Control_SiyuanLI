cmake_minimum_required(VERSION 3.8)
project(nmp)

find_package(GTest REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(SRC_LIST main.cpp)
add_executable(nmp ${SRC_LIST})

target_link_libraries(nmp
    ${GTEST_LIBRARIES}
    pthread)