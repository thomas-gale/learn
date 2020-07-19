# External and third party libraries.
set(3P_DIR ${CMAKE_SOURCE_DIR}/lib CACHE STRING "")

# Lightweight messaging kernel - https://github.com/zeromq/libzmq
set(ZMQ_DIR ${3P_DIR}/libzmq CACHE STRING "")
option(ZMQ_BUILD_TESTS "" OFF)
add_subdirectory(libzmq)

# C++ adapted wrapper around libzmq
set(ZMQCPP_DIR ${3P_DIR}/zmqcpp CACHE STRING "")
add_subdirectory(zmqcpp)

# MessagePack is an efficient binary serialization format - https://github.com/msgpack/msgpack-c
set(MSGPACK_DIR ${3P_DIR}/msgpack-c CACHE STRING "")

# Fast C++ logging library - https://github.com/gabime/spdlog
set(SPDLOG_DIR ${3P_DIR}/spdlog CACHE STRING "")
add_subdirectory(spdlog)

# C++ API to log data in tensorboard format - https://github.com/RustingSword/tensorboard_logger
set(TENSOR_LOG_DIR ${3P_DIR}/tensorboard_logger CACHE STRING "")
add_subdirectory(tensorboard_logger)
