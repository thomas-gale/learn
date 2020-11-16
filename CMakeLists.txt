cmake_minimum_required(VERSION 3.17.2)
project(Learn
    VERSION 0.1.0
    DESCRIPTION "Learning reinforcement learning in C++"
    LANGUAGES CXX)

# Project wide C++ standard
set(CMAKE_CXX_STANDARD 17)

# -- Protocol buffers -- (used by tensorboard) - https://github.com/protocolbuffers/protobuf
# (Built and located in /usr/lib/... during Docker environemnt setup)
include(FindProtobuf)
find_package(Protobuf REQUIRED)
message(STATUS "Using protobuf version: ${Protobuf_VERSION}")

# -- PyTorch -- (Facebook research's machine learning framework) - https://pytorch.org/
# (Docker devcontainer should have already installed and configured this)
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/libtorch")
find_package(Torch REQUIRED)
message(STATUS "Using torch version: ${Torch_VERSION}")

# -- Configure all build options for Corrade, Magnum and Magnum-Plugins --

# Magnum Configuration
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})

# For easy release on Linux machine, set to static:
# Remember that the host machine will still need libSDS2-2.0.so.0
# So run something like `sudo apt install libsdl2-2.0`
set(BUILD_STATIC ON CACHE BOOL "" FORCE)
set(BUILD_PLUGINS_STATIC ON CACHE BOOL "" FORCE)

# -- File Loading --

# Corrade build multithreaded
#set(CORRADE_BUILD_MULTITHREADED ON CACHE BOOL "" FORCE)

# Loading OBJ files
set(WITH_ANYIMAGEIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_ANYSCENEIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_OBJIMPORTER ON CACHE BOOL "" FORCE)

# If you want to load (textured) glTF as well
set(WITH_STBIMAGEIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_TINYGLTFIMPORTER ON CACHE BOOL "" FORCE)

# -- Bullet --

# Disable Bullet tests and demos
set(BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(BUILD_BULLET2_DEMOS OFF CACHE BOOL "" FORCE)
set(BUILD_CPU_DEMOS OFF CACHE BOOL "" FORCE)
set(BUILD_OPENGL3_DEMOS OFF CACHE BOOL "" FORCE)
# While not needed for Magnum, you might actually want some of those
set(BUILD_ENET OFF CACHE BOOL "" FORCE)
set(BUILD_CLSOCKET OFF CACHE BOOL "" FORCE)
set(BUILD_EXTRAS OFF CACHE BOOL "" FORCE)
set(BUILD_BULLET3 OFF CACHE BOOL "" FORCE)
# This is needed in case BUILD_EXTRAS is enabled, as you'd get a CMake syntax
# error otherwise
set(PKGCONFIG_INSTALL_PREFIX "lib${LIB_SUFFIX}/pkgconfig/")
# Actuallly enable bullet!
#set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
set(WITH_BULLET ON CACHE BOOL "" FORCE)

# -- General --

# Enable Magnum Sdl2Application
set(WITH_SDL2APPLICATION ON CACHE BOOL "" FORCE)

# Add libraries (submodules of third party and external libraries)
add_subdirectory(lib)

# Recurse into src.
add_subdirectory(src)

# Recurse into tests.
add_subdirectory(test)
