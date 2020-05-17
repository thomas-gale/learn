add_library(gym_client
requests.h
communicator.h
communicator.cpp
example.h
example.cpp
)

set(3P_DIR ${CMAKE_SOURCE_DIR}/third_party)
set(CPPZMQ_DIR ${3P_DIR}/cppzmq)
set(MSGPACK_DIR ${3P_DIR}/msgpack-c)
set(SPDLOG_DIR ${3P_DIR}/spdlog)
set(ZMQ_DIR ${3P_DIR}/libzmq)

# Spdlog
add_subdirectory(${SPDLOG_DIR})
# ZMQ
option(ZMQ_BUILD_TESTS "" OFF)
add_subdirectory(${ZMQ_DIR})

target_include_directories(gym_client 
    PRIVATE
    .
    ${CPPZMQ_DIR}
    ${MSGPACK_DIR}/include
    ${SPDLOG_DIR}/include
    ${ZMQ_DIR}/include
)

target_link_libraries(gym_client PRIVATE libzmq-static)