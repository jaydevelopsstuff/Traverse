cmake_minimum_required(VERSION 3.5)

project(Traverse VERSION 1.0.0 DESCRIPTION "A Minecraft Proxy written in C++ with performance as a priority.")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_EXTENSIONS 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17") # This fixes my clangd lmao idk why

set(PocoFoundation_DIR ./dependencies/Poco/cmake-build/Poco)
find_package(PocoFoundation REQUIRED)
set(PocoNet_DIR ./dependencies/Poco/cmake-build/Poco)
find_package(PocoNet REQUIRED)
set(PocoJSON_DIR ./dependencies/Poco/cmake-build/Poco)
find_package(PocoJSON REQUIRED)

file(GLOB_RECURSE source ./src/*.cpp)
file(GLOB_RECURSE source_headers ./src/*.h)
add_executable(${PROJECT_NAME} ${source} ${source_headers})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./run)

target_link_libraries(${PROJECT_NAME} PRIVATE Poco::Foundation)
target_link_libraries(${PROJECT_NAME} PRIVATE Poco::Net)
target_link_libraries(${PROJECT_NAME} PRIVATE Poco::JSON)