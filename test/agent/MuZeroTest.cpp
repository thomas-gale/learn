#include "learn/agent/MuZero.hpp"
#include "learn/environment/bullet/BasicBulletEnvironment.hpp"
#include "gtest/gtest.h"

namespace learn {
namespace test {

TEST(MuZero, Create) {
    // Arrange
    std::shared_ptr<environment::bullet::BasicBulletEnvironment> bulletEnv;

    // Act
    agent::MuZero mZero(bulletEnv);

    // Assert
    // Not thrown
}

} // namespace test
} // namespace learn