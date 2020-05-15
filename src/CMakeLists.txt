## PyTorch (Docker devcontainer should have already configured this)
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/libtorch")
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_library(learn
  hello-torch.h
  hello-torch.cpp
)

target_compile_options(learn PRIVATE -Wall -Wextra -pedantic)

target_include_directories(learn PRIVATE ${TORCH_INCLUDE_DIRS})