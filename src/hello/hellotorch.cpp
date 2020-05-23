#include <torch/torch.h>
#include <iostream>

namespace Learn {
  void hellotorch() {
    torch::Tensor tensor = torch::rand({2, 3});
    std::cout << tensor << std::endl;
  }
}