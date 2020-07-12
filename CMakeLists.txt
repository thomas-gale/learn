cmake_minimum_required(VERSION 3.17.2)
project(Learn
    VERSION 0.1.0
    DESCRIPTION "Learning reinforcement learning in C++"
    LANGUAGES CXX)

# Project wide C++ standard
set(CMAKE_CXX_STANDARD 17)

# Locate protocol buffer library (used for all DTO encoding) - https://github.com/protocolbuffers/protobuf
# (Built and located in /usr/lib/... during Docker environemnt setup)
include(FindProtobuf)
find_package(Protobuf REQUIRED)
message(STATUS "Using protobuf version: ${Protobuf_VERSION}")

# PyTorch (Facebook research's machine learning framework) - https://pytorch.org/
# (Docker devcontainer should have already installed and configured this)
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/libtorch")
find_package(Torch REQUIRED)
message(STATUS "Using torch version: ${Torch_VERSION}")

# Add other third parties
add_subdirectory(third_party)

# Recurse into src.
add_subdirectory(src)

# Recurse into tests.
add_subdirectory(test)
