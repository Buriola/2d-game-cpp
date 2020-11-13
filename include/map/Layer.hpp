#pragma once

namespace Maps
{
	class Layer
	{
	public:
		virtual void Render() = 0;
		virtual void Update() = 0;
	};
}