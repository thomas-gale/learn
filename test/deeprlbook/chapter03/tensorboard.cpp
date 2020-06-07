#include "gtest/gtest.h"

#include <cmath>
#include "learn/logging/summarywriter.h"

using namespace learn;

namespace testlearn {
    TEST(DRLChapter03, CanUseTensorboard) {
        SummaryWriter writer;

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
        }
    }
}