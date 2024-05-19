#pragma once

extern Lumen::Application* Lumen::CreateApplication();

int main(int argc, char ** argv)
{
	auto app = Lumen::CreateApplication();
	app->Run();

	delete app;
	app = nullptr;

	return 0;
	
}