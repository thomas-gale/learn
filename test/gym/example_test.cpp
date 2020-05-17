#include "gtest/gtest.h"
#include "../../src/gym/gym_client/example.h"

namespace TestLearn {
    TEST(GymClient, RunExample) {
        // Act
        Learn::example();
    }
}