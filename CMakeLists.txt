cmake_minimum_required(VERSION 3.10.2)
project(Assignment3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-lgmpxx -lgmp")

# GMP library is no used. But this is how we can add GMP library.
find_library(GMP_LIBRARY gmp)
find_library(GMPXX_LIBRARY gmpxx)

add_executable(Assignment3 main.cpp QR_QNR_P.cpp QR_QNR_P.h P_ROOTS_Zp.cpp P_ROOTS_Zp.h MillerRobbin.cpp MillerRobbin.h)
target_link_libraries(Assignment3 "${GMP_LIBRARY}" "${GMPXX_LIBRARY}")
