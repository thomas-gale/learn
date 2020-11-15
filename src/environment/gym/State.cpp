#include "learn/environment/gym/State.hpp"

namespace learn {
namespace environment {
namespace gym {

State::State(std::vector<float> observation, float reward, bool done,
             std::string info)
    : observation(observation), reward(reward), done(done), info(info) {}


} // namespace gym
} // namespace environment
} // namespace learn
