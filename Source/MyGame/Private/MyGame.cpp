// Copyright (c) Eric Jeker 2025.

#include "MyGame.h"

#include "Events/NavigateToMainMenu.h"
#include "Events/StartGame.h"
#include "GameStates/GameController.h"
#include "GameStates/MainMenu/MainMenuState.h"
#include "Logger.h"
#include "Managers/AudioManager.h"
#include "Managers/ResourceManager.h"

void MyGame::Initialize()
{
    LOG_DEBUG("(MyGame::Initialization): Load Resources");
    GameService::Get<ResourceManager>().LoadResourcesFromManifest("Assets/Manifest.json");
    LOG_DEBUG("(MyGame::Initialization): Load the Main Menu State");
    GameService::Get<GameController>().ChangeState(std::make_unique<MainMenuState>());

    // --- Start the main theme ---
    // GameService::Get<AudioManager>().PlayMusic("8mm");

    // --- Add event listeners ---
    GameService::Get<EventManager>().Subscribe<ExitGame>(_exitGameListener);
    GameService::Get<EventManager>().Subscribe<StartGame>(_startGameListener);
    GameService::Get<EventManager>().Subscribe<NavigateToMainMenu>(_returnToMainMenuListener);
}

void MyGame::Shutdown()
{
    LOG_DEBUG("(MyGame::Shutdown)");
    GameService::Get<AudioManager>().StopMusic();
}
