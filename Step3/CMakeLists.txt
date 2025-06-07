cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

# TODO 4: Replace the following code by:
# * Creating an interface library called tutorial_compiler_flags
#   Hint: use add_library() with the INTERFACE signature
add_library(tutorial_compiler_flags INTERFACE)
# * Add compiler feature cxx_std_11 to tutorial_compiler_flags
#   Hint: Use target_compile_features()
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# TODO 2: Remove EXTRA_INCLUDES list

# add the MathFunctions library
add_subdirectory(MathFunctions)
# list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")

# add the executable
add_executable(Tutorial tutorial.cxx)

# TODO 5: Link Tutorial to tutorial_compiler_flags
target_link_libraries(Tutorial PUBLIC tutorial_compiler_flags)
target_link_libraries(Tutorial PUBLIC MathFunctions)

# TODO 3: Remove use of EXTRA_INCLUDES

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
