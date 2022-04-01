## Building
```
cmake -S . -B build
cmake --build build
cd build && ./ascii_renderer
```

## Testing
```
cmake -S . -B build
cmake --build build
cd build && ctest --output-on-failure
```
