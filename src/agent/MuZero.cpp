#include "learn/agent/MuZero.hpp"
#include <torch/torch.h>

namespace learn {
namespace agent {

// MuZero C'tor - inject the environment.
MuZero::MuZero(std::shared_ptr<environment::Environment> env) : env_(env){
    // Do something with torch to make sure the compiler is knowing that we are wanting to use it.
    torch::Tensor tensor = torch::rand({2, 3});
};

} // namespace agent
} // namespace learn
