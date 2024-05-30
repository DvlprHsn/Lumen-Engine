#pragma once

extern Lumen::Application* Lumen::CreateApplication();

int main(int argc, char ** argv)
{
	auto app = Lumen::CreateApplication();
	LUMEN_INFO("Welcome To Lumen {0}.{1}.{2}", LUMEN_VERSION_MAJOR, LUMEN_VERSION_MINOR, LUMEN_VERSION_PATCH);

	app->Run();

	delete app;
	app = nullptr;

	return 0;
}