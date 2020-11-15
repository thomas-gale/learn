#ifndef LEARN_ENV_GYM_SPACE_H_
#define LEARN_ENV_GYM_SPACE_H_

#include <memory>
#include <vector>

namespace learn {
namespace environment {
namespace gym {

class Space {
  public:
    enum SpaceType {
        DISCRETE,
        BOX,
    } type;

    // boxShape - E.g. { 64, 96, 3 } for 96x64 rgb image.
    std::vector<int> boxShape;
    std::vector<float> boxHigh;
    std::vector<float> boxLow;
    int discreetN;

    // Utiltity function to flatten vector base case.
    static std::vector<float> flattenVector(const std::vector<float>& vec);

    // Utiltity function to flatten vector (using recursive template).
    template <class T>
    static std::vector<float> flattenVector(const std::vector<std::vector<T>>& vec);

    // C'tor - boxHigh and boxLow should be flattened sample ranges with length
    // = product of boxShape values.
    Space(SpaceType type, std::vector<int> boxShape, std::vector<float> boxHigh,
          std::vector<float> boxLow, int discreetN);

    // Random flattened vector that belong to this space
    std::vector<float> sample();
};

} // namespace gym
} // namespace environment
} // namespace learn

// Template implementations
#include "learn/environment/gym/Space.tpp"

#endif // LEARN_ENV_GYM_SPACE_H_
