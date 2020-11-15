#include <exception>
#include <memory>

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
#include "learn/environment/bullet/BulletClient.hpp"
#include "learn/environment/gym/Environment.hpp"

namespace learn {
namespace environment {
namespace bullet {

std::shared_ptr<gym::Environment> BulletClient::make(const std::string& name) {
    // Right now we will only support some simple cube/primitive worlds
    if (name == "basic") {
        return std::make_shared<BasicBulletEnvironment>();
    } else {
        throw new std::runtime_error("Unrecognised bullet environment name");
    }
}

} // namespace bullet
} // namespace environment
} // namespace learn
