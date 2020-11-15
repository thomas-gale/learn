#include "learn/environment/gym/Space.hpp"
#include "gtest/gtest.h"

namespace learn {
namespace environment {
namespace gym {
namespace test {

TEST(SpaceTest, FlattenBase) {
    // Arrange
    std::vector<float> testVec{1, 2};   

    // Act
    std::vector<float> flat = Space::flattenVector(testVec);

    // Assert
    EXPECT_EQ(flat.size(), 2);
}



TEST(SpaceTest, FlattenRecursive) {
    // Arrange
    std::vector<std::vector<float>> testVec{{1, 2}, {3, 4}};   

    // Act
    std::vector<float> flat = Space::flattenVector(testVec);

    // Assert
    EXPECT_EQ(flat.size(), 4);
}

TEST(SpaceTest, FlattenRecursiveDeep) {
    // Arrange
    std::vector<std::vector<float>> testVec{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};   

    // Act
    std::vector<float> flat = Space::flattenVector(testVec);

    // Assert
    EXPECT_EQ(flat.size(), 9);
}

} // namespace test
} // namespace gym
} // namespace environment
} // namespace learn