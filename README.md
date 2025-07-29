# CodeExercises

This repository is a personal collection of C++ solutions for coding exercises. It also includes implementations of common algorithms and data structures for learning and practice purposes.

## Project Structure

The project is organized as follows:

-   `CodeExercises/`: The main source directory containing all coding challenges.
    -   `Codility/`: Solutions for Codility problems.
    -   `LeetCode/`: Solutions for LeetCode problems.
    -   `TheAlgorithms/`: Implementations of various algorithms from the open-source project "The Algorithms - C++" ([repository](https://github.com/TheAlgorithms/C-Plus-Plus), [website](https://thealgorithms.github.io/C-Plus-Plus/)). This section serves as a learning resource for a wide range of algorithms.

## Build and Run

This project uses a CMake preset-based workflow.

### Debug Build

1.  **Configure the project:**
    ```sh
    cmake --preset=Linux-Clang-Ninja-Debug
    ```
2.  **Build the project:**
    ```sh
    cmake --build --preset=Linux-Clang-Ninja-Debug
    ```
    *Executables will be in `_Out/build/Linux-Clang-Ninja-Debug`.*

### Release Build

1.  **Configure the project:**
    ```sh
    cmake --preset=Linux-Clang-Ninja-ReleaseWithDebugInfo
    ```
2.  **Build the project:**
    ```sh
    cmake --build --preset=Linux-Clang-Ninja-ReleaseWithDebugInfo
    ```
    *Executables will be in `_Out/build/Linux-Clang-Ninja-ReleaseWithDebugInfo`.*

### Run Tests

After building the project, you can run the tests by executing the test binary directly, `CodeExercisesTests`
