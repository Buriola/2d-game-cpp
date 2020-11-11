#include "graphics/TextureManager.hpp"

Graphics::TextureManager* Graphics::TextureManager::s_Instance = nullptr;

Graphics::TextureManager* Graphics::TextureManager::GetInstance() 
{ 
	return s_Instance = (s_Instance != nullptr) ? s_Instance : new TextureManager(); 
}

bool Graphics::TextureManager::Load(std::string id, std::string filename) 
{
	SDL_Surface* surface = IMG_Load(filename.c_str());
	if(surface == nullptr)
	{
		std::cout << "Failed to create surface: " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Core::Engine::GetInstance()->GetRenderer(), surface);
	if(texture == nullptr)
	{
		std::cout << "Failed to load texture into surface: " << SDL_GetError() << std::endl;
		return false;
	}

	m_TextureMap[id] = texture;
	return true;
}

void Graphics::TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect sourceRect = {0, 0, width, height};
	SDL_Rect destinationRect = {x, y, width, height};

	SDL_RenderCopyEx(Core::Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &sourceRect, &destinationRect, 0, nullptr, flip);
}

void Graphics::TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
	SDL_Rect sourceRect = {width * frame, height * row, width, height };
	SDL_Rect destinationRect = {x, y, width, height};

	SDL_RenderCopyEx(Core::Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &sourceRect, &destinationRect, 0, nullptr, flip);
}

void Graphics::TextureManager::Drop(std::string id)
{
	SDL_DestroyTexture(m_TextureMap[id]);
	m_TextureMap.erase(id);
}

void Graphics::TextureManager::Clean()
{
	std::map<std::string, SDL_Texture*>::iterator it;
	for(it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
	{
		SDL_DestroyTexture(it->second);
	}

	m_TextureMap.clear();

	std::cout << "Texture map cleaned!" << std::endl;
}