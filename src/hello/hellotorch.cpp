#include <iostream>
#include <torch/torch.h>

namespace learn {
void hellotorch() {
    torch::Tensor tensor = torch::rand({2, 3});
    std::cout << tensor << std::endl;
}
} // namespace learn