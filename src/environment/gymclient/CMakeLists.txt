set(HEADER_LIST "${Learn_SOURCE_DIR}/include/learn/example.h")

add_library(gymclient
    ${HEADER_LIST}
    example.cpp)

#target_compile_options(gym_client PRIVATE -Wall -Wextra -pedantic)

# We need this directory, and users of our library will need it too
target_include_directories(gymclient
    PUBLIC 
    "${Learn_SOURCE_DIR}/include"
    ${TORCH_INCLUDE_DIRS})

target_include_directories(gymclient 
    PRIVATE
    ${MSGPACK_DIR}/include
    ${SPDLOG_DIR}/include
    ${ZMQCPP_DIR})

target_link_libraries(gymclient 
    PRIVATE
    zmqcpp
    communicator
    ${TORCH_LIBRARIES})
