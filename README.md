# queue

A simple dynamic queue library in C.

## Build

The build system used is CMake >= 3.0.
There is different build type supported :

- `Debug` : for debug symbols
- `Coverage` : for test coverage
- `Profiling` : for lib profiling on a simple example
- `Release` : build with `-03` flag
- `Else` normal build

You can either build the library with cmake or cmake-gui.

## Usage

An example is given in the source. It will build with the project.
To use it you must set the `-lqueue` flag.