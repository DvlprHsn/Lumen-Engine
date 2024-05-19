#include "Lumen.h"
class Sandbox : public Lumen::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox() 
	{

	}

private:

};

Lumen::Application* Lumen::CreateApplication()
{
	return new Sandbox;
}