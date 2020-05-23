add_subdirectory(gym/gym_client)

add_library(hellolearn
hellotorch.h
hellotorch.cpp
)

target_compile_options(hellolearn PRIVATE -Wall -Wextra -pedantic)

find_package(Torch REQUIRED)
target_include_directories(hellolearn PUBLIC ${TORCH_INCLUDE_DIRS})
target_link_libraries(hellolearn ${TORCH_LIBRARIES})
