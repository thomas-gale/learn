#include "gtest/gtest.h"
#include "learn/hellotorch.hpp"

namespace TestLearn {
    TEST(HelloTorch, FirstTest) {
        // Act
        learn::hellotorch();
    }
}