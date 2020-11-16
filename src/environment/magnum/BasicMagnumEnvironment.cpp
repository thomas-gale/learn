#include "learn/environment/magnum/BasicMagnumEnvironment.hpp"

namespace learn {
namespace environment {
namespace magnum {

BasicMagnumEnvironment::BasicMagnumEnvironment() {
    actionSpace_ = std::make_shared<gym::Space>(
        gym::Space::SpaceType::BOX, std::vector<int>{2},
        std::vector<float>{1.0, 1.0}, std::vector<float>{-1.0, -1.0}, -1);
    observationSpace_ = std::make_shared<gym::Space>(
        gym::Space::SpaceType::BOX, std::vector<int>{2},
        std::vector<float>{std::numeric_limits<float>::max(),
                           std::numeric_limits<float>::max()},
        std::vector<float>{std::numeric_limits<float>::min(),
                           std::numeric_limits<float>::min()},
        -1);
    state_ = reset();
}


std::shared_ptr<gym::Space> BasicMagnumEnvironment::actionSpace() const {
    return actionSpace_;
}

std::shared_ptr<gym::Space> BasicMagnumEnvironment::observationSpace() const {
    return observationSpace_;
}

std::shared_ptr<gym::State> BasicMagnumEnvironment::reset() {
    // Return a copy to the smart pointer for optional consumption by clients.
    return state_;
}

std::shared_ptr<gym::State>
BasicMagnumEnvironment::step(const std::vector<float>& action, bool render) {
    // Mutate state_
    return state_;
}

void BasicMagnumEnvironment::monitorStart(const std::string& directory,
                                          bool force, bool resume) {
    // Start monitor
    // We can use the Tensorboard implementation?
}

void BasicMagnumEnvironment::monitorStop() {
    // Stop montor
    // We can use the Tensorboard implementation?
}

} // namespace magnum
} // namespace environment
} // namespace learn
