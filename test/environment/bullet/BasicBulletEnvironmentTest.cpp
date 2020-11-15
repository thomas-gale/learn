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

} // namespace test
} // namespace bullet
} // namespace environment
} // namespace learn