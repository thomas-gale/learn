#include "gtest/gtest.h"
#include "learn/logging/summarywriter.h"

namespace testlearn {
    TEST(Logging, CanCreateSummaryWriter) {
        // Act / Assert
        ASSERT_NO_THROW(learn::SummaryWriter summaryWriter);        
    }
    
    /*TEST(SummaryWriter, CanLogScalar) {
        // Act
        learn::example();
    }*/
}
