#ifndef _LEARN_LOGGING_SUMMARYWRITER
#define _LEARN_LOGGING_SUMMARYWRITER

#include <string>
#include "../communicator/communicator.h"

namespace learn {

constexpr int LOGGING_PORT = 10202;

class SummaryWriter {
public:
    SummaryWriter();
    bool addScalar(std::string tag, double scalarValue, double globalStep);
    bool addImage(std::string tag, const std::vector<std::vector<float>>& imageTensor, double globalStep);

private:
    communicator::Communicator tensorboardWriter;
};

} // namespace learn 
#endif // _LEARN_LOGGING_SUMMARYWRITER
