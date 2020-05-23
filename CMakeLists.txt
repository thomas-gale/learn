cmake_minimum_required(VERSION 3.17.2)
project(Learn
    VERSION 0.1.0
    DESCRIPTION "Learning reinforcement learning in C++"
    LANGUAGES CXX)

# Project wide C++ standard
set(CMAKE_CXX_STANDARD 17)

# PyTorch (Facebook research's machine learning framework) - https://pytorch.org/
# (Docker devcontainer should have already installed and configured this)
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/libtorch")
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# Add other third parties
add_subdirectory(third_party)

# Recurse into src.
add_subdirectory(src/hello)

# Recurse into tests.
add_subdirectory(test)
