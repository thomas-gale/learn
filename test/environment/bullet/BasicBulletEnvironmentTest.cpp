#include "learn/environment/bullet/BasicBulletEnvironment.hpp"
#include "gtest/gtest.h"

namespace learn {
namespace environment {
namespace bullet {
namespace test {

TEST(BulletEnvironment, Construct) {
    // Act
    environment::bullet::BasicBulletEnvironment bulletEnv;

    // Assert
    // Not thrown
}

/*    actionSpace_ = std::make_shared<gym::Space>(
        gym::Space::SpaceType::BOX, std::vector<int>{2},
        std::vector<float>{1.0, 1.0}, std::vector<float>{-1.0, -1.0}, -1);
    observationSpace_ = std::make_shared<gym::Space>(
        gym::Space::SpaceType::BOX, std::vector<int>{2},
        std::vector<float>{std::numeric_limits<float>::max(),
                           std::numeric_limits<float>::max()},
        std::vector<float>{std::numeric_limits<float>::min(),
                           std::numeric_limits<float>::min()},
*/

TEST(BulletEnvironment, GetActionSpace) {
    // Arrange
    environment::bullet::BasicBulletEnvironment bulletEnv;

    // Act
    auto actionSpace = bulletEnv.actionSpace();

    // Assert
    EXPECT_NE(actionSpace, nullptr);
    EXPECT_EQ(actionSpace->boxShape[0], 2);
    EXPECT_FLOAT_EQ(actionSpace->boxHigh[0], 1.0);
    EXPECT_FLOAT_EQ(actionSpace->boxHigh[1], 1.0);
    EXPECT_FLOAT_EQ(actionSpace->boxLow[0], -1.0);
    EXPECT_FLOAT_EQ(actionSpace->boxLow[1], -1.0);
}

TEST(BulletEnvironment, GetObservationSpace) {
    // Arrange
    environment::bullet::BasicBulletEnvironment bulletEnv;

    // Act
    auto space = bulletEnv.observationSpace();

    // Assert
    EXPECT_NE(space, nullptr);
    EXPECT_EQ(space->boxShape[0], 2);
    EXPECT_FLOAT_EQ(space->boxHigh[0], std::numeric_limits<float>::max());
    EXPECT_FLOAT_EQ(space->boxHigh[1], std::numeric_limits<float>::max());
    EXPECT_FLOAT_EQ(space->boxLow[0], std::numeric_limits<float>::min());
    EXPECT_FLOAT_EQ(space->boxLow[1], std::numeric_limits<float>::min());
}

TEST(BulletEnvironment, Reset) {
    // Arrange
    environment::bullet::BasicBulletEnvironment bulletEnv;

    // Act
    auto state = bulletEnv.reset();

    // Assert
    EXPECT_NE(state, nullptr);
    EXPECT_FLOAT_EQ(state->observation[0], 0.0);
    EXPECT_FLOAT_EQ(state->observation[1], 0.0);
    EXPECT_FLOAT_EQ(state->reward, -5.0);
    EXPECT_FLOAT_EQ(state->done, false);
    EXPECT_TRUE(state->info == "Reset");
}

} // namespace test
} // namespace bullet
} // namespace environment
} // namespace learn