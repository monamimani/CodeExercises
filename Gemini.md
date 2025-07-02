# Gemini Project Helper

This file provides context about the project to the Gemini AI assistant.

## Project Overview

This is a C++ project containing a collection of solutions to coding exercises from platforms like Codility and LeetCode, as well as implementations of common algorithms. The project is set up for learning, practice, and demonstration of problem-solving skills in C++.

## Tech Stack

-   **Language:** C++
-   **Build System:** CMake
-   **Package Manager:** vcpkg
-   **CI/CD:** GitHub Actions
-   **Code Quality:** Clang-Format, Clang-Tidy

## Project Structure

-   `CodeExercises/`: The main source directory containing all coding challenges.
    -   `Codility/`: Solutions for Codility problems, organized by lesson.
    -   `LeetCode/`: Solutions for LeetCode problems.
    -   `TheAlgorithms/`: Implementations of various algorithms from the open-source project "The Algorithms - C++" ([repository](https://github.com/TheAlgorithms/C-Plus-Plus), [website](https://thealgorithms.github.io/C-Plus-Plus/)). This section serves as a learning resource for a wide range of algorithms.
-   `CMakeLists.txt`: The root CMake build script.
-   `CMake/`: Directory for custom CMake modules and scripts.
-   `vcpkg.json`: Defines the C++ dependencies managed by vcpkg.
-   `.github/workflows/cicd.yml`: The Continuous Integration and Continuous Deployment pipeline configuration.
-   `.clang-format` / `.clang-tidy`: Configuration files for code formatting and static analysis.

## Build and Run

This project uses a CMake preset-based workflow. The build output will be located in a subdirectory under `_Out/build/`, corresponding to the preset name.

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

After building the project, you can run the tests by executing the test binary directly:

```sh
./_Out/build/Linux-Clang-Ninja-Debug/CodeExercises/CodeExercisesTests
```

## Coding Style

The project enforces a consistent code style using `.clang-format` and uses `.clang-tidy` for static analysis. Please ensure that any new code contributions are formatted according to these configurations.

## Comments policy
Only write high-value comments if at all. Avoid talking to the user through comments.
