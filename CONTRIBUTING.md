# Dev Notes
## Things you need
- Linux
- Docker (version 19.03+)
- Beefy Nvidia GPU (driver version 440+) *(CUDA / Cudnn should all be handled inside dev container thanks to [nvidia-docker](https://github.com/NVIDIA/nvidia-docker))*
- [VSCode](https://code.visualstudio.com/) with [dev containers](https://code.visualstudio.com/docs/remote/containers) extension.

## Build
- Open repository VSCode and re-open in devcontainer (may take some time to build on first time)
- ```bash
mkdir build && cd build
cmake ..
make -j4
```
