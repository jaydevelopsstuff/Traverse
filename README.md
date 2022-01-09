# Traverse
Traverse is a Minecraft proxy implementation in C++ with performance as a priority.

## Importing
1. Clone the repo
2. Retrieve dependencies with `git submodule update --init --recursive`
3. Build Poco:
Create `cmake-build` folder in Poco
`cd dependencies/Poco`
`mkdir cmake-build`
`cd cmake-build`
Build Poco
`cmake ..` (In `cmake-build`)
`cmake --build . --config Release`