#include <cstdio>
#include <experimental/filesystem>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

#include "tensorboard_logger.h"
#include "gtest/gtest.h"

namespace learn {
namespace test {

namespace fs = std::experimental::filesystem;

class TensorBoardLoggerTest : public ::testing::Test {
  public:
    const std::string_view LOG_DIR = "/workspaces/learn/build/logs";

  protected:
    fs::path logFile;
    std::unique_ptr<TensorBoardLogger> logger;

    void SetUp() override {
        fs::create_directory(LOG_DIR);
        logFile = fs::path("/workspaces/learn/build/logs/tfevents.pb");
        logger = std::make_unique<TensorBoardLogger>(logFile.c_str());
    }

    void TearDown() override {
        ASSERT_TRUE(fs::remove(logFile))
            << "Unable to tear down and remove logFile";
    }
};

TEST_F(TensorBoardLoggerTest, CanLogScalar) {
    // Arrange - test scalar and histogram
    std::default_random_engine generator;
    std::normal_distribution<double> default_distribution(0, 1.0);
    for (int i = 0; i < 10; ++i) {
        std::normal_distribution<double> distribution(i * 0.1, 1.0);
        std::vector<float> values;
        for (int j = 0; j < 10000; ++j)
            values.push_back(distribution(generator));
        // Act & Assert
        ASSERT_EQ(0, logger->add_histogram("param", i, values))
            << "Unable to add histogram";
        ASSERT_EQ(0,
                  logger->add_scalar("acc", i, default_distribution(generator)))
            << "Unable to add scalar";
    }
}

TEST_F(TensorBoardLoggerTest, CanLogImage) {
    // Arrange
    std::ifstream input("build/test/resources/doge.png", std::ios::binary);
    std::ostringstream ss;
    ss << input.rdbuf();
    std::string dogeImage(ss.str());
    input.close();

    // Act & Assert
    ASSERT_EQ(0, logger->add_image("wonderful image", 1, dogeImage, 800, 636, 3,
                                   "Doge", "Image of Doge"))
        << "Unable to add single image";
}
} // namespace test
} // namespace learn
