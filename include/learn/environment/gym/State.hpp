#ifndef LEARN_ENV_GYM_STATE_H_
#define LEARN_ENV_GYM_STATE_H_

#include <memory>
#include <vector>

namespace learn {
namespace environment {
namespace gym {

struct State {
    std::vector<float>
        observation; // get observation_space() to make sense of this data
    float reward;
    bool done;
    std::string info;
};

} // namespace gym
} // namespace environment
} // namespace learn

#endif // LEARN_ENV_GYM_STATE_H_
