#include "gtest/gtest.h"
#include "learn/logging/summarywriter.h"

namespace testlearn {
    TEST(Logging, CanCreateSummaryWriter) {
        // Act / Assert
        ASSERT_NO_THROW(learn::SummaryWriter summaryWriter);        
    }
    
    TEST(Logging, CanLogScalar) {
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
    }
}
