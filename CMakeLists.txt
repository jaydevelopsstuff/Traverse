cmake_minimum_required(VERSION 3.5)

project(Traverse VERSION 1.0.0 DESCRIPTION "A Minecraft Proxy written in C++ with performance as a priority.")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_EXTENSIONS 17)

set(PocoFoundation_DIR ./dependencies/Poco/cmake-build/Poco)
find_package(PocoFoundation REQUIRED)

file(GLOB_RECURSE source ./src/*)
add_executable(${PROJECT_NAME} ${source})

set_property(TARGET ${PROJECT_NAME} PROPERTY LINKER_LANGUAGE CXX)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_link_libraries(${PROJECT_NAME} PRIVATE Poco::Foundation)