add_library(learn
hellotorch.h
hellotorch.cpp
)

target_compile_options(learn PRIVATE -Wall -Wextra -pedantic)

target_include_directories(learn PRIVATE ${TORCH_INCLUDE_DIRS})

target_link_libraries(learn ${TORCH_LIBRARIES})

add_subdirectory(gym/gym_client)