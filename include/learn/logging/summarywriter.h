#ifndef _LEARN_LOGGING_SUMMARYWRITER
#define _LEARN_LOGGING_SUMMARYWRITER

#include <string>
#include "../communicator/communicator.h"

namespace learn {

class SummaryWriter {
public:
    SummaryWriter();
    bool addScalar(std::string tag, double scalarValue, double globalStep);

private:
    communicator::Communicator tensorboardWriter;
};

} // namespace learn 
#endif // _LEARN_LOGGING_SUMMARYWRITER
