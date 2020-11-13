#include "learn/agent/MuZero.hpp"

namespace learn {
namespace agent {

// MuZero C'tor - inject the environment.
MuZero::MuZero(std::shared_ptr<environment::Environment> env) : env_(env){};

} // namespace agent
} // namespace learn
