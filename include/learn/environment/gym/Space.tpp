#ifndef LEARN_ENV_GYM_SPACE_T_
#define LEARN_ENV_GYM_SPACE_T_

#include "learn/environment/gym/Space.hpp"
#include <vector>

namespace learn {
namespace environment {
namespace gym {

// Utiltity function to flatten vector (using recursive template).
// Reference:
// https://github.com/Omegastick/pytorch-cpp-rl/blob/master/example/gym_client.cpp#L53
template <class T>
std::vector<float>
Space::flattenVector(const std::vector<std::vector<T>>& vec) {
    std::vector<float> out;
    for (const auto& element : vec) {
        auto subVec = Space::flattenVector(element);
        out.reserve(out.size() + subVec.size());
        out.insert(out.end(), subVec.cbegin(), subVec.cend());
    }
    return out;
}

} // namespace gym
} // namespace environment
} // namespace learn

#endif // LEARN_ENV_GYM_SPACE_T_