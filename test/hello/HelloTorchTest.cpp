#include "learn/HelloTorch.hpp"
#include "gtest/gtest.h"

namespace learn {
namespace test {

TEST(HelloTorch, Tensor) {
    // Act
    hellotorch();
}

TEST(HelloTorch, CudaGPU) {
    // Act
    hellotorchgpu();
}

} // namespace test
} // namespace learn