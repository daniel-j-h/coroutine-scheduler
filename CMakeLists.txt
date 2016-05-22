cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(coroutine-scheduler VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.59 REQUIRED coroutine thread system context)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

add_executable(main main.cc)
target_link_libraries(main ${Boost_COROUTINE_LIBRARY} ${Boost_CONTEXT_LIBRARY} ${Boost_SYSTEM_LIBRARY})
