# Ray Marching on your Terminal

Learning Ray Marching and having fun

https://user-images.githubusercontent.com/12029285/161392081-70e1a312-dbde-4225-ae90-212635516fc4.mp4



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
