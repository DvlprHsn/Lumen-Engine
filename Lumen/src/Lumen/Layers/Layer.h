#pragma once

#include "Lumen/Defines.h"
#include "Lumen/Event/Event.h"

namespace Lumen
{
	class LUMEN_API Layer
	{
	private:
		std::string m_name{};

	public:
		Layer(const std::string& name = "Layer")
			:m_name(name) {};
		virtual ~Layer() = default;

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnEvent(const Event& ev) = 0;

		std::string GetName() { return m_name; }
	};
}

