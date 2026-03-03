#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#if _DEBUG && __has_include(<vld.h>)
#include <vld.h>
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"

// Components
#include "TextComponent.h"
#include "RenderComponent.h"
#include "FPSComponent.h"

#include "Scene.h"

#include <filesystem>
namespace fs = std::filesystem;

static void load()
{
	// scenes
	auto& scene = dae::SceneManager::GetInstance().CreateScene();

	// Fonts
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	// Background
	auto go = std::make_unique<dae::GameObject>();
	go->AddComponent<dae::RenderComponent>(go.get())->SetTexture("background.png");
	scene.Add(std::move(go));

	// Logo
	go = std::make_unique<dae::GameObject>();
	go->AddComponent<dae::RenderComponent>(go.get())->SetTexture("logo.png");
	go->SetPosition(358, 180);
	scene.Add(std::move(go));

	// Title
	go = std::make_unique<dae::GameObject>();
	go->SetPosition(292, 20);
	go->AddComponent<dae::TextComponent>(go.get())->SetText("Programming 4 Assignment", font, { 255,255,255,255 });
	scene.Add(std::move(go));

	// FPS Counter
	auto FPSCounter = std::make_unique<dae::GameObject>();
	FPSCounter->SetPosition(20, 20);
	FPSCounter->AddComponent<dae::TextComponent>(FPSCounter.get())->SetText("FPS: ", font, { 255,255,255,255 });
	FPSCounter->AddComponent<dae::FPSComponent>(FPSCounter.get())->SetTextComponent(FPSCounter->GetComponent<dae::TextComponent>());
	scene.Add(std::move(FPSCounter));
	






	
}

int main(int, char*[]) {
#if __EMSCRIPTEN__
	fs::path data_location = "";
#else
	fs::path data_location = "./Data/";
	if(!fs::exists(data_location))
		data_location = "../Data/";
#endif
	dae::Minigin engine(data_location);
	engine.Run(load);
    return 0;
}
