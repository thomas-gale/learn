# Derived from https://github.com/google/googletest/blob/master/googletest/README.md

enable_testing()

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(learn_test
  hello/HelloTorchTest.cpp
  environment/bullet/BasicBulletEnvironmentTest.cpp
  environment/bullet/BulletClientTest.cpp
  environment/gym/SpaceTest.cpp
  agent/MuZeroTest.cpp
  logging/TensorboardLoggerTest.cpp)


target_include_directories(learn_test PRIVATE
  "${Learn_SOURCE_DIR}/include"
  ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(learn_test PRIVATE
  hellolearn
  learn_environment
  learn_agent
  tensorboard_logger  
  gtest_main)

# Copy test resources
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/logging/resources/doge.png ${CMAKE_CURRENT_BINARY_DIR}/resources/doge.png COPYONLY)

# Register test so that ctest and make test can run it.
add_test(NAME test_learn_test COMMAND learn_test)
