#ifndef LEARN_AGENT_MUZERO_H_
#define LEARN_AGENT_MUZERO_H_

#include <memory>

#include "learn/environment/gym/Environment.hpp"

namespace learn {
namespace agent {

// This is directly derived from https://github.com/werner-duvaud/muzero-general
class MuZero {
  public:
    // C'tor - Inject the Environment created beforehand.
    MuZero(std::shared_ptr<environment::gym::Environment> env);

    // Spawn ray workers and launch the training
    void train();

    // Test the model performance.
    void test(bool render);

    // Load a model and/or a saved replay buffer.
    void loadModel();

    // Play a game only with the learned model then play the same trajectory in
    // the real environment and display information.
    void diagnoseModel();

  private:
    std::shared_ptr<environment::gym::Environment> env_;

    // Keep track of the training performance.
    void loggingLoop();

    // Not sure -  Softly terminate the running tasks and garbage collect the
    // workers. Initially, we won't have multiple workers?
    void terminateWorkers();
};

} // namespace agent
} // namespace learn

#endif // LEARN_AGENT_MUZERO_H_