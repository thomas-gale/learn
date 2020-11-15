#include "learn/environment/bullet/BasicBulletEnvironment.hpp"
#include "gtest/gtest.h"

namespace learn {
namespace test {

TEST(BulletEnvironment, Construct) {
    // Act
    environment::bullet::BasicBulletEnvironment bulletEnv;

    // Assert
    // Not thrown
}

} // namespace test
} // namespace learn