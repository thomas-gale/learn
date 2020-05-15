#include "gtest/gtest.h"
#include "../src/hello-torch.h"

namespace TestLearn {
    TEST(HelloTorch, FirstTest) {
        // Act
        Learn::hellotorch();
    }
}