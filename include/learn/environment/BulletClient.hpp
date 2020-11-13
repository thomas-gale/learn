#ifndef LEARN_ENV_BULLETCLIENT_H_
#define LEARN_ENV_BULLETCLIENT_H_

#include "learn/environment/Gym.hpp"

namespace learn {
namespace environment {

class BulletClient : public Client {
  public:
    std::shared_ptr<Environment> make(const std::string& name) override;
};

} // namespace environment
} // namespace learn

#endif // LEARN_ENV_BULLETCLIENT_H_