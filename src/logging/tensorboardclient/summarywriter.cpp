#include "learn/communicator/communicator.h"
#include "learn/communicator/requests.h"
#include "learn/logging/summarywriter.h"

namespace com = communicator;

namespace learn {

    bool SummaryWriter::addScalar(std::string name, double y, double x) {
        // Talk to tensorboard server code python though zmq.

        // HACK
        com::Communicator communicator("tcp://127.0.0.1:10202");

        auto log_scalar_param = std::make_shared<com::LogScalarParam>();
        log_scalar_param->tag = "test_val";
        log_scalar_param->scalar_value = 42.42;
        log_scalar_param->global_step = 2.45;
        com::Request<com::LogScalarParam> addScalarRequest("add_scalar", log_scalar_param);
        communicator.send_request(addScalarRequest);

        return communicator.get_response<com::LogResponse>()->success;
    }

} // namespace learn 
