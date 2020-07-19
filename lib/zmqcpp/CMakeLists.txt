set(HEADER_LIST "${3P_DIR}/zmqcpp/zmq.hpp")

add_library(zmqcpp
    ${HEADER_LIST})

#target_compile_options(zmqcpp PRIVATE -Wall -Wextra -pedantic)

# We need this directory, and users of our library will need it too
target_include_directories(zmqcpp
    PUBLIC 
    ${ZMQ_DIR}/include)

target_link_libraries(zmqcpp 
    PRIVATE
    libzmq-static)
