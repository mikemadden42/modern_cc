cmake_minimum_required(VERSION 3.10)

project(modern_cc CXX)

set (CMAKE_CXX_STANDARD 14)
if (NOT MSVC)
  set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
endif()

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
