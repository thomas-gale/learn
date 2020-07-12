#include <experimental/filesystem>
#include <string>

#include "gtest/gtest.h"
#include "tensorboard_logger.h"

namespace testlearn {

    namespace fs = std::experimental::filesystem;

    TEST(Logging, CanCreateTensorboardLogger) {
        // Arrange
        fs::create_directory("/workspaces/learn/build/logging_test");
        std::string logFile = "/workspaces/learn/build/logging_test/tfevents.pb";

        // Act / Assert
        ASSERT_NO_THROW(TensorBoardLogger(logFile.c_str()));
    }
    
    /*TEST(Logging, CanLogScalar) {
        // Arrange
        learn::SummaryWriter summaryWriter;

        // Act
        bool success = summaryWriter.addScalar("TestScalar", 0.5, 0.25);

        // Assert
        ASSERT_TRUE(success);
    }

    TEST(Logging, CanLogImage) {
        // Arrange
        learn::SummaryWriter summaryWriter;
        std::vector<std::vector<std::vector<float>>> testImage{
         {{ 0.1, 0.6, 0.0 }, {0.4, 0.6, 0.0}}, 
         {{ 0.2, 0.7, 0.0 }, {0.9, 0.4, 0.0}},
         {{ 0.4, 0.4, 0.0 }, {0.1, 0.3, 0.0}}
        };

        // Act
        bool success = summaryWriter.addImage("TestImage", testImage, 0.25);

        // Assert
        ASSERT_TRUE(success);
    }*/
}
