add_library(gym_client
requests.h
communicator.h
communicator.cpp
example.h
example.cpp
)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

target_include_directories(gym_client 
    PRIVATE
    ${MSGPACK_DIR}/include
    ${SPDLOG_DIR}/include
    ${ZMQ_DIR}/include
    ${TORCH_INCLUDE_DIRS}
)

target_link_libraries(gym_client PRIVATE libzmq-static ${TORCH_INCLUDE_DIRS})
