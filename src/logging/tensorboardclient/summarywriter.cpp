#include "learn/communicator/communicator.h"
#include "learn/communicator/requests.h"
#include "learn/logging/summarywriter.h"

namespace com = communicator;

namespace learn {

    // TODO: Remove the magic string.
    SummaryWriter::SummaryWriter(): tensorboardWriter("tcp://127.0.0.1:10202") {}

    bool SummaryWriter::addScalar(std::string tag, double scalarValue, double globalStep) {
        // Talk to tensorboard server code python though zmq.
        auto scalarParam = std::make_shared<com::LogScalarParam>();
        scalarParam->tag = tag;
        scalarParam->scalar_value = scalarValue;
        scalarParam->global_step = globalStep;
        com::Request<com::LogScalarParam> addScalarRequest("add_scalar", scalarParam);

        // Outbound message
        tensorboardWriter.send_request(addScalarRequest);

        // Request status
        return tensorboardWriter.get_response<com::LogResponse>()->success;
    }

} // namespace learn 
