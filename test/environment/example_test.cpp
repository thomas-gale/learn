#include "learn/example.hpp"
#include "gtest/gtest.h"

namespace learn {
namespace test {

TEST(GymClient, RunExample) {
    // Act
    learn::example();
}

} // namespace test
} // namespace learn