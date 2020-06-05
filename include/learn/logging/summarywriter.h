#ifndef _LEARN_LOGGING_SUMMARYWRITER
#define _LEARN_LOGGING_SUMMARYWRITER

#include <string>

namespace learn {

class SummaryWriter {
public:
    void addScalar(std::string name, double y, double x);


};
} // namespace learn 

#endif // _LEARN_LOGGING_SUMMARYWRITER
