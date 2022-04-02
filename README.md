# Ray Marching on your Terminal

Learning Ray Marching and having fun

## Building
```
git clone git@github.com:timHau/Ascii-Renderer.git
cd Ascii-Renderer
git submodule update --init --recursive
cmake -S . -B build
cmake --build build
cd build && ./ascii_renderer
```
Currently only tested on MacOS, if you find a bug, please open an issue.

## Testing
```
cd build && ctest --output-on-failure
```
