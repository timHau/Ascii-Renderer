# Ray Marching on your Terminal

Learning Ray Marching and having fun

## Dependencies
Place [TermOx](https://github.com/a-n-t-h-o-n-y/TermOx) inside `/external` 

## Building
```
cmake -S . -B build
cmake --build build
cd build && ./ascii_renderer
```
Currently only tested on MacOS, if you find a bug, please open an issue.

## Testing
```
cmake -S . -B build
cmake --build build
cd build && ctest --output-on-failure
```
