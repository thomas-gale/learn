#include "learn/environment/bullet/BulletClient.hpp"
#include "gtest/gtest.h"

namespace learn {
namespace test {

TEST(BulletClient, Create) {
    // Act
    environment::bullet::BulletClient bulletClient;

    // Assert
    // Not thrown
}

TEST(BulletClient, MakeBasicEnvironment) {
    // Arrange
    environment::bullet::BulletClient bulletClient;

    // Act
    auto env = bulletClient.make("basic");

    // Assert
    EXPECT_NE(env, nullptr);
}

} // namespace test
} // namespace learn