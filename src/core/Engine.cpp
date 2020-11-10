#include "Core/Engine.hpp"
#include <iostream>

using namespace Core;

Engine* Core::Engine::s_Instance = nullptr;

Engine* Engine::GetInstance() 
{ 
	return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();	
}

Engine::Engine()
{

}

bool Engine::Init()
{
	m_IsRunning = true;
	return true;
}

bool Engine::Clean()
{
	return false;
}

void Engine::Quit()
{
	
}

void Engine::Update(float deltaTime)
{
	std::cout << "updating..." << std::endl;
}

void Engine::Render()
{

}

void Engine::Events()
{

}