#ifndef LEARN_ENV_BULLET_H_
#define LEARN_ENV_BULLET_H_

#include "learn/environment/Gym.hpp"

namespace learn {
namespace environment {

class BulletEnvironment : public Environment {
  public:
    std::shared_ptr<Space> action_space() override;
    std::shared_ptr<Space> observation_space() override;

    void reset(State* save_initial_state_here) override;
    void step(const std::vector<float>& action, bool render,
              State* save_state_here) override;
    void monitor_start(const std::string& directory, bool force,
                       bool resume) override;
    void monitor_stop() override;
};

} // namespace environment
} // namespace learn

#endif // LEARN_ENV_BULLET_H_