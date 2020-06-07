#include "learn/communicator/communicator.h"
#include "learn/communicator/requests.h"
#include "learn/logging/summarywriter.h"

namespace com = communicator;

namespace learn {

    // TODO: Remove the magic string.
    SummaryWriter::SummaryWriter(): tensorboardWriter("tcp://127.0.0.1:" + std::to_string(LOGGING_PORT)) {} 

    bool SummaryWriter::addScalar(std::string tag, double scalarValue, double globalStep) {
        // Talk to tensorboard server code python though zmq.
        auto scalarParam = std::make_shared<com::ScalarParam>();
        scalarParam->tag = tag;
        scalarParam->scalar_value = scalarValue;
        scalarParam->global_step = globalStep;
        com::Request<com::ScalarParam> addScalarRequest("add_scalar", scalarParam);

        // Outbound message
        tensorboardWriter.send_request(addScalarRequest);

        // Request status
        return tensorboardWriter.get_response<com::LogResponse>()->success;
    }

    bool SummaryWriter::addImage(std::string tag, const std::vector<std::vector<float>>& imageTensor, double globalStep) {
        // Talk to tensorboard server code python though zmq.
        auto imageParam = std::make_shared<com::ImageParam>();
        imageParam->tag = tag;
        imageParam->img_tensor = imageTensor;
        imageParam->global_step = globalStep;
        com::Request<com::ImageParam> addImageRequest("add_image", imageParam);

        // Outbound message
        tensorboardWriter.send_request(addImageRequest);

        // Request status
        return tensorboardWriter.get_response<com::LogResponse>()->success;
    }

} // namespace learn 
