// Copyright (c) Eric Jeker. All Rights Reserved.
#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>

namespace Configuration
{

constexpr auto WINDOW_TITLE = "Game Engine Using Flecs ECS";
constexpr sf::Vector2u WINDOW_SIZE = {1920, 1080};
constexpr auto WINDOW_STYLE = sf::Style::Close;
constexpr auto WINDOW_STATE = sf::State::Windowed;
constexpr bool IS_FULL_SCREEN = false;

constexpr unsigned int FRAMES_PER_SECOND = 60;
constexpr bool IS_VSYNC = true;
constexpr unsigned int ANTI_ALIASING_LEVEL = 4;

constexpr bool ENABLE_KEY_REPEAT = false;


} // namespace Configuration
