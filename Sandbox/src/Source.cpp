#include "Lumen.h"

class ExampleLayer : public Lumen::Layer
{
private:
	
public:
	ExampleLayer() = default;
	~ExampleLayer() = default;

	void OnAttach() {};
	void OnDetach() {};
	void OnUpdate() {};
	void OnEvent(const Lumen::Event& ev)
	{
		LUMEN_TRACE(ev.ToString());
	}
};

class Sandbox : public Lumen::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer);
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