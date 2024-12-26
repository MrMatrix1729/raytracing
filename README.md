# Raytracer

This is a WIP ray tracer built in C++ but planned to be ported to Rust as well

## Build

To build the project, make sure you have `cmake` installed. Then run

```bash
cmake -B build/Release -DCMAKE_BUILD_TYPE=Release
cmake --build build/Release --config Release
```

## Run
To generate a file run,
```bash
build/Release/rayTracing > images/image.ppm
```
The files will be stored as `ppm` files in `images/` folder. It can be viewed using any ppm viewer. Plan to use a more storage efficient file format later.

