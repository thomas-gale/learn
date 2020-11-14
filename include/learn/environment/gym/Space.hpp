#ifndef LEARN_ENV_GYM_SPACE_H_
#define LEARN_ENV_GYM_SPACE_H_

#include <memory>
#include <vector>

namespace learn {
namespace environment {
namespace gym {

struct Space {
    enum SpaceType {
        DISCRETE,
        BOX,
    } type;

    std::vector<float> sample(); // Random vector that belong to this space

    std::vector<int> box_shape; // Similar to Caffe blob shape, for example
                                // { 64, 96, 3 } for 96x64 rgb image.
    std::vector<float> box_high;
    std::vector<float> box_low;

    int discreet_n;
};

} // namespace gym
} // namespace environment
} // namespace learn

#endif // LEARN_ENV_GYM_SPACE_H_
