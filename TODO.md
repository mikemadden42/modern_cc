# TODO

Findings from a project review (2026-11-02). Everything compiles cleanly with
`-Wall -Wextra -pedantic`; the real problems are in build and CI.

## Priority

1. Fix the CI test step (see Build & CI).
2. Use `generator` instead of `std::rand` in `lambda0.cc`.
3. Switch smart-pointer samples to `make_shared` / `make_unique`; update README to C++17.
4. Clean up CMake and drop the Makefile (done).

## Build & CI

- [x] **CI test step is broken or does nothing.** `.github/workflows/cmake.yml`
      runs `ctest`, but `CMakeLists.txt` has no `enable_testing()` / `add_test()`.
      With CMake 4.4.5, `ctest` printed "No test configuration file found!" and
      exited 1. Add tests or remove the step:
      ```cmake
      enable_testing()
      foreach(program ${PROGRAMS})
        add_test(NAME ${program} COMMAND ${program} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
      endforeach()
      ```
- [x] **CMake:** `${CORELIBS}` is never defined; remove it and use
      `Threads::Threads` instead of `${CMAKE_THREAD_LIBS_INIT}`.
- [x] **CMake:** `set(CMAKE_CXX_FLAGS ...)` overwrites flags the user passes in;
      use `add_compile_options(-Wall -Wextra -pedantic)`.
- [x] **CMake:** add `set(CMAKE_CXX_STANDARD_REQUIRED ON)` and
      `set(CMAKE_CXX_EXTENSIONS OFF)`.
- [x] **Makefile:** `space` is missing from `PROGRAMS`, so only 17 of 18 programs build.
- [x] **Makefile:** use `CXX` / `CXXFLAGS` instead of `CC` / `CFLAGS`.
- [x] **Makefile:** `clean` should use `rm -f` and be marked `.PHONY`.
- [x] **Makefile / .gitignore:** in-source binaries aren't ignored, so `make`
      leaves the working tree dirty.
- [x] **CI:** update `actions/checkout@v3` to v4 or later.
- [ ] **CI:** add an OS matrix (ubuntu, macos, windows) so the `MSVC` branch is tested.

## Bugs

- [x] **`lambda0.cc`:** lines 45 and 55 still use `std::rand`, which isn't
      seeded and gives the same sequence on every run (`<cstdlib>` isn't
      included either). Pass `generator` instead. `<cmath>` is unused.
- [x] **`read.cc`:** opens `"read.cc"` by a relative path; run from `build/` it
      prints nothing and exits 0. Print an error and return non-zero when the
      file isn't found, or take the path as an argument. The `infile.close()`
      call is unnecessary.

## Accuracy & modern C++ style

- [x] **README** says "Sample C++11 programs", but the build uses C++17
      (`space.cc` needs `std::filesystem`).
- [x] Use `std::make_shared` / `std::make_unique` instead of raw `new` in
      `shared.cc`, `unique.cc`, `weak.cc` and `smrtptrs.cc`.
- [x] **`smrtptrs.cc`:** comment says "three kinds of smart pointers" but only
      two are shown. Add `weak_ptr` or fix the comment.
- [ ] Add missing `<string>` include in `token.cc` (`smrtptrs.cc` done).
- [ ] Qualify ADL-reliant calls: `getline` in `read.cc` and `token.cc`, `copy`
      in `token.cc`.
- [ ] **`lambda1.cc`:** `size_t count3` but `int count13`; make them consistent.
- [ ] **`rvref.cc`:** drop `using namespace std;`.
- [ ] **`atomic.cc`:** rename the free function `thread`; it's confusing next to `std::thread`.
- [ ] **`vector.cc`:** loops could use `const auto&`.
- [ ] **`sysinfo.cc`:** `hardware_concurrency()` may return 0; add a comment or check.

## Repo hygiene

- [ ] Commit `.clang-format` and `.clang-tidy` so contributors and CI apply the same rules.
- [ ] Trim the generic `.gitignore` template (Fortran, `.lai`, etc.).
