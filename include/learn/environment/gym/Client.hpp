#ifndef LEARN_ENV_GYM_CLIENT_H_
#define LEARN_ENV_GYM_CLIENT_H_

#include <memory>
#include <vector>

#include "learn/environment/gym/Environment.hpp"

namespace learn {
namespace environment {
namespace gym {

class Client {
  public:
    virtual std::shared_ptr<Environment> make(const std::string& name) = 0;
};

} // namespace gym
} // namespace environment
} // namespace learn

#endif // LEARN_ENV_GYM_CLIENT_H__
