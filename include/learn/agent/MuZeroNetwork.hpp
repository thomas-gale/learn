#ifndef LEARN_AGENT_MUZERONETWORK_H_
#define LEARN_AGENT_MUZERONETWORK_H_

#include <memory>
#include <torch/torch.h>

#include "learn/environment/Gym.hpp"

namespace learn {
namespace agent {

// Abstract Torch Network.
class Network : public torch::nn::Module {
  public:
    Network();

    // Not sure what this is for right now...!
    virtual at::Tensor initialInference(const at::Tensor& observation) = 0;

    // Also not sure what this is for..!
    virtual at::Tensor recurrentInference(const at::Tensor& encodedState,
                                          const at::Tensor& action) = 0;

    // Return the state weights from GPU -> CPU.
    std::vector<float> getWeights();
};

// Fully connected concrete network implementation.
class MuZeroFullyConnectedNetwork : public Network {
  public:
    MuZeroFullyConnectedNetwork(c10::ArrayRef<double> observationShape);
};

} // namespace agent
} // namespace learn

#endif LEARN_AGENT_MUZERONETWORK_H_