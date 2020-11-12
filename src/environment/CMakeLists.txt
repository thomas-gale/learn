find_package(Corrade REQUIRED)
find_package(Magnum REQUIRED 
    GL
    MeshTools
    ObjImporter
    Sdl2Application
    Shaders
    SceneGraph
    Trade
)
find_package(MagnumIntegration REQUIRED
    Bullet
)
find_package(MagnumPlugins REQUIRED
    TinyGltfImporter
)
find_package(Bullet REQUIRED)

set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

add_executable(bullet_example
BulletExample.cpp)

target_link_libraries(bullet_example PRIVATE 
    Corrade::Main
    Magnum::Application
    Magnum::GL
    Magnum::Magnum
    Magnum::MeshTools
    Magnum::ObjImporter
    Magnum::Primitives
    Magnum::SceneGraph
    Magnum::Shaders
    Magnum::Trade
    MagnumIntegration::Bullet
    Bullet::Dynamics
    MagnumPlugins::TinyGltfImporter
)

