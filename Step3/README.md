# Step 3

The goal of this exercise is to highlight the use of `INTERFACE`, making a *modern* CMake project. Recall from Step 2 that `INTERFACE` means that the object will be propagated to targets that depends on it. 

## Variable Access

In CMake, to access the value of a variable, you must wrap its name in `"${}"`. Without `"${}"`, CMake just treats it as a literal string. 

Then, the impact of `"` is that it will prevent the string from being splitted by special character, like space. For example, if `x` is the path specified as `/Learn CMake/Step1`. Then, without `"`, `x` will be treated as two independent strings: `/Learn` and `CMake/Step1`. With `"`, the string will still be `/Learn CMake/Step1`. 

## Use Case of `INTERFACE` 1

In the top level `CMakeLists.txt`, i.e., in `/Step2/CMakeLists.txt`, we explicitly specify the executables to include the `MathFunctions` directory: 

```cmake
target_include_directories(Tutorial PUBLIC "${PROJECT_SOURCE_DIR}/MathFunctions")
```

When the project expands, manually including all the directories that we use will be very tedious and vulnerable to bug. 

To address this issue, we can utilize the `INTERFACE` scope. In the `CMakeLists.txt` specified at the `MathFunctions` library, we specify that for all that depends on `MathFunctions` (definition of `INTERFACE`), it will include the current source directory. 

```cmake
target_include_directories(MathFunctions INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
```

With this, we no longer need to explicitly include directories for `Tutorial`. 

## Use Case of `INTERFACE` 2

Other use case of `INTERFACE` is that instead of specifying the C++ standard globally like this (in the top level `CMakeLists.txt`):

```cmake
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

We can make it into an `INTERFACE`: 

```cmake
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)
```

By this, we are more target-specific, i.e, only apply features to the targets that we need them. For example:

```cmake
target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)
```

Here, we explicitly state the dependency of `SqrtLibrary` to `tutorial_compiler_flags`, i.e., `cxx_std_11`. 

However, this maybe too overkill for tiny projects; just use the global one for tiny projects. 

## Good to Highlight 1

When using interface, recall that the items you specified do not used by the target. For example, in Use Case 1, `MathFunctions` does not include the directory for itself, it's just propagate the "include" property to all that depends on it. 

## Good to Highlight 2

When we have:
```cmake
target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)
target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
```
This means that `tutorial_compiler_flags` is used by `SqrtLibrary` and propagated to all that depends on `SqrtLibrary`, because we use `PUBLIC`. So, here `MathFunctions` also use `tutorial_compiler_flags`. 

**Takeaways**: Specifying `PUBLIC`, `INTERFACE`, and `PRIVATE` impact **all things that depend on it** and the **internal usage**. 