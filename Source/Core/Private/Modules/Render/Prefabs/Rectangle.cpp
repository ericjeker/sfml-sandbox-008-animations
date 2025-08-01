// Copyright (c) Eric Jeker 2025.

#include "Modules/Render/Prefabs/Rectangle.h"

#include "Modules/Render/Components/RectangleRenderable.h"
#include "Modules/Render/Components/Transform.h"
#include "Modules/Render/Components/ZOrder.h"

namespace Prefabs
{

flecs::entity Rectangle::Create(const flecs::world& world, const RectangleParams& params)
{
    sf::RectangleShape backgroundDrawable;
    backgroundDrawable.setSize(params.size);
    backgroundDrawable.setPosition(params.position);
    backgroundDrawable.setOrigin(params.size.componentWiseMul(params.origin));
    backgroundDrawable.setFillColor(params.color);

    const auto entity = world.entity()
                            .set<RectangleRenderable>({std::move(backgroundDrawable)})
                            .set<ZOrder>({params.zOrder})
                            .set<Transform>({.position = params.position, .scale = params.scale, .rotation = params.rotation});

    return entity;
}

} // namespace Prefabs
