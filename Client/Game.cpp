#include "pch.h"
#include "Game.h"
#include "Engine.h"

void Game::Initialize(WindowInfo info)
{
	GEngine->Init(info);
}

void Game::Update()
{
}

void Game::Render()
{
	GEngine->Render();
}
