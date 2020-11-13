#include "gtest/gtest.h"
#include "learn/environment/Bullet.hpp"

namespace learn {
namespace test {

TEST(BulletEnvironment, Construct) {
    // Act
    environment::BulletEnvironment bulletEnv;

    // Assert
    // Not thrown
}

} // namespace test
} // namespace learn