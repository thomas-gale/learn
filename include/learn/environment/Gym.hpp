#ifndef LEARN_ENV_GYM_H_
#define LEARN_ENV_GYM_H_

#include <memory>
#include <vector>

namespace learn {
namespace environment {

struct Space {
    enum SpaceType {
        DISCRETE,
        BOX,
    } type;

    std::vector<float> sample(); // Random vector that belong to this space

    std::vector<int> box_shape; // Similar to Caffe blob shape, for example
                                // { 64, 96, 3 } for 96x64 rgb image.
    std::vector<float> box_high;
    std::vector<float> box_low;

    int discreet_n;
};

struct State {
    std::vector<float>
        observation; // get observation_space() to make sense of this data
    float reward;
    bool done;
    std::string info;
};

// Action space representation
typedef std::vector<float>& Action;

class Environment {
  public:
    virtual std::shared_ptr<Space> action_space() = 0;
    virtual std::shared_ptr<Space> observation_space() = 0;

    virtual void reset(State* save_initial_state_here) = 0;

    virtual void step(const Action action, bool render,
                      State* save_state_here) = 0;

    virtual void monitor_start(const std::string& directory, bool force,
                               bool resume) = 0;
    virtual void monitor_stop() = 0;
};

class Client {
  public:
    virtual std::shared_ptr<Environment> make(const std::string& name) = 0;
};

extern std::shared_ptr<Client> client_create(const std::string& addr, int port);

} // namespace environment
} // namespace learn

#endif // LEARN_ENV_GYM_H__
