#ifndef LEARN_ENV_GYM_ENV_H_
#define LEARN_ENV_GYM_ENV_H_

#include <memory>
#include <vector>

#include "learn/environment/gym/Space.hpp"
#include "learn/environment/gym/State.hpp"

namespace learn {
namespace environment {
namespace gym {

class Environment {
  public:
    virtual std::shared_ptr<Space> action_space() = 0;
    virtual std::shared_ptr<Space> observation_space() = 0;

    virtual void reset(State* save_initial_state_here) = 0;

    virtual void step(const std::vector<float>& action, bool render,
                      State* save_state_here) = 0;

    virtual void monitor_start(const std::string& directory, bool force,
                               bool resume) = 0;
    virtual void monitor_stop() = 0;
};

} // namespace gym
} // namespace environment
} // namespace learn

#endif // LEARN_ENV_GYM_ENV_H_
