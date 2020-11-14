#include "learn/environment/bullet/BulletEnvironment.hpp"
#include "gtest/gtest.h"

namespace learn {
namespace test {

TEST(BulletEnvironment, Construct) {
    // Act
    environment::bullet::BulletEnvironment bulletEnv;

    // Assert
    // Not thrown
}

} // namespace test
} // namespace learn