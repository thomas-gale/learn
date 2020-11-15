#include <exception>
#include <random>

#include "learn/environment/gym/Space.hpp"

namespace learn {
namespace environment {
namespace gym {

// Base (non-template) case (std::vector<float>) just directly return the
// vector.
std::vector<float> Space::flattenVector(const std::vector<float>& vec) {
    return vec;
}

// Space - Basic C'tor implementation.
Space::Space(SpaceType type, std::vector<int> boxShape,
             std::vector<float> boxHigh, std::vector<float> boxLow,
             int discreetN)
    : type(type), boxShape(boxShape), boxHigh(boxHigh), boxLow(boxLow),
      discreetN(discreetN) {
    // Preconditions.
    if (boxHigh.size() != boxLow.size())
        throw std::runtime_error("boxHigh size is not equal to boxLow size");
}

// Sample - Given a space, sample and return a flattened set of values from the
// space.
std::vector<float> Space::sample() const {
    // Random source - this should move to some util?
    std::random_device dev;
    std::mt19937 rng(dev());

    std::vector<float> res(boxHigh.size());
    // Box high and box low are already flattened to the shape and c'tor asserted that the size is the same.
    for (size_t i = 0; i < boxHigh.size(); ++i) {
        std::uniform_real_distribution dist(boxLow[i], boxHigh[i]);
        res[i] = dist(rng);
    }
    return res;
}

} // namespace gym
} // namespace environment
} // namespace learn
