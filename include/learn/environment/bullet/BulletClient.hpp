#ifndef LEARN_ENV_BULLETCLIENT_H_
#define LEARN_ENV_BULLETCLIENT_H_

#include "learn/environment/gym/Client.hpp"
#include "learn/environment/gym/Environment.hpp"

namespace learn {
namespace environment {
namespace bullet {

class BulletClient : public gym::Client {
  public:
    std::shared_ptr<gym::Environment> make(const std::string& name) override;
};

} // namespace bullet
} // namespace environment
} // namespace learn

#endif // LEARN_ENV_BULLETCLIENT_H_