#include <Siv3D.hpp>
#include "SceneManager.h"

void Main()
{
	Window::Resize(1280, 720);

	SceneManager scene_manager;
	scene_manager.Initialize();

	while (System::Update())
	{
		scene_manager.Update();
		scene_manager.Draw();
	}

	scene_manager.Finalize();
}
