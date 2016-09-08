cmake_minimum_required(VERSION 2.8)

project(modern_cc CXX)

add_definitions(-Wall -O2 -std=c++14 -march=native)

set(PROGRAMS
    atomic
    auto
    for
    hello
    lambda0
    lambda1
    null
    read
    rvref
    shared
    size
    smrtptrs
    sysinfo
    token
    unique
    vector
    weak
    )

find_package(Threads REQUIRED)

foreach(program ${PROGRAMS})
  add_executable(${program} ${program}.cc)
  target_link_libraries(${program} ${CORELIBS} ${CMAKE_THREAD_LIBS_INIT})
endforeach(program)
