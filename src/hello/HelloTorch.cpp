#include "learn/HelloTorch.hpp"

#include <exception>
#include <iostream>
#include <torch/torch.h>

namespace learn {

void hellotorch() {
    torch::Tensor tensor = torch::rand({2, 3});
    std::cout << tensor << std::endl;
}

void hellotorchgpu() {
    bool cudaAvail = torch::cuda::is_available();
    if (!cudaAvail)
        throw std::runtime_error("No GPU :(");

    torch::Tensor tensor = torch::rand({2, 3});
    torch::Device dev("cuda:0");
    torch::Tensor gpuTensor = tensor.to(dev);
    std::cout << gpuTensor << std::endl;
}

} // namespace learn
