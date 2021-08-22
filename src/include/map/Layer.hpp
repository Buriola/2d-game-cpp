#ifndef GAME_LAYER_HPP
#define GAME_LAYER_HPP

namespace maps
{
	class Layer
	{
	public:
		virtual void Render() = 0;
		virtual void Update() = 0;
	};
}
#endif //GAME_LAYER_HPP