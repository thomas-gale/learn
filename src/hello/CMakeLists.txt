set(HEADER_LIST 
    "${Learn_SOURCE_DIR}/include/learn/HelloTorch.hpp")

# hello learn is an automatic library
add_library(hellolearn 
    ${HEADER_LIST}
    HelloTorch.cpp
)

target_compile_options(hellolearn PRIVATE -Wall -Wextra -pedantic)

# We need this directory, and users of our library will need it too
target_include_directories(hellolearn PUBLIC 
    "${Learn_SOURCE_DIR}/include"
    ${TORCH_INCLUDE_DIRS}
)

# This depends on (header only) Torch
target_link_libraries(hellolearn PRIVATE ${TORCH_LIBRARIES})
