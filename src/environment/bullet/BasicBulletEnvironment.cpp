#include <Corrade/Containers/GrowableArray.h>
#include <Corrade/Containers/Optional.h>
#include <Corrade/Containers/Pointer.h>
#include <Magnum/BulletIntegration/DebugDraw.h>
#include <Magnum/BulletIntegration/Integration.h>
#include <Magnum/BulletIntegration/MotionState.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Math/Constants.h>
#include <Magnum/MeshTools/Compile.h>
#include <Magnum/MeshTools/Transform.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/Primitives/Cube.h>
#include <Magnum/Primitives/UVSphere.h>
#include <Magnum/SceneGraph/Camera.h>
#include <Magnum/SceneGraph/Drawable.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>
#include <Magnum/SceneGraph/Scene.h>
#include <Magnum/Shaders/Phong.h>
#include <Magnum/Timeline.h>
#include <Magnum/Trade/MeshData.h>
#include <btBulletDynamicsCommon.h>

#include "learn/environment/bullet/BasicBulletEnvironment.hpp"
#include "learn/environment/gym/State.hpp"

namespace learn {
namespace environment {
namespace bullet {

BasicBulletEnvironment::BasicBulletEnvironment() {
    actionSpace_ = std::make_shared<gym::Space>(
        gym::Space::SpaceType::BOX, std::vector<int>{2},
        std::vector<float>{1.0, 1.0}, std::vector<float>{-1.0, -1.0}, -1);
    observationSpace_ = std::make_shared<gym::Space>(
        gym::Space::SpaceType::BOX, std::vector<int>{2},
        std::vector<float>{std::numeric_limits<float>::max(),
                           std::numeric_limits<float>::max()},
        std::vector<float>{std::numeric_limits<float>::min(),
                           std::numeric_limits<float>::min()},
        -1);
    state_ = reset();
}

std::shared_ptr<gym::Space> BasicBulletEnvironment::actionSpace() const {
    return actionSpace_;
}

std::shared_ptr<gym::Space> BasicBulletEnvironment::observationSpace() const {
    return observationSpace_;
}

std::shared_ptr<gym::State> BasicBulletEnvironment::reset() {
    // Running reset...

    // Get the state from bullet
    // Bullet reset things
    float cubeX = 0;
    float cubeY = 0;

    // Target is middle (reward -ve mag of distance)
    float reward = -1.0f * (std::abs(2.5f - cubeX) + std::abs(2.5f - cubeY));

    // Update internal state to new.
    state_ = std::make_unique<gym::State>(std::vector<float>{cubeX, cubeY},
                                          reward, false, "Reset");

    // Return a copy to the smart pointer for optional consumption by clients.
    return state_;
}

std::shared_ptr<gym::State>
BasicBulletEnvironment::step(const std::vector<float>& action, bool render) {
    // Running step...

    // Mutate state_

    return state_;
}

void BasicBulletEnvironment::monitorStart(const std::string& directory,
                                          bool force, bool resume) {
    // Start monitor
    // We can use the Tensorboard implementation?
}

void BasicBulletEnvironment::monitorStop() {
    // Stop montor
    // We can use the Tensorboard implementation?
}

} // namespace bullet
} // namespace environment
} // namespace learn
