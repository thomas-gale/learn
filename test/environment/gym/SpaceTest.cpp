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

TEST(SpaceTest, Construct) {
    // Arrange

    // Act
    Space space(Space::SpaceType::BOX, std::vector<int>{4},
                std::vector<float>{100.0, 50.0, 10.0},
                std::vector<float>{0.0, -50.0, 0.0}, -1);

    // Assert (not throw)
}

TEST(SpaceTest, Sample) {
    // Arrange
    std::vector<float> max{100.0, 50.0, 10.0};
    std::vector<float> min{50.0, -50.0, 0.0};
    Space space(Space::SpaceType::BOX, std::vector<int>{4}, max, min, -1);

    // Act
    std::vector<float> sample = space.sample();

    // Assert
    EXPECT_EQ(sample.size(), 3);
    for (size_t i = 0; i < sample.size(); ++i) {
        if (sample[i] < min[i] || sample[i] > max[i]) {
            FAIL() << "Sample outside expected range";
        }
    }
}

} // namespace test
} // namespace gym
} // namespace environment
} // namespace learn