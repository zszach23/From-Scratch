# From-Scratch
A collection of data structures, algorithms, and other things built from scratch.

## How to Run Test Suites

To run the various test suites, follow the steps below:

#### CMake
Ensure CMake is installed on your system

#### Run Test Suites
Run the following commands:

```
cd <Directory>  # <Directory> is the root of the (sub)project

mkdir build     # Make a directory called build

cd build        # Go into the build directory

cmake ..        # Run cmake

cmake --build . # Create build files for tests

ctest           # Run the test suites
```