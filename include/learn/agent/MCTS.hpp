#ifndef LEARN_MCTS_H_
#define LEARN_MCTS_H_

#include <memory>
#include <vector>

#include "learn/environment/Gym.hpp"
#include "learn/agent/MuZeroNetwork.hpp"

namespace learn {
namespace agent {

class MCTS {
  class Node;
  class MinMaxStats;
  struct Config;

  public:
    

    MCTS(Config config);

    // Perform N game simulations, starting at the root node.
    // traversing using UCB, until a leaf node is found.
    Node run(
      std::shared_ptr<Network> model,
      environment::Environment env,
      const std::vector<environment::Action> actions,
      bool add_noise
    );

  private:
    // gets the child with the highest UBC store
    std::pair<environment::Action,  Node> selectChild(Node node, MinMaxStats stats);

    // evaluate UCB store Q value estimate, prior and visit count
    double getUCBScore(Node parent, Node child, MinMaxStats stats);

    // prop through the tree, updating value sums and visit counts
    void backpropagate(std::vector<Node> search_path, MinMaxStats);


  class Node {
      public:

        // Create a node from the prior of the action taken to get there
        Node(float prior);

        // Expand a previously unsearched node. 
        void expand(const std::vector<environment::Action> actions, 
                    const environment::State state);

        // add dirchlet noise to node values to encourage exploration.
        void addExplorationNoise(float dirichletAlpha, float explorationFraction);

      private:
        float count_;
        float prior_;
        float valueSum_;
        std::vector<std::shared_ptr<Node>> children;
        environment::State state;
        bool isExpanded();
        double getValue();
    };

  };
}; // namespace agent
}; // namespace learn

#endif
