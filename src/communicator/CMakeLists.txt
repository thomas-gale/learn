set(HEADER_LIST 
 "${Learn_SOURCE_DIR}/include/learn/communicator/requests.h"
 "${Learn_SOURCE_DIR}/include/learn/communicator/communicator.h")

add_library(communicator
    ${HEADER_LIST}
    communicator.cpp)

#target_compile_options(communicator PRIVATE -Wall -Wextra -pedantic)
target_include_directories(communicator 
    PUBLIC
    "${Learn_SOURCE_DIR}/include")

target_include_directories(communicator 
    PRIVATE
    ${MSGPACK_DIR}/include
    ${SPDLOG_DIR}/include
    ${ZMQCPP_DIR})

target_link_libraries(communicator 
    PRIVATE
    zmqcpp)
