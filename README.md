# Traverse
Traverse is a Minecraft proxy implementation in C++ with performance as a priority.

## Setting Up
Traverse requires you to have CMake installed. <br> <br>

1. Clone the repo
2. Retrieve dependencies with `git submodule update --init --recursive`
3. Build Poco: <br>
Create `cmake-build` folder in Poco <br>
`cd dependencies/Poco` <br>
`mkdir cmake-build` <br>
Build Poco <br>
`cd cmake-build` <br>
`cmake ..` <br>
`cmake --build . --config Release` <br>

## Building
In the root directory create a folder named `build` <br>
`mkdir build` <br>
Setup CMake inside of build <br>
`cmake ..` <br>
Build the project <br>
`cmake --build .`