#include "learn/environment/Bullet.hpp"

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

namespace learn {
namespace environment {

std::shared_ptr<Space> BulletEnvironment::action_space() {
    return std::shared_ptr<Space>{};
}

std::shared_ptr<Space> BulletEnvironment::observation_space() {
    return std::shared_ptr<Space>{};
}

void BulletEnvironment::reset(State* save_initial_state_here) {
    // Running reset.
}

void BulletEnvironment::step(const std::vector<float>& action, bool render,
                             State* save_state_here) {
    // Running step.
}

void BulletEnvironment::monitor_start(const std::string& directory, bool force,
                                      bool resume) {
    // Start monitor
}

void BulletEnvironment::monitor_stop() {
    // Stop montor
}

} // namespace environment
} // namespace learn
