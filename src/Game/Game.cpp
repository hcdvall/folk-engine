#include "Game.h"
#include "../Logger/Logger.h"
#include "../ECS/ECS.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

Game::Game() 
{
    isRunning = false;
    Logger::Log("Game constructor called!");
}

Game::~Game() 
{
    Logger::Log("Game destructor called!");
}

void Game::Initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Logger::Error("Error initializing SDL.");
        return;
    };

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    windowWidth = displayMode.w;
    windowHeight = displayMode.h;
    window = SDL_CreateWindow(
        "FOLKE", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        windowWidth, 
        windowHeight,
        SDL_WINDOW_BORDERLESS
    );

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    if (!window)
    {
        Logger::Error("Error creating SDL window.");
        return;
    }

    renderer = SDL_CreateRenderer(
        window, 
        -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    
    if (!renderer)
    {
        Logger::Error("Error creating SDL renderer.");
        return;
    }

    isRunning = true;

}

void Game::ProcessInput()
{
    SDL_Event sdlEvent;
    while(SDL_PollEvent(&sdlEvent))
    {
        switch (sdlEvent.type)
        {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
                {
                    isRunning = false;
                }
                break;
        }
    }
}

void Game::Setup()
{
    // TODO: 
    // Entity tank = registry.CreateEntity();
    // tank.AddComponent<TransformComponent>();
    // ...
    
}

// 
void Game::Update()
{
    int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks64() - millisecsPreviousFrame);
    if (timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME)
    {
        SDL_Delay(timeToWait);
    }

    double deltaTime = (SDL_GetTicks64() - millisecsPreviousFrame) / 1000.0;
    
    millisecsPreviousFrame = SDL_GetTicks64();

    // TODO: Update systems
}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 40, 30, 20, 255);
    SDL_RenderClear(renderer);

    // TODO: Render game objects...

    SDL_RenderPresent(renderer);
}

void Game::Run()
{
    Setup();
    while (isRunning)
    {
        ProcessInput();
        Update();
        Render();
    }   
}

void Game::Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}