#include "learn/environment/BulletEnvironment.hpp"
#include "gtest/gtest.h"

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