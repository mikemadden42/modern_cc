cmake_minimum_required(VERSION 2.8)

project(modern_cc CXX)

add_definitions(-Wall -O2 -std=c++11 -march=native)

set(PROGRAMS
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

foreach(program ${PROGRAMS})
  add_executable(${program} ${program}.cc)
  target_link_libraries(${program} ${CORELIBS})
endforeach(program)
