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

# -- Library Environment -- 

add_library(learn_environment
bullet/BulletEnvironment.cpp
bullet/BulletClient.cpp)

target_include_directories(learn_environment PUBLIC
"${Learn_SOURCE_DIR}/include")

target_link_libraries(learn_environment PRIVATE 
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
    MagnumPlugins::TinyGltfImporter)

# -- Executable Environment --

add_executable(bullet_example
bullet/BulletExample.cpp)

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
    MagnumPlugins::TinyGltfImporter)
