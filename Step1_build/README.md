# How to Build and Run?

## Background

A recommended way to use CMake is to use **out-of-source build**. In-of-source build combines the source and binary directories together, while out-of-source build separates the source and binary directories. We will discuss the steps on how to use out-of-source build here. 

**Note**: Source directory refers to the human-readable, uncompiled code, whereas binary directory contains the compiled machine code of the code. 

## Setup
To perform out-of-source build, do this following steps:

### 1. Make a build directory:
```bash
    mkdir Step1_build 
    cd Step1_build
```

### 2. Run CMake:
```bash
    cmake ../Step1
```
**Note**: The aim of this step is to configure the project. On the back, what happens is that CMake will generate build system files based on `CMakeLists.txt`. These files will tell the build tool how to compile and link your code. 

### 3. Build the project:
```bash
    cmake --build .
```
**Note**: The build files that are created in Step 2 will now be used to compile the codes. 


## Tips

Only rerun `cmake ../Step1` when you modify `CMakeLists.txt`. In other words, only rerun Step 2 when the change you've impacted how the project is configured. 

Otherwise, if you only modify the source code, you just need to rerun `cmake --build .`