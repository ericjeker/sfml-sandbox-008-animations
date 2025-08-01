// Copyright (c) Eric Jeker 2025.

#include "Modules/Render/Prefabs/Sprite.h"

#include "Managers/GameService.h"
#include "Managers/ResourceManager.h"
#include "Modules/Render/Components/SpriteRenderable.h"
#include "Modules/Render/Components/Transform.h"
#include "Modules/Render/Components/ZOrder.h"


namespace Prefabs
{

flecs::entity Sprite::Create(const flecs::world& world, const SpriteParams& params)
{
    const auto texture = GameService::Get<ResourceManager>().GetResource<sf::Texture>(params.textureAsset);
    if (!texture)
    {
        return flecs::entity::null();
    }

    auto sprite = std::make_unique<sf::Sprite>(*texture);
    const auto size = texture->getSize();
    sprite->setOrigin({size.x * params.origin.x, size.y * params.origin.y});

    const auto entity = world.entity()
                            .set<Transform>({.position = params.position, .scale = params.scale, .rotation = params.rotation})
                            .set<ZOrder>({params.zOrder})
                            .set<SpriteRenderable>({std::move(sprite)});

    return entity;
}


} // namespace Prefabs
