cmake_minimum_required(VERSION 3.17.1)
project(learn
    LANGUAGES CXX
    VERSION 0.1.0
    DESCRIPTION "Learning reinforcement learning in C++"
)

# Project wide C++ standard
set(CMAKE_CXX_STANDARD 17)

# Recurse into source
add_subdirectory(src)

# Recurse into tests.
add_subdirectory(test)

# Define targets
#add_library(cpprl STATIC "")
#target_compile_definitions(cpprl PRIVATE DOCTEST_CONFIG_DISABLE)
#option(CPPRL_BUILD_TESTS "Whether or not to build the CppRl tests" ON)
#if (CPPRL_BUILD_TESTS)
#    add_executable(cpprl_tests "")
#endif(CPPRL_BUILD_TESTS)


# Includes
#set(CPPRL_INCLUDE_DIRS
#    include
#    src
#    ${TORCH_INCLUDE_DIRS}
#)
#target_include_directories(learn PRIVATE ${CPPRL_INCLUDE_DIRS})
#if (CPPRL_BUILD_TESTS)
#    target_include_directories(cpprl_tests PRIVATE ${CPPRL_INCLUDE_DIRS})
#endif(CPPRL_BUILD_TESTS)

# Linking
#target_link_libraries(cpprl torch ${TORCH_LIBRARIES})
#if (CPPRL_BUILD_TESTS)
#    target_link_libraries(cpprl_tests torch ${TORCH_LIBRARIES})
#endif(CPPRL_BUILD_TESTS)

# Example
#option(CPPRL_BUILD_EXAMPLE "Whether or not to build the CppRl Gym example" ON)
#if (CPPRL_BUILD_EXAMPLE)
#    add_subdirectory(example)
#endif(CPPRL_BUILD_EXAMPLE)