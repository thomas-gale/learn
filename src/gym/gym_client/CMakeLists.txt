add_library(gym_client
requests.h
communicator.h
communicator.cpp
example.h
example.cpp
)

message(STATUS "TEst: ${MSGPACK_DIR}")

target_include_directories(gym_client 
    PRIVATE
    .
    ${MSGPACK_DIR}/include
    ${SPDLOG_DIR}/include
    ${ZMQ_DIR}/include
)

target_link_libraries(gym_client PRIVATE libzmq-static)
