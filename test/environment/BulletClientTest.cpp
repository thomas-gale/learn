#include "learn/environment/BulletClient.hpp"
#include "gtest/gtest.h"

namespace learn {
namespace test {

TEST(BulletClient, Create) {
    // Act
    environment::BulletClient bulletClient;

    // Assert
    // Not thrown
}

TEST(BulletClient, MakeDefaultEnvironment) {
    // Arrange
    environment::BulletClient bulletClient;

    // Act
    auto env = bulletClient.make("default");

    // Assert
    EXPECT_NE(env, nullptr);
}

} // namespace test
} // namespace learn