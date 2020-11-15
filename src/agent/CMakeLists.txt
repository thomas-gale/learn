add_library(learn_agent
    MuZero.cpp
    MCTS.cpp)

target_include_directories(learn_agent PUBLIC
    "${Learn_SOURCE_DIR}/include"
    ${TORCH_INCLUDE_DIRS})

target_link_libraries(learn_agent PRIVATE 
    ${TORCH_LIBRARIES})
