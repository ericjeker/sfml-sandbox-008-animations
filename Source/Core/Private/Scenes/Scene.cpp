// Copyright (c) Eric Jeker 2025.

#ifdef TRACY_ENABLE
#include <tracy/Tracy.hpp>
#endif

#include "Logger.h"
#include "Managers/GameService.h"
#include "Scenes/Scene.h"


void Scene::Initialize()
{
    LOG_DEBUG("(Scene:Initialize): Create a the root entity");
    _rootEntity = flecs::entity(_world);
}

void Scene::Shutdown()
{
    LOG_DEBUG("(Scene:Shutdown): Delete children of root entity");
    if (_rootEntity == flecs::entity::null())
    {
        return;
    }

    _world.delete_with(flecs::ChildOf, _rootEntity);
}

void Scene::Update(const float deltaTime)
{
    // Progress of the world by one tick.
    GetWorld().progress(deltaTime);
}

void Scene::HandleEvent(const std::optional<sf::Event>& event)
{
}

bool Scene::IsLoaded() const
{
    return _isLoaded;
}

void Scene::SetLoaded(const bool loaded)
{
    _isLoaded = loaded;
}

bool Scene::IsPaused() const
{
    return _isPaused;
}

void Scene::Pause()
{
    _isPaused = true;
    _world.entity(flecs::OnUpdate).disable();
}

void Scene::Resume()
{
    _isPaused = false;
    _world.entity(flecs::OnUpdate).enable();
}

const std::string& Scene::GetName() const
{
    return _name;
}

const std::string& Scene::GetPath() const
{
    return _path;
}

void Scene::SetName(const std::string& name)
{
    _name = name;
}

void Scene::SetPath(const std::string& path)
{
    _path = path;
}

flecs::world& Scene::GetWorld()
{
    return _world;
}

const flecs::world& Scene::GetWorld() const
{
    return _world;
}
