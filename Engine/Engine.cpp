#include "pch.h"
#include "Engine.h"
#include "DXManager.h"
#include "BufferManager.h"
#include "Light.h"
#include "Material.h"

void Engine::Init(WindowInfo _info)
{
	mWinfo = _info;

	DXManager::GetInstance()->Init();
	BufferManager::GetInstance()->CreateConstantBuffer(CBV_REGISTER::b0, sizeof(LightParams));
	BufferManager::GetInstance()->CreateConstantBuffer(CBV_REGISTER::b1, sizeof(TransformParams));
	BufferManager::GetInstance()->CreateConstantBuffer(CBV_REGISTER::b2, sizeof(MaterialParams));




}

void Engine::Update()
{
	DXManager::GetInstance()->Update();
}

void Engine::Render()
{
	DXManager::GetInstance()->Render();
}

void Engine::CreateRenderTargetGroups()
{
}
