add_library(hellolearn
hellotorch.h
hellotorch.cpp
)

target_compile_options(hellolearn PRIVATE -Wall -Wextra -pedantic)

target_include_directories(hellolearn PRIVATE ${TORCH_INCLUDE_DIRS})

target_link_libraries(hellolearn ${TORCH_LIBRARIES})
