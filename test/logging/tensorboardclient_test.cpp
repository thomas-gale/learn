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

        // Act
        bool success = summaryWriter.addImage("TestScalar", 0.5, 0.25);

        // Assert
        ASSERT_TRUE(success);
    }
}
