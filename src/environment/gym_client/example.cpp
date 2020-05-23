#include "learn/example.h"

#include <string.h>
#include <chrono>
#include <fstream>

#include <spdlog/spdlog.h> 
#include <spdlog/sinks/basic_file_sink.h>
#include <ATen/Parallel.h>

#include "torch/torch.h"

//#include <cpprl/cpprl.h>
//#include 

#include "communicator.h"
#include "requests.h"

using namespace gym_client;
//using namespace cpprl;

namespace learn {

// Algorithm hyperparameters
/*const std::string algorithm = "PPO";
const float actor_loss_coef = 1.0;
const int batch_size = 40;
const float clip_param = 0.2;
const float discount_factor = 0.99;
const float entropy_coef = 1e-3;
const float gae = 0.9;
const float kl_target = 0.5;
const float learning_rate = 1e-3;
const int log_interval = 10;
const int max_frames = 10e+7;
const int num_epoch = 3;
const int num_mini_batch = 20;
const int reward_average_window_size = 10;
const float reward_clip_value = 100; // Post scaling
const bool use_gae = true;
const bool use_lr_decay = false;
const float value_loss_coef = 0.5;*/

// Environment hyperparameters
const std::string env_name = "LunarLander-v2";
const int num_envs = 1;
//const float render_reward_threshold = 160;

// Model hyperparameters
//const int hidden_size = 64;
//const bool recurrent = false;
const bool use_cuda = false;

std::vector<float> flatten_vector(std::vector<float> const &input)
{
    return input;
}

template <typename T>
std::vector<float> flatten_vector(std::vector<std::vector<T>> const &input)
{
    std::vector<float> output;

    for (auto const &element : input)
    {
        auto sub_vector = flatten_vector(element);

        output.reserve(output.size() + sub_vector.size());
        output.insert(output.end(), sub_vector.cbegin(), sub_vector.cend());
    }

    return output;
}

void example()
{
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("%^[%T %7l] %v%$");

    at::set_num_threads(1);
    torch::manual_seed(0);

    torch::Device device = use_cuda ? torch::kCUDA : torch::kCPU;

    spdlog::info("Connecting to gym server");
    Communicator communicator("tcp://127.0.0.1:10201");

    spdlog::info("Creating environment");
    auto make_param = std::make_shared<MakeParam>();
    make_param->env_name = env_name;
    make_param->num_envs = num_envs;
    Request<MakeParam> make_request("make", make_param);
    communicator.send_request(make_request);
    spdlog::info(communicator.get_response<MakeResponse>()->result);

    Request<InfoParam> info_request("info", std::make_shared<InfoParam>());
    communicator.send_request(info_request);
    auto env_info = communicator.get_response<InfoResponse>();
    spdlog::info("Action space: {} - [{}]", env_info->action_space_type,
                env_info->action_space_shape);
    spdlog::info("Observation space: {} - [{}]", env_info->observation_space_type,
                env_info->observation_space_shape);

    spdlog::info("Resetting environment");
    auto reset_param = std::make_shared<ResetParam>();
    Request<ResetParam> reset_request("reset", reset_param);
    communicator.send_request(reset_request);

    // Observation stuff.
    auto observation_shape = env_info->observation_space_shape;
    observation_shape.insert(observation_shape.begin(), num_envs);
    torch::Tensor observation;
    std::vector<float> observation_vec;
    if (env_info->observation_space_shape.size() > 1)
    {
        observation_vec = flatten_vector(communicator.get_response<CnnResetResponse>()->observation);
        observation = torch::from_blob(observation_vec.data(), observation_shape).to(device);
    }
    else
    {
        observation_vec = flatten_vector(communicator.get_response<MlpResetResponse>()->observation);
        observation = torch::from_blob(observation_vec.data(), observation_shape).to(device);
    }

    // Action stuff.
    std::vector<std::vector<float>> actions(num_envs);
    // Discrete  Nop, fire left engine, main engine, right engine
    actions.at(0) = std::vector<float>{1.0, 0.0, 0.0, 0.0};

    auto step_param = std::make_shared<StepParam>();
    for (auto i = 0; i < 10; ++i) {
        step_param->render = true;
        step_param->actions = actions;
        Request<StepParam> step_request("step", step_param);
        communicator.send_request(step_request);
    }
}

} // namespace learn 