#ifndef LEARN_ENV_BULLET_BASICBULLETENVIRONMENT_H_
#define LEARN_ENV_BULLET_BASICBULLETENVIRONMENT_H_

#include "learn/environment/gym/Environment.hpp"
#include "learn/environment/gym/Space.hpp"
#include "learn/environment/gym/State.hpp"

namespace learn {
namespace environment {
namespace bullet {

class BasicBulletEnvironment : public gym::Environment {
  public:
    BasicBulletEnvironment();

    std::shared_ptr<gym::Space> actionSpace() const override;
    std::shared_ptr<gym::Space> observationSpace() const override;

    // On reset, the environment emmits a shared pointer for learning agents to
    // grab.
    std::shared_ptr<gym::State> reset() override;

    // On step, the agent updates it's internal state and emits a shared pointer
    // again (this may be inefficient)
    std::shared_ptr<gym::State> step(const std::vector<float>& action,
                                     bool render) override;
    void monitorStart(const std::string& directory, bool force,
                       bool resume) override;
    void monitorStop() override;

  private:
    std::shared_ptr<gym::Space> actionSpace_;
    std::shared_ptr<gym::Space> observationSpace_;
    std::shared_ptr<gym::State> state_;
};

} // namespace bullet
} // namespace environment
} // namespace learn

#endif // LEARN_ENV_BULLET_BASICBULLETENVIRONMENT_H_