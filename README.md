# UAVCalc C++ Library

A calculation library for Unmanned Aerial Vehicle (UAV) performance calculation and analysis tools.

## Usage

### Building and Installing

```bash
# Create a build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build the library
make

# Install the library (may require sudo)
make install
```

### Linking with Your Project

In your project's CMakeLists.txt:

```cmake
find_package(uavcalc REQUIRED)
target_link_libraries(your_target uavcalc::uavcalc)
```

### Including in Your Code

```cpp
#include <uavcalc/aerodynamics.h>

// Use the library functionality
// ...
```

### Running Tests

```bash
# Build and run tests
make test
```

### Uninstalling

```bash
# From the build directory
make uninstall
```

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
