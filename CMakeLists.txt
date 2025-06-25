cmake_minimum_required(VERSION 3.16)

project(hashtable LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hashtable linear_probing_test.cpp
    linear_probing.h linear_probing.cpp
    quadratic_probing.h quadratic_probing.cpp
    chained.h chained.cpp
    base_class.h
    quadratic_probing_test.cpp
    chained_test.cpp
    stess_test.cpp
)

include(GNUInstallDirs)
install(TARGETS hashtable
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
