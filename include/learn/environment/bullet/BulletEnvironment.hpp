#ifndef LEARN_ENV_BULLET_BULLETENVIRONMENT_H_
#define LEARN_ENV_BULLET_BULLETENVIRONMENT_H_

#include "learn/environment/gym/Environment.hpp"
#include "learn/environment/gym/Space.hpp"
#include "learn/environment/gym/State.hpp"

namespace learn {
namespace environment {
namespace bullet {

class BulletEnvironment : public gym::Environment {
  public:
    std::shared_ptr<gym::Space> action_space() override;
    std::shared_ptr<gym::Space> observation_space() override;

    void reset(gym::State* save_initial_state_here) override;
    void step(const std::vector<float>& action, bool render,
              gym::State* save_state_here) override;
    void monitor_start(const std::string& directory, bool force,
                       bool resume) override;
    void monitor_stop() override;

  private:
    // Bullet related internal state.
};

} // namespace bullet
} // namespace environment
} // namespace learn

#endif // LEARN_ENV_BULLET_BULLETENVIRONMENT_H_