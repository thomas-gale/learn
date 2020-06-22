# learn
A personal, experimental dive learning how to build C++ based machine learning systems.

## Motivation
- I ultimately want to explore the use of deep reinforcement learning to democratise the manufacturing domain
- I'm fascinated by the work of Deepmind / David Silver (loved his [UCL lecture series](https://www.davidsilver.uk/teaching/))
- I'm enjoying reading *Reinforcement Learning: An Introduction: Sutton, Barto (2018)*
- I'm enjoying reading *Deep Reinforcement Learning Hands-On: Maxim Lapan (2018)*
- I think that https://gym.openai.com/ is cool
- I like [bullet](https://github.com/bulletphysics/bullet3) as a simulation environement, maybe even try [godot](https://github.com/godotengine/godot)?
- I learn by doing e.g. re-writing things from python -> C++
- PyTorch now has a [wonderful C++ API](https://pytorch.org/cppdocs/)
- I want my GPU to do something interesting
- I want to build the whole thing as a container native / ready to scale

## Attribution
- https://github.com/Omegastick/pytorch-cpp-rl (such as linking to torch C++ <-> openai gym with ZMQ)
- https://github.com/Shmuma/ptan / https://github.com/PacktPublishing/Deep-Reinforcement-Learning-Hands-On 
- https://github.com/lupoglaz/GodotGymAI

## Plan
- Build Godot gym module https://github.com/thomas-gale/godot-gym-cpp
- Attempt to roughly follow exercises in [Deep Reinforcement Learning Hands-On: Maxim Lapan (2018)](https://github.com/PacktPublishing/Deep-Reinforcement-Learning-Hands-On) but using godot game approximations and rewritten in C++
- Possibily give learn library similar structure to [ptan](https://github.com/Shmuma/ptan)?
- Finally, do something cool (maybe with [b2a](https://github.com/thomas-gale/bits-to-atoms) - build in a learning agent into the service providers of the virtual factory marketplace with the reward function set to maximise profit...)

## Architecture Notes
![learn-library-structure](https://user-images.githubusercontent.com/11990706/85264505-b08f4800-b468-11ea-8365-7c050780c4fa.png)
