# CrystalUI
Simple XML-based OpenGL UI system

## Usage
By far the easiest way to use CrystalUI within your project is to add a git submodule and then 
include it as a subdirectory in CMake:

```cmake
add_subdirectory(lib/CrystalUI)
target_include_directories(yourproject PRIVATE ... lib/CrystalUI/src)
target_link_libraries(yourproject ... CrystalUI)
```

## Examples
To use 