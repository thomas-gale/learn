# External and third party libraries.
set(3P_DIR ${CMAKE_SOURCE_DIR}/lib CACHE STRING "")

# Magnum + Bullet
add_subdirectory(corrade EXCLUDE_FROM_ALL)
add_subdirectory(magnum EXCLUDE_FROM_ALL)
add_subdirectory(magnum-plugins EXCLUDE_FROM_ALL)
add_subdirectory(bullet3 EXCLUDE_FROM_ALL)
add_subdirectory(magnum-integration EXCLUDE_FROM_ALL)

# C++ API to log data in tensorboard format - https://github.com/RustingSword/tensorboard_logger
set(TENSOR_LOG_DIR ${3P_DIR}/tensorboard_logger CACHE STRING "")
add_subdirectory(tensorboard_logger)
