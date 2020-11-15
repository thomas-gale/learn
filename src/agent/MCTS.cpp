#include "learn/agent/MCTS.hpp"

namespace learn {
namespace agent {

MCTS::Node::Node(float prior) : prior_(prior) {
    // Do something with torch to make sure the compiler is knowing that we are wanting to use it.
}; 

} // namespace agent
} // namespace learn
