cmake_minimum_required(VERSION 3.4)
project(testpyncpp LANGUAGES CXX)

#find_package(PythonLibs REQUIRED)
find_package(pybind11 REQUIRED)  # or add_subdirectory(pybind11)


include_directories(${PYTHON_INCLUDE_DIRS})
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(testpyncpp testpyncpp.cpp)
target_link_libraries(testpyncpp PRIVATE ${PYTHON_LIBRARIES} pybind11::embed)
