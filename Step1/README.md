# Step 1

## `add_executable()`

The signature of `add_executable()` is
```cmake
add_executable(<name> <options>... <sources>...)
```
`<options>...` and `<sources>...` are optional, but usually `<sources>...` are typically required. It is quite intuitive because most of the time you need to specify the list of sources to compile into the executable. The executable name will be the one that you state in `<name>`. 

There are many common `<options>...`  that you can use. Here are a list of them with some brief description on what each does:
1. `WIN32`: Creates a Windows GUI application instead of a console application
2. `MACOSX_BUNDLE`: Creates a macOS bundle
3. `EXCLUDE_FROM_ALL`: Prevents the target from being built by default
4. `IMPORTED`: Declares an external pre-built executable
5. `GLOBAL`: Makes the target visible to the parent scope when using functions

## `set()`

In CMake, you cannot directly assign values to variable using `=`, you need to use the set function. A complete documentation can be found [here](https://cmake.org/cmake/help/latest/command/set.html). 

In brief, the signature of `set()` is:
```cmake
set(<variable> <value>)
```

## `target_include_directories()`

The signature of `target_include_directories()` is
```cmake
target_include_directories(<target> [SYSTEM] [AFTER|BEFORE] <scope> <paths>... [<scope> <paths>...]...)
```

**Note**: 
1. `[x]` means that `x` is optional
2. `x...` means that we can insert in many values to specify `x`

A more detailed description for this function can be found [here](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories). 

This command basically tells CMake to add the specified `<paths>` to the list of directories the compiler should search when compiling `<target>`. You may specify `#include` directives in the code, but if you do not specify the paths in which the compiler should look for when compiling the code with `target_include_directories`, you will get an error because the program cannot find the header it is looking for. 

## Final Notes

You can find a more complete tutorials for this section [here](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html). 