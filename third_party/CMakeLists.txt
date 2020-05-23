# Third parties.
set(3P_DIR ${CMAKE_SOURCE_DIR}/third_party CACHE STRING "")

# Lightweight messaging kernel - https://github.com/zeromq/libzmq
set(ZMQ_DIR ${3P_DIR}/libzmq CACHE STRING "")
add_subdirectory(libzmq)
set(ZMQ_BUILD_TESTS OFF CACHE BOOL "")

# MessagePack is an efficient binary serialization format - https://github.com/msgpack/msgpack-c
set(MSGPACK_DIR ${3P_DIR}/msgpack-c CACHE STRING "")

# Fast C++ logging library - https://github.com/gabime/spdlog
set(SPDLOG_DIR ${3P_DIR}/spdlog CACHE STRING "")
add_subdirectory(spdlog)
