#include "learn/environment/gym/Space.hpp"

namespace learn {
namespace environment {
namespace gym {

// Base (non-template) case (std::vector<float>) just directly return the vector.
std::vector<float> Space::flattenVector(const std::vector<float>& vec) {
    return vec;
}

Space::Space(SpaceType type, std::vector<int> boxShape,
             std::vector<float> boxHigh, std::vector<float> boxLow,
             int discreetN)
    : type(type), boxShape(boxShape), boxHigh(boxHigh), boxLow(boxLow),
      discreetN(discreetN) {}

std::vector<float> Space::sample() { return std::vector<float>{}; }

} // namespace gym
} // namespace environment
} // namespace learn
