#ifndef LEARN_ENV_MAGNUM_BASICMAGNUMENVIRONMENT_H_
#define LEARN_ENV_MAGNUM_BASICMAGNUMENVIRONMENT_H_

#include "learn/environment/gym/Environment.hpp"
#include "learn/environment/gym/Space.hpp"
#include "learn/environment/gym/State.hpp"
#include <Magnum/Platform/GLContext.h>
#include <Magnum/Platform/Sdl2Application.h>

namespace learn {
namespace environment {
namespace magnum {

class BasicMagnumEnvironment : public gym::Environment {
  public:
    // Construct the magnum environment and initialise window.
    BasicMagnumEnvironment();

    // Destruct magnum environment and destroy window.
    ~BasicMagnumEnvironment();

    // Suppressing copy semantics for now.
    BasicMagnumEnvironment(const BasicMagnumEnvironment& other) = delete;
    BasicMagnumEnvironment& operator=(const BasicMagnumEnvironment* other) = delete;

    // Suppressing move semantics for now.
    BasicMagnumEnvironment(BasicMagnumEnvironment&& other) = delete;
    BasicMagnumEnvironment& operator=(BasicMagnumEnvironment&& other) = delete;

    // Get the action space for the environment.
    std::shared_ptr<gym::Space> actionSpace() const override;

    // Get the observation space for the environment.
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

} // namespace magnum
} // namespace environment
} // namespace learn

#endif // LEARN_ENV_MAGNUM_BASICMAGNUMENVIRONMENT_H_