cmake_minimum_required(VERSION 3.0.0)
project(mspeed VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()


set(FLAGS_COMP "-std=c99 --pedantic-errors -Wall -Werror")
set(FLAGS_DBUG "-g")
set(FLAGS_RELEASE "${FLAGS_COMP} -DNDEBUG")

set(CMAKE_C_FLAGS ${FLAGS_RELEASE})

add_executable(mspeed main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
