cmake_minimum_required(VERSION 3.10)

project(modern_cc CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if (NOT MSVC)
  add_compile_options(-Wall -Wextra -pedantic)
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
    space
    sysinfo
    token
    unique
    vector
    weak
    )

find_package(Threads REQUIRED)

enable_testing()

foreach(program ${PROGRAMS})
  add_executable(${program} ${program}.cc)
  target_link_libraries(${program} Threads::Threads)
  add_test(NAME ${program} COMMAND ${program}
           WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endforeach(program)
