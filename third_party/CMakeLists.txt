# Third parties.
set(3P_DIR ${CMAKE_SOURCE_DIR}/third_party)

# Lightweight messaging kernel - https://github.com/zeromq/libzmq
set(ZMQ_DIR ${3P_DIR}/libzmq)
add_subdirectory(libzmq)
option(ZMQ_BUILD_TESTS "" OFF)

# MessagePack is an efficient binary serialization format - https://github.com/msgpack/msgpack-c
set(MSGPACK_DIR ${3P_DIR}/msgpack-c)

# Fast C++ logging library - https://github.com/gabime/spdlog
set(SPDLOG_DIR ${3P_DIR}/spdlog)
add_subdirectory(spdlog)

# PyTorch (Facebook research's machine learning framework) - https://pytorch.org/
# (Docker devcontainer should have already installed and configured this)
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/libtorch")
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
