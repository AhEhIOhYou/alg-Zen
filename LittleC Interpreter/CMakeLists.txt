project(interp_prj)

include_directories("i")
file(GLOB SOURCES "*.cpp", "*.h")
add_executable(test ${SOURCES})
