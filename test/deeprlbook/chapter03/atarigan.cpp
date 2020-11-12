#include "gtest/gtest.h"

#include <cmath>

namespace learn {
namespace test {

constexpr int LATENT_VECTOR_SIZE = 100;
constexpr int DISCR_FILTERS = 64;
constexpr int GENER_FILTERS = 64;
constexpr int BATCH_SIZE = 16;

// dimension input image will be rescaled
constexpr int IMAGE_SIZE = 64;

constexpr double LEARNING_RATE = 0.0001;
constexpr int REPORT_EVERY_ITER = 100;
constexpr int SAVE_IMAGE_EVERY_ITER = 1000;

TEST(DRLChapter03, AtariCaptureImage) {
    // Start Atari space

    // Make random move

    // Capture Image

    // Log image to tensorboard
}

TEST(DRLChapter03, AtariGan) {
    /*SummaryWriter writer;

    std::vector<std::tuple<std::string, std::function<float(float)>>> funcs{
        { "Sin", [](float x){ return std::sin(x); } },
        { "Cos", [](float x){ return std::cos(x); } },
        { "Tan", [](float x){ return std::tan(x); } }
    };

    float pi = std::atan(1)*4.0;
    for (int angle = -360; angle <= 360; ++angle) {
        float angleRad = float(angle) * (pi / 180.0);
        for (const auto& func : funcs) {
            float val = std::get<1>(func)(angleRad);
            bool success = writer.addScalar(std::get<0>(func), val, angle);
            ASSERT_TRUE(success);
        }
    }*/
}
} // namespace test
} // namespace learn