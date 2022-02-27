#include "nkpch.h"

#include "Layer.h"

namespace nk
{
	Layer::Layer(std::basic_string<char> debugName)
		: m_DebugName(std::move(debugName)) {}

	Layer::~Layer() = default;
}
