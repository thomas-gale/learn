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
    virtual std::shared_ptr<Space> actionSpace() const = 0;
    virtual std::shared_ptr<Space> observationSpace() const = 0;

    // Returns a shared pointer to reset observation state.
    virtual std::shared_ptr<State> reset() = 0;

    // Step the environment with the action and returns shared pointer to new
    // state.
    virtual std::shared_ptr<State> step(const std::vector<float>& action,
                                        bool render) = 0;

    virtual void monitorStart(const std::string& directory, bool force,
                               bool resume) = 0;
    virtual void monitorStop() = 0;
};

} // namespace gym
} // namespace environment
} // namespace learn

#endif // LEARN_ENV_GYM_ENV_H_
