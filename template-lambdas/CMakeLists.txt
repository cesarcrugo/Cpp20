cmake_minimum_required(VERSION 3.22.1)
project (cpp20)
set (CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(cpp20 template-lambdas.cpp)
target_include_directories(cpp20 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cpp20)